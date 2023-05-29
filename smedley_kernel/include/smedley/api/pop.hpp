#ifndef API_POP_HPP_
#define API_POP_HPP_

#include "native.hpp"
#include "../native/handles/CPop.hpp"
#include "../native/handles/CashFlowType.hpp"
#include <windows.h>

namespace smedley
{
namespace api
{

using namespace native;

using CashFlowType = handles::CashFlowType;

class SMEDLEY_API Pop
{
	handles::CPop *_handle;
	static HandleRegistry<handles::CPop *, Pop *> *_registry;
public:
	Pop(handles::CPop *handle);

	void GiveMoney(CashFlowType cf, long long int amount);

	long long int money() { return _handle->money; }
	long long int savings() { return _handle->savingsInBank; }

	static void InstallHooks(DWORD baseAddr);
	static HandleRegistry<handles::CPop *, Pop *> *registry() { return _registry; };
};

}
}

#endif // API_POP_HPP_