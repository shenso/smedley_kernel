#pragma once

#include "../event.hpp"
#include "../v2/console.hpp"

namespace smedley::events
{

    /**
     * When the player starts a new campaign the game initalizes the
     * console command manager so it is available to the console if the
     * player opens it. This event occurs when the command manager is 
     * initialized. At this point all the base game commands have been added
     * to the manager.
     */
    class ConsoleCmdManagerInitEvent : public Event
    {
        v2::CConsoleCmdManager *_cmd_mgr;
    public:
        ConsoleCmdManagerInitEvent(v2::CConsoleCmdManager *cmd_mgr);
        /// @brief returns the console command manager being initalized
        v2::CConsoleCmdManager *cmd_mgr() { return _cmd_mgr; }

        /// @brief installs the hook needed to trigger the event
        static void InstallHook();
    };

}