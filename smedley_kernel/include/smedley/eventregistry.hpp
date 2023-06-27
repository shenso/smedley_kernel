#pragma once

#include "event.hpp"
#include "macros.hpp"
#include <algorithm>
#include <cstdint>
#include <functional>
#include <limits>
#include <string>
#include <vector>

namespace smedley
{

    class Plugin;

    enum class EventHandlerPriority : uint32_t
    {
        LOWEST = 0,
        LOW = 1 << 10,
        NORMAL = 1 << 15,
        HIGH = 1 << 20,
        HIGHEST = std::numeric_limits<uint32_t>::max(),
    };

    /**
     * A static container for of all listeners of a given event.
     */
    template <class Ev>
    class EventRegistry
    {
    protected:
        struct Handler
        {
            Plugin *key_plugin;
            std::string key_str;
            std::function<void(Ev &)> fn;
            EventHandlerPriority priority;
        };
    public:
        using Handlers = std::vector<Handler>;
    protected:
        inline static struct
        {
            inline bool operator()(Handler a, Handler b) const { return a.priority < b.priority; }
        } _handler_compare_lt{};

        // should be defined for each event by template specialization
        SMEDLEY_API static Handlers _handlers;
    public:
        /**
         * Adds the given event handler to the registry.
         * 
         * @param plugin The registering plugin.
         * @param id The id of the event handler (namespaced within the plugin).
         * @param fn The event handler.
         * @param priority The priority on the handler queue on callback.
         */
        static void Register(Plugin *plugin, const std::string &id, std::function<void(Ev &)> fn, EventHandlerPriority priority = EventHandlerPriority::LOWEST)
        {
            auto handler_exists = [&plugin, &id](const Handler &h) { return h.key_plugin == plugin && h.key_str == id; };
            if (std::find_if(_handlers.begin(), _handlers.end(), handler_exists) == _handlers.end()) {
                Handler eh{plugin, id, fn, priority};
                _handlers.push_back(eh);
                std::sort(_handlers.begin(), _handlers.end(), _handler_compare_lt);
            }
        }

        /**
         * Removes the given event handler from the registry.
         * 
         * @param plugin The plugin which registered the handler.
         * @param id The id of the event handler.
         */
        static void Unregister(Plugin *plugin, const std::string &id)
        {
            auto handler_exists = [&fn](const Handler &h) { return h.key_plugin == plugin && h.key_str == id; };
            auto iter = std::find_if(_handlers.begin(), _handlers.end(), handler_exists);
            if (iter != _handlers.end()) {
                _handlers.erase(iter);
            }
        }

        /**
         * Notifies event handlers of the given event.
         */
        static void Notify(Ev &e)
        {
            for (auto iter = _handlers.begin(); iter != _handlers.end() && !e.is_cancelled(); iter++) {
                (*iter).fn(e);
            }
        }
    };

}