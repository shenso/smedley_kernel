#ifndef FUNCTIONS_POP_HPP_
#define FUNCTIONS_POP_HPP_

#include "kernel.hpp"
#include "handles.hpp"

namespace smedley
{
namespace functions
{

namespace CPop
{

void __stdcall GiveMoney(handles::CPop *pop, handles::CashFlowType cfType, long long int amount)
{
	DWORD fn = core::Kernel::GetInstance()->baseAddress() + 0x55a5f0;
	uint32_t amount_00 = (uint32_t) (amount >> 32);
	uint32_t amount_01 = amount & 0xffffffff;

	__asm {
		mov eax, pop
		mov esi, cfType
		push amount_00
		push amount_01
		call fn // __stdcall
	}
}

}

}
}

// 55A5F0

#endif // FUNCTIONS_POP_HPP_