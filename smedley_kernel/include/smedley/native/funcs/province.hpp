#ifndef FUNCTIONS_PROVINCE_HPP_
#define FUNCTIONS_PROVINCE_HPP_

#include "../../kernel.hpp"
#include "../handles/basic_string.hpp"
#include "../handles/CProvince.hpp"

namespace smedley
{
namespace native
{
namespace funcs
{

namespace CProvince
{

handles::basic_string<char> GetName(handles::CProvince *_this)
{
	handles::basic_string<char> name = {};
	auto namePtr = &name;
	DWORD addr = core::Kernel::instance()->baseAddress() + 0xaaf90;
	name.capacity = 0xf;

	__asm {
		mov ecx, _this
		push namePtr
		call addr
	}

	return name;
}

}

}
}
}

#endif // FUNCTIONS_PROVINCE_HPP_