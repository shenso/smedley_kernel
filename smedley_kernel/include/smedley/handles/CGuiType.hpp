#ifndef HANDLES_CGUITYPE_HPP_
#define HANDLES_CGUITYPE_HPP_

#include <cstdint>
#include "basic_string.hpp"

#pragma pack(push, 1)

namespace smedley
{
namespace handles
{

struct CGuiType
{
	void **vftable;
	uint8_t field1_0x4;
	uint8_t field2_0x5;
	uint8_t field3_0x6;
	uint8_t field4_0x7;
	basic_string<char> name;
	uint8_t field6_0x24;
	uint8_t field7_0x25;
	uint8_t field8_0x26;
	uint8_t field9_0x27;
	uint8_t field10_0x28;
	uint8_t field11_0x29;
	uint8_t field12_0x2a;
	uint8_t field13_0x2b;
};

}
}

#pragma pack(pop)

#endif // HANDLES_CGUITYPE_HPP_
