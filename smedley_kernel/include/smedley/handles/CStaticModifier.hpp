#ifndef HANDLES_CSTATICMODIFIER_HPP_
#define HANDLES_CSTATICMODIFIER_HPP_

#include <cstdint>
#include "basic_string.hpp"
#include "vector.hpp"
#include "CFixedPoint.hpp"

#pragma pack(push, 1)

namespace smedley
{
namespace handles
{

struct CStaticModifier
{
	uint8_t **vtable;
	uint32_t field1_0x4;
	uint8_t **field2_0x8;
	uint8_t **field3_0xc;
	uint8_t **field4_0x10;
	uint8_t field5_0x14;
	uint8_t field6_0x15;
	uint8_t field7_0x16;
	uint8_t field8_0x17;
	vector<CFixedPoint> values;
	int icon;
	uint8_t field11_0x2c;
	uint8_t field12_0x2d;
	uint8_t field13_0x2e;
	uint8_t field14_0x2f;
	basic_string<char> name;
};

}
}

#pragma pack(pop)

#endif // HANDLES_CSTATICMODIFIER_HPP_
