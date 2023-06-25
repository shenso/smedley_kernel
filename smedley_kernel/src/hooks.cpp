#include "hooks.hpp"
#include "events/console.hpp"

namespace smedley
{

    void InstallHooks()
    {
        using namespace events;

        // event hooks
        ConsoleCmdManagerInitEvent::InstallHook();
    }

}