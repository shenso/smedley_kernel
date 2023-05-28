#ifndef HANDLES_CANDTRIGGER_HPP_
#define HANDLES_CANDTRIGGER_HPP_

#include <cstdint>
#include "vector.hpp"

#pragma pack(push, 1)

namespace smedley
{
namespace handles
{

struct CTrigger;
struct CAndTrigger_vftable;

struct CAndTrigger
{
	CAndTrigger_vftable * vftable;
	uint8_t field1_0x4;
	uint8_t field2_0x5;
	uint8_t field3_0x6;
	uint8_t field4_0x7;
	vector<CTrigger *> operands;
	uint8_t field6_0x18;
	uint8_t field7_0x19;
	uint8_t field8_0x1a;
	uint8_t field9_0x1b;
};

}
}

#pragma pack(pop)

#endif // HANDLES_CANDTRIGGER_HPP_
