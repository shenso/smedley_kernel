#include "hooks.hpp"
#include "loader.hpp"
#include "memory.hpp"
#include "util.hpp"
#include <cstdio>
#include <cstdio>
#include <filesystem>
#include <windows.h>
#include <direct.h>
#include <psapi.h>
#include <shlobj.h>

PLUGIN_API void LoadPlugins()
{
    smedley::PluginLoader::instance()->LoadPlugins();
}


namespace smedley
{

    // a PLUGIN_API export required by all smedley plugins. for most plugins this
    // should just be simple boilerplate allocating and instantiating the plugin
    // subclass.
    typedef Plugin *(*PluginCreator)();

    struct PluginModule
    {
        Plugin *(*CreatePlugin)();

        std::string (*PluginID)();
    };

    PluginLoader *PluginLoader::_instance = nullptr;

    void DumpLoadedModules(smedley::Logger &logger)
    {
        constexpr size_t hmods_size = 1024;
        constexpr size_t text_buf_size = 512;

        HMODULE hmods[hmods_size];
        HANDLE hproc;
        DWORD cb_needed;

        hproc = GetCurrentProcess();
        if (EnumProcessModules(hproc, hmods, sizeof(hmods), &cb_needed)) {
            for (uint32_t i = 0; i < (cb_needed / sizeof(HMODULE)); i++) {
                char mod_name[MAX_PATH];
                char text_buf[text_buf_size];

                if (GetModuleFileNameEx(hproc, hmods[i], mod_name,
                                        sizeof(mod_name) / sizeof(char))) {
                    std::snprintf(text_buf, text_buf_size, TEXT("%s (0x%08X)"), mod_name, reinterpret_cast<uint32_t>(hmods[i]));
                    logger.Info("module detected: " + std::string(text_buf));
                }
            }
        }
    }


    PluginLoader::PluginLoader() : _loaded(false)
    {
        wchar_t cwd_buf[MAX_PATH];
        wchar_t *documents_path_ws;

        // currently victoria 2 always assumes its launched within the game directory.
        // if it isn't it will crash failing to find some map file. we may want to
        // fix this in the future, but for now we can ride on this assumption.
        if (!_wgetcwd(cwd_buf, MAX_PATH)) {
            auto err_no = errno;
            throw std::runtime_error("failed to get current working directory: " + err_no);
        }

        // keep smedley logs near game logs
        if (SHGetKnownFolderPath(FOLDERID_Documents, 0, NULL, &documents_path_ws) == E_FAIL) {
            throw std::runtime_error("failed to find documents folder");
        }
        std::wstring tmp_ws(documents_path_ws);
        std::string documents_path(tmp_ws.begin(), tmp_ws.end());
        tmp_ws = std::wstring(cwd_buf);
        
        _gamedir = std::string(tmp_ws.begin(), tmp_ws.end());;
        _userdir = documents_path + "\\Paradox Interactive\\Victoria II";
        _plugindir = _gamedir + "\\plugins";
        _log_filepath = _userdir + "\\logs\\smedley.log";

        _logger = std::make_unique<FileLogger>(_log_filepath, "smedley");
        _logger->Info("initializing plugin loader...");
    }

    void PluginLoader::LoadPlugins()
    {
        // initialize the memory map before touching the text segment
        memory::Map::Init();
        // install hooks & patches
        InstallHooks();

        auto filenames = ParseCommandLine(GetCommandLineA());
        for (auto &filename : filenames) {
            _plugin_defs.push_back(PluginDefinition::Read(filename));
        }

        DumpLoadedModules(*_logger);
        for (auto &def : _plugin_defs) {
            auto fail = [&](const std::string &reason) {
                _logger->Critical("error loading plugin \"" + def.id + "\": " + reason);
                MessageBoxA(NULL, "Failed trying to load plugins!", "Smedley Fatal Error", MB_ICONERROR);
                ExitProcess(1000);
            };

            auto path = std::filesystem::absolute("plugins" / std::filesystem::path(def.module_name));
            auto path_str = path.native();
            HMODULE hmod = GetModuleHandleW(path_str.c_str());
            if (hmod == NULL || hmod == INVALID_HANDLE_VALUE) {
                fail("module \"" + std::string(path_str.begin(), path_str.end()) + "\" not found!");
            }

            auto creator = (PluginCreator) GetProcAddress(hmod, "CreatePlugin");
            if (creator == NULL) {
                fail("failed to locate address of CreatePlugin in module " + def.module_name + " (" + std::to_string(GetLastError()) + ")");
            }

            auto plugin = creator();
            plugin->_definition = def;
            plugin->_hmod = hmod;
            plugin->_logger = std::make_unique<FileLogger>(_log_filepath, def.id, true);
            _plugins.push_back(plugin);
            plugin->OnLoad();
        }
    }

    void PluginLoader::UnloadPlugins()
    {
        for (auto plugin : _plugins) {
            plugin->OnUnload();
        }

        _plugins.clear();
        _plugin_defs.clear();
    }

    std::vector<std::string> PluginLoader::ParseCommandLine(const std::string &cmdline)
    {
        const std::string prefix = "-plugin=";
        std::vector<std::string> targets;
        std::vector<std::string> argv;
        int argc;

        argv = SplitString(cmdline, ' ');
        argc = argv.size();
        for (int i = 1; i < argc; i++) {
            if (argv[i].rfind(prefix, 0) != 0) {
                continue;
            }

            targets.push_back(argv[i].substr(prefix.length()));
        }

        return targets;
    }

}