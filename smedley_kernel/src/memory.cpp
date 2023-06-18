#include "memory.hpp"
#include <stdexcept>

namespace smedley
{
namespace core
{
namespace memory
{

bool Patch(void *addr, uint8_t *instr, int n)
{
	DWORD old_protect;

	VirtualProtect(addr, n, PAGE_EXECUTE_READWRITE, &old_protect);
	memcpy(addr, instr, n);
	VirtualProtect(addr, n, old_protect, &old_protect);

	return true;
}

bool Hook(void *addr, void *jmp, int n, std::vector<uint8_t> *old_instr)
{
	DWORD old_protect, offset;

	if (n < 5) {
		return false;
	}

	offset = (DWORD) jmp - (DWORD) addr - 5;

	VirtualProtect(addr, n, PAGE_EXECUTE_READWRITE, &old_protect);

	if (old_instr != nullptr) {
		uint8_t *ptr;
		old_instr->clear();
		for (int i = 0; i < n; i++) {
			ptr = ((uint8_t *) (addr)) + i;
			old_instr->push_back(*ptr);
		}
	}

	std::memset(((uint8_t *) addr)+1, 0x90, n-1); // fill the dest with noops for padding
	*(uint8_t *) addr = 0xe9;
	*(DWORD *) (((uint8_t *) addr) + 1) = offset;

	VirtualProtect(addr, n, old_protect, &old_protect);

	return true;
}

} // memory
} // core
} // smedley