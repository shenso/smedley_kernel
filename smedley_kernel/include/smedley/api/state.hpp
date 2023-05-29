#ifndef API_STATE_HPP_
#define API_STATE_HPP_

#include "../native/handles/CState.hpp"
#include "native.hpp"
#include <windows.h>

namespace smedley
{
namespace api
{

using namespace native;

class SMEDLEY_API State
{
	handles::CState *_handle;
	static HandleRegistry<handles::CState *, State *> *_registry;
public:
	State(handles::CState *handle);
	std::string name();

	static void InstallHooks(DWORD baseAddr);
	static HandleRegistry<handles::CState *, State *> *registry() { return _registry; };
};

}
}

#endif // API_STATE_HPP_