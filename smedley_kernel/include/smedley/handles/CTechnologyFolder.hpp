#ifndef HANDLES_CTECHNOLOGYFOLDER_HPP_
#define HANDLES_CTECHNOLOGYFOLDER_HPP_

#include <cstdint>
#include "basic_string.hpp"

#pragma pack(push, 1)

namespace smedley
{
namespace handles
{

struct CTechnologyFolder
{
	void **vftable;
	uint8_t field1_0x4;
	uint8_t field2_0x5;
	uint8_t field3_0x6;
	uint8_t field4_0x7;
	basic_string<char> name;
	basic_string<char> label;
	uint8_t field7_0x40;
	uint8_t field8_0x41;
	uint8_t field9_0x42;
	uint8_t field10_0x43;
	uint8_t field11_0x44;
	uint8_t field12_0x45;
	uint8_t field13_0x46;
	uint8_t field14_0x47;
};

}
}

#pragma pack(pop)

#endif // HANDLES_CTECHNOLOGYFOLDER_HPP_
