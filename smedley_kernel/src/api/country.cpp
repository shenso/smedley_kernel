#include "api/country.hpp"
#include "native/handles/CCountry.hpp"
#include "native/funcs/country.hpp"
#include "memory.hpp"
#include <stdexcept>

using namespace smedley::native;

DWORD AFTER_COUNTRY_INSTANTIATION_RET = NULL;
DWORD AFTER_NULL_COUNTRY_INSTANTIATION_RET = NULL;
DWORD AFTER_NULL_COUNTRY_INSTANTIATION_JMP = NULL;

void __stdcall RegisterNativeCountry(handles::CCountry *handle)
{
	smedley::api::Country::registry()->Register(handle, new smedley::api::NativeCountry(handle));
}

void __declspec(naked) AfterCountryInstantiationTrampoline()
{
	__asm {
		push eax
		push ecx 
		push edx
		push ebx
		push esp
		push ebp
		push esi
		push edi

		push eax
		call RegisterNativeCountry

		pop edi
		pop esi
		pop ebp
		pop esp
		pop ebx
		pop edx
		pop ecx
		pop eax

		mov edx, eax
		mov dword ptr [esp + 0x24], eax
		jmp AFTER_COUNTRY_INSTANTIATION_RET
	}
}


void __declspec(naked) AfterNullCountryInstantiationTrampoline()
{
	__asm {
		push eax
		push ecx
		push edx
		push ebx
		push esp
		push ebp
		push esi
		push edi

		push eax
		call RegisterNativeCountry

		pop edi
		pop esi
		pop ebp
		pop esp
		pop ebx
		pop edx
		pop ecx
		pop eax

		mov edi, eax
		jmp AFTER_NULL_COUNTRY_INSTANTIATION_JMP
		xor edi, edi
		jmp AFTER_NULL_COUNTRY_INSTANTIATION_RET
	}
}

namespace smedley
{
namespace api
{

HandleRegistry<handles::CCountry *, Country *> *Country::_registry = new HandleRegistry<handles::CCountry *, Country *>();

Country::Country(handles::CCountry *handle) : _handle(handle)
{
	if (Country::registry()->Has(handle)) {
		throw std::runtime_error("country is already registered.");
	}
}

NativeCountry::NativeCountry(handles::CCountry *handle) : Country(handle)
{
}

std::string NativeCountry::name()
{
	handles::basic_string<char> nameHandle = funcs::CCountry::GetName(handle());
	return nameHandle.transform();
}

void NativeCountry::InstallHooks(DWORD baseAddr)
{
	DWORD afterNullCountryInstantiation = baseAddr + 0x0015a84f;
	DWORD afterCountryInstantiation = baseAddr + 0x0015af37;

	AFTER_NULL_COUNTRY_INSTANTIATION_RET = afterNullCountryInstantiation + 6;
	AFTER_COUNTRY_INSTANTIATION_RET = afterCountryInstantiation + 6;
	AFTER_NULL_COUNTRY_INSTANTIATION_JMP = baseAddr + 0x0015a85a;

	core::memory::Hook((void *) (baseAddr + afterNullCountryInstantiation), AfterNullCountryInstantiationTrampoline, 6, nullptr);
	core::memory::Hook((void *) afterCountryInstantiation, AfterCountryInstantiationTrampoline, 6, nullptr);
}


}
}

