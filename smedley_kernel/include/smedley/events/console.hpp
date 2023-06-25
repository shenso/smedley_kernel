#pragma once

#include "../event.hpp"
#include "../v2/console.hpp"

namespace smedley::events
{

    class ConsoleCmdManagerInitEvent : public Event
    {
        v2::CConsoleCmdManager *_cmd_mgr;
    public:
        ConsoleCmdManagerInitEvent(v2::CConsoleCmdManager *cmd_mgr);
        v2::CConsoleCmdManager *cmd_mgr() { return _cmd_mgr; }

        static void InstallHook();
    };

}