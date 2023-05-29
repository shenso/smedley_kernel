#ifndef NATIVE_FUNCS_COUNTRY_HPP_
#define NATIVE_FUNCS_COUNTRY_HPP_

#include "../../kernel.hpp"
#include "../handles/basic_string.hpp"
#include "../handles/CCountry.hpp"
#include <windows.h>

namespace smedley
{
namespace native
{
namespace funcs
{

namespace CCountry
{

handles::basic_string<char> GetName(handles::CCountry *_this)
{
	handles::basic_string<char> name = {};
	name.capacity = 0xf;
	auto namePtr = &name;
	DWORD addr = core::Kernel::instance()->baseAddress() + 0x000f97a0;

	__asm {
		mov eax, _this
		mov ecx, namePtr
		call addr
	}

	return name;
}

}

}
}
}

#endif // NATIVE_FUNCS_COUNTRY_HPP_