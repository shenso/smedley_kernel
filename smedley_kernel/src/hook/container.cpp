#ifndef HOOK_COUNTRY_HPP_
#define HOOK_COUNTRY_HPP_

#include "hook/container.hpp"
#include "kernel.hpp"

#include <mutex>

namespace smedley
{
namespace hook
{

Hook<handles::CCountry *> *__afterCountryUpdate = nullptr;
DWORD __afterCountryUpdateRetAddr = NULL;

void __declspec(naked) CountryAfterUpdateTrampoline()
{
	__asm {
		push esp
		push ecx
		push esi
		push ebx
		push ebp

		push ebx
		mov ecx, __afterCountryUpdate
		call Hook<handles::CCountry *>::Notify
		//pop ebx __thiscall

		pop ebp
		pop ebx
		pop esi
		pop ecx
		pop esp

		mov ecx, dword ptr [esp + 0x64]
		pop edi

		jmp __afterCountryUpdateRetAddr
	}
}

HookContainer::HookContainer(DWORD baseAddr)
{
	_afterCountryUpdate = std::make_unique<Hook<handles::CCountry *>>(baseAddr + 0x10918a, 5, CountryAfterUpdateTrampoline);
	__afterCountryUpdate = _afterCountryUpdate.get();
	__afterCountryUpdateRetAddr = baseAddr + 0x10918a + 5;
}

HookContainer::~HookContainer()
{
	__afterCountryUpdate = nullptr;
}

}
}

#endif // HOOK_COUNTRY_HPP_