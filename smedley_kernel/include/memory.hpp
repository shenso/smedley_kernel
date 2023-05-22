#ifndef MEMORY_HPP_
#define MEMORY_HPP_

#include <cstdint>
#include <vector>

#include <windows.h>
#include <memoryapi.h>

namespace smedley
{
namespace core
{
namespace memory
{

bool Patch(void *addr, uint8_t *instr, int n);

bool Hook(void *addr, void *jmp, int n, std::vector<uint8_t> *oldInstr);

} // memory
} // core
} // smedley

#endif // MEMORY_HPP_