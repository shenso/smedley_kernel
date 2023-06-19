#pragma once

#include "log.hpp"
#include <memory>
#include <optional>
#include <string>
#include <vector>
#include <windows.h>

#define PLUGIN_API extern "C" __declspec(dllexport)

namespace smedley
{

	struct PluginDefinition
	{
		struct Version
		{
			std::string str;
			std::unique_ptr<int[]> versions;
			int num_versions;

			static Version Parse(const std::string &s);

			friend bool operator==(const Version &lhs, const Version &rhs);
			friend bool operator!=(const Version &lhs, const Version &rhs);
		};

		struct Dependency
		{
			std::string id;
			std::optional<Version> eq;
			std::optional<Version> gt;
			std::optional<Version> lt;
		};

		std::string id;
		std::string name;
		std::string description;
		std::string module_name;
		Version version;
		std::vector<Dependency> dependencies;

		PluginDefinition() {}
		PluginDefinition(const PluginDefinition &def) : id(def.id), name(def.name), description(def.description), module_name(def.module_name) {}

		void operator=(const PluginDefinition &def) { id = def.id; name = def.name; description = def.description; module_name = def.module_name; }

		static PluginDefinition Read(const std::string &filename);
	};

	class Plugin
	{
	private: // fields populated by the loader
		HMODULE _hmod;
		PluginDefinition _definition;
		uint32_t _checksum;

		std::unique_ptr<Logger> _logger;
	public:
		// plugin constructors should generally have little to no logic. various
		// object properties will NOT be available until they are provided by the 
		// plugin loader immediately AFTER instantiation.
		Plugin();
		virtual ~Plugin() {};

		virtual void OnLoad() {};
		virtual void OnUnload() {};

		const PluginDefinition &definition() const { return _definition; }
		uint32_t checksum() const { return _checksum; }
		HMODULE mod_handle() const { return _hmod; }

		friend class PluginLoader;
	protected:
		Logger &logger() const { return *_logger; }
	};

	

}