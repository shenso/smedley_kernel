#include "memory.hpp"

namespace smedley
{
namespace core
{
namespace memory
{

bool Patch(void *addr, uint8_t *instr, int n)
{
	DWORD oldProtect;

	VirtualProtect(addr, n, PAGE_EXECUTE_READWRITE, &oldProtect);
	memcpy(addr, instr, n);
	VirtualProtect(addr, n, oldProtect, &oldProtect);

	return true;
}

bool Hook(void *addr, void *jmp, int n, std::vector<uint8_t> *oldInstr)
{
	DWORD oldProtect, offset;

	if (n < 5) {
		return false;
	}

	offset = (DWORD) jmp - (DWORD) addr - 5;

	VirtualProtect(addr, n, PAGE_EXECUTE_READWRITE, &oldProtect);

	if (oldInstr != nullptr) {
		uint8_t *ptr;
		oldInstr->clear();
		for (int i = 0; i < n; i++) {
			ptr = ((uint8_t *) (addr)) + i;
			oldInstr->push_back(*ptr);
		}
	}

	memset(((uint8_t *) addr)+1, 0x90, n-1); // fill the dest with noops for padding
	*(uint8_t *) addr = 0xe9;
	*(DWORD *) (((uint8_t *) addr) + 1) = offset;

	VirtualProtect(addr, n, oldProtect, &oldProtect);

	return true;
}


} // memory
} // core
} // smedley