#ifndef HANDLES_CTRIGGER_HPP_
#define HANDLES_CTRIGGER_HPP_

#include <cstdint>
#include "vector.hpp"

#pragma pack(push, 1)

namespace smedley
{
namespace native
{
namespace handles
{

struct CTrigger;
struct CTrigger_vftable;

struct CTrigger
{
	CTrigger_vftable *vftable;
	uint8_t field1_0x4;
	uint8_t field2_0x5;
	uint8_t field3_0x6;
	uint8_t field4_0x7;
	vector<CTrigger *> children;
};

}
}
}

#pragma pack(pop)

#endif // HANDLES_CTRIGGER_HPP_
