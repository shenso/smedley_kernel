#include "plugin.hpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

#include <kernel.hpp>
#include <memory.hpp>
#include <handles.hpp>
#include <functions/gamestate.hpp>
#include <functions/pop.hpp>

namespace v2up
{

DWORD COUNTRY_UPDATE_RET_ADDR = NULL;

void PayPopInterest(handles::CCountry *country)
{
	DWORD baseAddr = core::Kernel::GetInstance()->baseAddress();
	handles::CGameState *gameState = functions::CCurrentGameState::GetInstance();
	handles::CFixedPoint64 popMoneyScaleFactor = *(handles::CFixedPoint64 *) (baseAddr + 0xb0b168); // pretty sure this is always 1000.0

	for (auto node = country->states.first; node != country->states.last; node = node->next) {
		handles::CState *state = node->val;
		handles::CFixedPoint64 stateSavings = state->savingsInBank;
		handles::CFixedPoint64 origAmount = state->interestPayments;

		// interest must be at least $1
		if (stateSavings.qty == 0 || origAmount.qty < 1ll << 0xf) {
			continue;
		}

		for (int *provCursor = state->provinces.first; provCursor != state->provinces.last; provCursor++) {
			int provinceId = *provCursor;
			handles::CProvince *province = gameState->provinces.first[provinceId];

			for (handles::CPopList *popList = province->pops.first; popList != province->pops.last; popList++) {
				for (auto pop = popList->first; pop != nullptr; pop = pop->next) {
					handles::CFixedPoint64 popSavings{(pop->savingsInBank << 0xf) / popMoneyScaleFactor.qty};
					double percentage = (double) popSavings.qty / stateSavings.qty;
					handles::CFixedPoint64 payment{(long long int) (percentage * origAmount.qty)};
					state->interestPayments.qty -= payment.qty;
					if (state->interestPayments.qty < 0) {
						payment.qty += state->interestPayments.qty;
						state->interestPayments.qty = 0;
					}
					long long int popPayment = (payment.qty * popMoneyScaleFactor.qty) >> 0xf;

					functions::CPop::GiveMoney(pop, handles::CashFlowType::CF_INTEREST_PAYMENT, popPayment);
				}
			}
		}
	}
}

// TODO: add hooking CCountry::Update to smedley proper
void __declspec(naked) CountryUpdateTrampoline()
{
	__asm {
		push esp
		push ecx
		push esi
		push ebx
		push ebp

		push ebx
		call PayPopInterest
		pop ebx

		pop ebp
		pop ebx
		pop esi
		pop ecx
		pop esp

		mov ecx, dword ptr [esp + 0x64]
		pop edi

		jmp COUNTRY_UPDATE_RET_ADDR
	}
}

handles::ConsoleCommandOutput *V2UPCommandHandler(handles::ConsoleCommandOutput *out, handles::vector<handles::basic_string<char>> *argv)
{
	out->message.capacity = 0xf;
	out->message.size = 9;
	std::strcpy(out->message._impl, "V2UP v0.1");
	out->success = true;

	return out;
}

V2UPPlugin::~V2UPPlugin()
{
}

void V2UPPlugin::OnAttach()
{
	LPVOID patchAddr;
	core::Kernel *kernel = core::Kernel::GetInstance();

	injectors::ConsoleCommandInfo metadata{};
	metadata.name = "v2up";
	kernel->consoleInjector()->Inject(metadata, V2UPCommandHandler);

	patchAddr = (LPVOID) (kernel->baseAddress() + 0x10918a);
	COUNTRY_UPDATE_RET_ADDR = (DWORD) patchAddr + 5;
	core::memory::Hook(patchAddr, CountryUpdateTrampoline, 5);
}

PLUGIN_API core::Plugin *MakePlugin()
{
	return static_cast<core::Plugin *>(new v2up::V2UPPlugin());
}

PLUGIN_API const char *PluginName()
{
	return "v2up";
}

}
