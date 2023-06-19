#pragma once

#include "plugin.hpp"
#include <memory>
#include <string>
#include <vector>
#include <toml.hpp>

namespace smedley
{

	class PluginLoader
	{
	private:
		std::string _gamedir;
		std::string _userdir;
		std::string _plugindir;
		std::string _log_filepath;

		std::unique_ptr<Logger> _logger;

		bool _loaded;
		std::vector<PluginDefinition> _plugin_defs;
		std::vector<Plugin *> _plugins;

		static PluginLoader *_instance;
	public:
		PluginLoader();

		void LoadPlugins();
		void UnloadPlugins();

		static PluginLoader *instance()
		{
			if (_instance == nullptr) {
				_instance = new PluginLoader();
			}

			return _instance;
		}
	private:
		std::vector<std::string> ParseCommandLine(const std::string &cmdline);
		void LoadPluginModule();
	};

}