#pragma once

#include "eventregistry.hpp"
#include "log.hpp"
#include <memory>
#include <optional>
#include <string>
#include <vector>
#include <windows.h>

#define PLUGIN_API extern "C" __declspec(dllexport)

namespace smedley
{

    /**
     * Plugin metadata structure
     */
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

    /**
     * The basic interface for Smedley plugins. All smedley plugins MUST have
     * a Plugin subclass in their module. The Plugin base class provides a set of
     * helper methods and properties needed to provide basic functionality to a plugin,
     * as well as an interface for interaction with the PluginLoader.
     */
    class Plugin
    {
    private: // fields populated by the loader
        HMODULE _hmod;
        PluginDefinition _definition;
        uint32_t _checksum;

        std::unique_ptr<Logger> _logger;
    public:
        /// The plugin constructor MUST only contain initialization logic. Uses of
        /// object properties will lead to undefined behavior as they are initialized
        /// immediately after instantiation by the plugin loader.
        Plugin();
        virtual ~Plugin() {};

        /// @brief Called after the plugin is loaded by the plugin loader.
        virtual void OnLoad() {};
        /// @brief Called when the loader makes a request to unload.
        virtual void OnUnload() {};

        const PluginDefinition &definition() const noexcept { return _definition; }
        uint32_t checksum() const noexcept { return _checksum; }
        HMODULE mod_handle() const noexcept { return _hmod; }

        friend class PluginLoader;
    protected:
        /**
         * Helper function for registering plugin event handlers to an event registry.
         */
        template <class Ev>
        inline void AddEventHandler(const std::string &id, std::function<void(Ev &)> handler, EventHandlerPriority priority = EventHandlerPriority::LOWEST)
        {
            EventRegistry<Ev>::Register(this, id, handler, priority);
        }

        /**
         * Helper function for unregistering plugin event handlers
         */
        template <class Ev>
        inline void RemoveEventHandler(const std::string &id)
        {
            EventRegistry<Ev>::Unregister(this, id);
        }

        Logger &logger() const noexcept { return *_logger; }
    };

    

}