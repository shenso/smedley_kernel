#ifndef HANDLES_CRULEDEFINITION_HPP_
#define HANDLES_CRULEDEFINITION_HPP_

#include <cstdint>

#pragma pack(push, 1)

namespace smedley
{
namespace handles
{

struct CRuleDefinition
{
	uint8_t **vtable;
	char name[16];
	char * field2_0x14;
	uint8_t **field3_0x18;
	uint8_t field4_0x1c;
	uint8_t field5_0x1d;
	uint8_t field6_0x1e;
	uint8_t field7_0x1f;
	uint8_t **field8_0x20;
	char * field9_0x24;
	uint8_t field10_0x28;
};

}
}

#pragma pack(pop)

#endif // HANDLES_CRULEDEFINITION_HPP_
