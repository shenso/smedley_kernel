#ifndef HANDLES_CMODIFIER_HPP_
#define HANDLES_CMODIFIER_HPP_

#include <cstdint>
#include "CModifierEntry.hpp"
#include "vector.hpp"

#pragma pack(push, 1)

namespace smedley
{
namespace handles
{

struct CModifier
{
	uint8_t **vftable;
	uint32_t field1_0x4;
	uint8_t **field2_0x8;
	uint8_t **field3_0xc;
	uint8_t **field4_0x10;
	uint8_t field5_0x14;
	uint8_t field6_0x15;
	uint8_t field7_0x16;
	uint8_t field8_0x17;
	vector<CModifierEntry> entries;
	int icon;
	uint32_t field11_0x2c;
};

}
}

#pragma pack(pop)

#endif // HANDLES_CMODIFIER_HPP_
