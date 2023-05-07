#ifndef MEMORY_HPP_
#define MEMORY_HPP_

#include <cstdint>

#include <windows.h>
#include <memoryapi.h>

namespace smedley
{
namespace core
{
namespace memory
{

bool Hook(void *addr, void *jmp, int n)
{
	DWORD oldProtect, offset;

	if (n < 5) {
		return false;
	}

	offset = (DWORD) jmp - (DWORD) addr - 5;

	VirtualProtect(addr, n, PAGE_EXECUTE_READWRITE, &oldProtect);

	memset(((uint8_t *) addr)+1, 0x90, n-1); // fill the dest with noops for padding
	*(uint8_t *) addr = 0xe9;
	*(DWORD *) (((uint8_t *) addr) + 1) = offset;

	VirtualProtect(addr, n, oldProtect, &oldProtect);

	return true;
}

} // memory
} // core
} // smedley

#endif // MEMORY_HPP_