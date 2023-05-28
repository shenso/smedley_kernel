#ifndef HANDLES_CMEANTIMETOHAPPEN_HPP_
#define HANDLES_CMEANTIMETOHAPPEN_HPP_

#include <cstdint>
#include "vector.hpp"
#include "CFixedPoint.hpp"

#pragma pack(push, 1)

namespace smedley
{
namespace native
{
namespace handles
{

struct CMTTHModifier;

struct CMeanTimeToHappen
{
	void **vftable;
	uint8_t field1_0x4;
	uint8_t field2_0x5;
	uint8_t field3_0x6;
	uint8_t field4_0x7;
	CFixedPoint baseDays;
	vector<CMTTHModifier *> modifiers;
};

}
}
}

#pragma pack(pop)

#endif // HANDLES_CMEANTIMETOHAPPEN_HPP_
