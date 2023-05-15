#include "plugin.hpp"
#include "kernel.hpp"
#include "functions/base.hpp"
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <libloaderapi.h>

typedef smedley::core::Plugin *(*PluginCreator)();
typedef const char *(*PluginNameProvider)();

PLUGIN_API void LoadPlugins(PluginListNode *root)
{
	PluginListNode *node = root;

	while (node != nullptr) {
		std::string modPath(node->name);

		HMODULE hMod = GetModuleHandleA(node->name);
		if (hMod == NULL || hMod == INVALID_HANDLE_VALUE) {
			std::string msg = "could not find module: " + modPath;
			MessageBox(NULL, msg.c_str(), "Plugin Load Failure", MB_ICONERROR);
			node = node->next;
			continue;
		}

		PluginCreator creator = (PluginCreator) GetProcAddress(hMod, "MakePlugin");
		PluginNameProvider nameProvider = (PluginNameProvider) GetProcAddress(hMod, "PluginName");

		const char *name = nameProvider();
		smedley::core::Plugin *plugin = creator();

		auto *kernel = smedley::core::Kernel::GetInstance();
		kernel->pluginLoader()->Load(plugin, name, modPath);

		node = node->next;
	}
}

namespace smedley
{
namespace core
{

PluginLoader::PluginLoader()
{
}

void PluginLoader::Load(Plugin *newPlugin, const std::string &name, const std::string &path)
{
	PluginMetadata metadata{};

	if (_plugins.find(name) != _plugins.end()) {
		throw std::runtime_error("plugin " + name + " is already loaded!");
	}

	metadata.name = name;
	metadata.path = path;
	newPlugin->_metadata = metadata;
	_plugins.insert(std::pair<std::string, Plugin *>(name, newPlugin));
	newPlugin->OnAttach();
}

Plugin::Plugin()
{
}

}
}