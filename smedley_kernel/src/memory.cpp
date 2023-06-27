#include "memory.hpp"
#include <cstdint>
#include <stdexcept>

namespace smedley::memory
{

    uintptr_t Map::base_addr = NULL;
    HANDLE Map::game_heap = NULL;

    void __stdcall HeapInitHook(HANDLE heap)
    {
        Map::game_heap = heap;
    }

    void Map::Init()
    {
        Map::base_addr = reinterpret_cast<uintptr_t>(GetModuleHandle(NULL));

        constexpr uint8_t trampoline_template[] = {
            0x50, // push eax
            0x50, // push eax
            0xe8, 0x90, 0x90, 0x90, 0x90, // call <addr>
            0x58, // pop eax

            0xa3, 0xe8, 0x02, 0xb2, 0x00, // mov [HEAP_HANDLE], eax
            0x8b, 0xc1, // mov eax, ecx
            0xc3, // ret
        };

        uint8_t *trampoline = new uint8_t[sizeof(trampoline_template)];
        uintptr_t trampoline_jmp = (reinterpret_cast<uintptr_t>(HeapInitHook) + 9) - reinterpret_cast<uintptr_t>((trampoline + sizeof(trampoline_template)));

        std::copy(std::begin(trampoline_template), std::end(trampoline_template), trampoline);
        *reinterpret_cast<uintptr_t *>(trampoline + 3) = trampoline_jmp;
        *reinterpret_cast<uintptr_t *>(trampoline + 9) = Map::base_addr + 0x00b202e8;
        {
            DWORD old_protect;
            VirtualProtect(trampoline, sizeof(trampoline_template), PAGE_EXECUTE_READWRITE, &old_protect);
        }

        Hook(Map::base_addr + 0x006babee, trampoline, 8, nullptr);
    }

    bool Patch(uintptr_t addr, uint8_t *instr, int n)
    {
        DWORD old_protect;
        LPVOID lpv_addr = reinterpret_cast<LPVOID>(addr);

        VirtualProtect(lpv_addr, n, PAGE_EXECUTE_READWRITE, &old_protect);
        memcpy(lpv_addr, instr, n);
        VirtualProtect(lpv_addr, n, old_protect, &old_protect);

        return true;
    }

    bool Hook(uintptr_t addr, void *jmp, int n, std::vector<uint8_t> *old_instr)
    {
        DWORD old_protect, offset;
        LPVOID lpv_addr = reinterpret_cast<LPVOID>(addr);
        uint8_t *bytes_addr = reinterpret_cast<uint8_t *>(addr);

        if (n < 5) {
            return false;
        }

        offset = reinterpret_cast<uintptr_t>(jmp) - addr - 5;

        VirtualProtect(lpv_addr, n, PAGE_EXECUTE_READWRITE, &old_protect);

        if (old_instr != nullptr) {
            uint8_t *ptr;
            old_instr->clear();
            for (int i = 0; i < n; i++) {
                ptr = bytes_addr + i;
                old_instr->push_back(*ptr);
            }
        }

        std::memset(bytes_addr + 1, 0x90, n - 1); // fill the dest with noops for padding
        *bytes_addr = 0xe9;
        *reinterpret_cast<DWORD *>(bytes_addr + 1) = offset;

        VirtualProtect(lpv_addr, n, old_protect, &old_protect);

        return true;
    }
}