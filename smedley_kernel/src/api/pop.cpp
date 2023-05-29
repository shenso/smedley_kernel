#include "api/pop.hpp"
#include "memory.hpp"
#include "native/funcs/pop.hpp"
#include <stdexcept>

using namespace smedley::api;
using namespace smedley::native;

void __stdcall RegisterPop(handles::CPop *handle)
{
	Pop::registry()->Register(handle, new Pop(handle));
}

void __stdcall UnregisterPop(handles::CPop *handle)
{
	Pop *pop = Pop::registry()->Get(handle);
	Pop::registry()->Unregister(handle);
	delete pop;
}

namespace smedley
{
namespace api
{

HandleRegistry<handles::CPop *, Pop *> *Pop::_registry = new HandleRegistry<handles::CPop *, Pop *>();

Pop::Pop(handles::CPop *handle) : _handle(handle) {
	if (_registry->Has(handle)) {
		throw std::runtime_error("handle is already registered!");
	}
}

void Pop::GiveMoney(CashFlowType cf, long long int amount)
{
	funcs::CPop::GiveMoney(_handle, cf, amount);
}

void Pop::InstallHooks(DWORD base_addr)
{
	uint8_t trampoline_template[] = {
		0x55,                         // push ebp
		0x8b, 0xec,                   // mov ebp, esp
		0x8b, 0x75, 0x08,             // mov esi, [ebp + 0x8]
		0x56,                         // push esi
		0xe8, 0x90, 0x90, 0x90, 0x90, // call <addr>
		0x6a, 0xff,                   // push -1
		0xe9, 0x90, 0x90, 0x90, 0x90  // jmp <addr>
	};

	uint8_t *constructor_trampoline_1 = new uint8_t[sizeof(trampoline_template)];
	uint8_t *constructor_trampoline_2 = new uint8_t[sizeof(trampoline_template)];
	uint8_t *constructor_trampoline_3 = new uint8_t[sizeof(trampoline_template)];
	uint8_t *destructor_trampoline = new uint8_t[sizeof(trampoline_template)];

	DWORD constr_tramp_1_addr = base_addr + 0x00554a40;
	DWORD constr_tramp_2_addr = base_addr + 0x00554f40;
	DWORD constr_tramp_3_addr = base_addr + 0x00555450;
	DWORD destr_tramp_addr = base_addr + 0x00555ae0;
	DWORD constr_tramp_1_ret_addr = (constr_tramp_1_addr + 5) - ((DWORD) constructor_trampoline_1 + 19);
	DWORD constr_tramp_2_ret_addr = (constr_tramp_2_addr + 5) - ((DWORD) constructor_trampoline_2 + 19);
	DWORD constr_tramp_3_ret_addr = (constr_tramp_3_addr + 5) - ((DWORD) constructor_trampoline_3 + 19);
	DWORD destr_tramp_ret_addr = (destr_tramp_addr + 5) - ((DWORD) destructor_trampoline + 19);

	std::copy(std::begin(trampoline_template), std::end(trampoline_template), constructor_trampoline_1);
	std::copy(std::begin(trampoline_template), std::end(trampoline_template), constructor_trampoline_2);
	std::copy(std::begin(trampoline_template), std::end(trampoline_template), constructor_trampoline_3);
	std::copy(std::begin(trampoline_template), std::end(trampoline_template), destructor_trampoline);

	DWORD old_protect;
	VirtualProtect(constructor_trampoline_1, sizeof(trampoline_template), PAGE_EXECUTE_READWRITE, &old_protect);
	VirtualProtect(constructor_trampoline_2, sizeof(trampoline_template), PAGE_EXECUTE_READWRITE, &old_protect);
	VirtualProtect(constructor_trampoline_3, sizeof(trampoline_template), PAGE_EXECUTE_READWRITE, &old_protect);
	VirtualProtect(destructor_trampoline, sizeof(trampoline_template), PAGE_EXECUTE_READWRITE, &old_protect);

	*(DWORD *) (constructor_trampoline_1 + 8) = (DWORD) RegisterPop - (DWORD) (constructor_trampoline_1 + 12);
	*(DWORD *) (constructor_trampoline_2 + 8) = (DWORD) RegisterPop - (DWORD) (constructor_trampoline_2 + 12);
	*(DWORD *) (constructor_trampoline_3 + 8) = (DWORD) RegisterPop - (DWORD) (constructor_trampoline_3 + 12);
	*(DWORD *) (destructor_trampoline + 8) = (DWORD) UnregisterPop - (DWORD) (destructor_trampoline + 12);
	*(DWORD *) (constructor_trampoline_1 + 15) = constr_tramp_1_ret_addr;
	*(DWORD *) (constructor_trampoline_2 + 15) = constr_tramp_2_ret_addr;
	*(DWORD *) (constructor_trampoline_3 + 15) = constr_tramp_3_ret_addr;
	*(DWORD *) (destructor_trampoline + 15) = destr_tramp_ret_addr;

	core::memory::Hook((void *) constr_tramp_1_addr, (void *) constructor_trampoline_1, 5, nullptr);
	core::memory::Hook((void *) constr_tramp_2_addr, (void *) constructor_trampoline_2, 5, nullptr);
	core::memory::Hook((void *) constr_tramp_3_addr, (void *) constructor_trampoline_3, 5, nullptr);
	core::memory::Hook((void *) destr_tramp_addr, (void *) destructor_trampoline, 5, nullptr);
}

}
}