#ifndef NATIVE_FUNCS_STATE_HPP_
#define NATIVE_FUNCS_STATE_HPP_

#include "../../kernel.hpp"
#include "../handles/basic_string.hpp"
#include "../handles/CState.hpp"

namespace smedley
{
namespace native
{
namespace funcs
{

namespace CState
{

handles::basic_string<char> GetName(handles::CState *_this)
{
	using fn_ptr = handles::basic_string<char> *(__thiscall *)(handles::CState *, handles::basic_string<char> *);
	auto fn = (fn_ptr) (core::Kernel::instance()->baseAddress() + 0xcece0);
	handles::basic_string<char> name = {};
	name.capacity = 0xf;
	fn(_this, &name);
	return name;
}

}

}
}
}

#endif // NATIVE_FUNCS_STATE_HPP_