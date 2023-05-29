#include "plugin.hpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

#include <smedley/kernel.hpp>
#include <smedley/memory.hpp>
#include <smedley/api/Country.hpp>
#include <smedley/native/handles/CCountry.hpp>
#include <smedley/native/handles/CGameState.hpp>
#include <smedley/native/handles/CState.hpp>
#include <smedley/native/handles/CFixedPoint64.hpp>
#include <smedley/native/handles/CProvince.hpp>
#include <smedley/native/handles/CPopList.hpp>
#include <smedley/native/funcs/country.hpp>
#include <smedley/native/funcs/gamestate.hpp>
#include <smedley/native/funcs/province.hpp>
#include <smedley/native/funcs/pop.hpp>

using namespace smedley::native;

namespace v2up
{

void PayPopInterest(handles::CCountry *country)
{
	DWORD baseAddr = core::Kernel::instance()->baseAddress();
	handles::CGameState *gameState = funcs::CCurrentGameState::instance();
	handles::CFixedPoint64 popMoneyScaleFactor = *(handles::CFixedPoint64 *) (baseAddr + 0xb0b168); // pretty sure this is always 1000.0

	auto countryApi = api::Country::registry()->Get(country);
	for (auto &state : countryApi->states()) {
		MessageBox(NULL, state.name().c_str(), "TEST", MB_ICONINFORMATION);
	}

	for (auto state : country->states) {
		handles::CFixedPoint64 stateSavings = state->savingsInBank;
		handles::CFixedPoint64 origAmount = state->interestPayments;

		// interest must be at least $1
		if (stateSavings.qty == 0 || origAmount.qty < 1ll << 0xf) {
			continue;
		}

		for (int provinceId : state->provinces) {
			handles::CProvince *province = gameState->provinces[provinceId];

			for (auto &popList : province->pops) {
				for (auto &pop : popList) {
					if (pop.savingsInBank == 0) {
						continue;
					}

					handles::CFixedPoint64 popSavings{(pop.savingsInBank << 0xf) / popMoneyScaleFactor.qty};
					double percentage = (double) popSavings.qty / stateSavings.qty;
					handles::CFixedPoint64 payment{(long long int) (percentage * origAmount.qty)};
					state->interestPayments.qty -= payment.qty;
					if (state->interestPayments.qty < 0) {
						payment.qty += state->interestPayments.qty;
						state->interestPayments.qty = 0;
					}
					long long int popPayment = (payment.qty * popMoneyScaleFactor.qty) >> 0xf;

					funcs::CPop::GiveMoney(&pop, handles::CashFlowType::CF_INTEREST_PAYMENT, popPayment);
				}
			}
		}
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
	core::Kernel *kernel = core::Kernel::instance();

	injectors::ConsoleCommandInfo metadata{};
	metadata.name = "v2up";
	kernel->consoleInjector()->Inject(metadata, V2UPCommandHandler);

	kernel->hooks()->afterCountryUpdate().Add("pay_pop_interest", PayPopInterest, 0);
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
