#ifndef COUNTRY_HOOK_HPP_
#define COUNTRY_HOOK_HPP_

#include "hook/hook.hpp"
#include "handles/CCountry.hpp"

#include <memory>

namespace smedley
{
namespace hook
{

class HookContainer
{
	std::unique_ptr<Hook<handles::CCountry *>> _afterCountryUpdate;
public:
	HookContainer(DWORD baseAddr);
	~HookContainer();

	Hook<handles::CCountry *> &afterCountryUpdate() { return *_afterCountryUpdate; };
};

}
}

#endif //  COUNTRY_HOOK_HPP_