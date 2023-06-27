#include "eventregistry.hpp"
#include "memory.hpp"
#include "events/console.hpp"

constexpr uintptr_t hook_addr = 0x00023a43;
uintptr_t hook_ret_addr = NULL;

using namespace smedley;

void ConsoleCmdManagerInitHook(v2::CConsoleCmdManager *mgr)
{
    smedley::EventRegistry<events::ConsoleCmdManagerInitEvent>::Notify(events::ConsoleCmdManagerInitEvent(mgr));
}

void __declspec(naked) HookTrampoline()
{
    __asm {
         // save the current register context
        push eax
        push ecx
        push edx
        push esi

        push esi
        call ConsoleCmdManagerInitHook
        pop esi

        // restore the context
        pop esi
        pop edx
        pop ecx
        pop eax

        // patched instructions
        pop edi
        pop esi
        pop ebx
        mov esp, ebp

        jmp hook_ret_addr
    }
}

namespace smedley::events
{
    ConsoleCmdManagerInitEvent::ConsoleCmdManagerInitEvent(v2::CConsoleCmdManager *cmd_mgr)
        : Event(false), _cmd_mgr(cmd_mgr)
    {
    }

    void ConsoleCmdManagerInitEvent::InstallHook()
    {
        hook_ret_addr = memory::Map::base_addr + hook_addr + 5;
        memory::Hook(memory::Map::base_addr + hook_addr, HookTrampoline, 5, nullptr);
    }

}