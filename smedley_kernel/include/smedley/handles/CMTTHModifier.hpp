#ifndef HANDLES_CMTTHMODIFIER_HPP_
#define HANDLES_CMTTHMODIFIER_HPP_

#include <cstdint>
#include "vector.hpp"
#include "CFixedPoint.hpp"

#pragma pack(push, 1)

namespace smedley
{
namespace handles
{

struct CMTTHModifier_vftable;
struct CTrigger;

struct CMTTHModifier
{
	CMTTHModifier_vftable * vftable;
	uint8_t field1_0x4;
	uint8_t field2_0x5;
	uint8_t field3_0x6;
	uint8_t field4_0x7;
	vector<CTrigger *> children;
	uint8_t field6_0x18;
	uint8_t field7_0x19;
	uint8_t field8_0x1a;
	uint8_t field9_0x1b;
	uint8_t field10_0x1c;
	uint8_t field11_0x1d;
	uint8_t field12_0x1e;
	uint8_t field13_0x1f;
	CFixedPoint factor;
};

}
}

#pragma pack(pop)

#endif // HANDLES_CMTTHMODIFIER_HPP_
