#ifndef HANDLES_CHISTORYCONTAINER_HPP_
#define HANDLES_CHISTORYCONTAINER_HPP_

#include <cstdint>
#include "CEU3Date.hpp"

#pragma pack(push, 1)

namespace smedley
{
namespace native
{
namespace handles
{

struct CHistoryContainer
{
	void **vtable;
	uint8_t field1_0x4;
	uint8_t field2_0x5;
	uint8_t field3_0x6;
	uint8_t field4_0x7;
	CEU3Date date;
	uint8_t **field6_0xc;
	uint8_t **field7_0x10;
	uint8_t **field8_0x14;
	uint8_t field9_0x18;
	uint8_t field10_0x19;
	uint8_t field11_0x1a;
	uint8_t field12_0x1b;
	uint8_t field13_0x1c;
	uint8_t field14_0x1d;
	uint8_t field15_0x1e;
	uint8_t field16_0x1f;
	uint8_t field17_0x20;
	uint8_t field18_0x21;
	uint8_t field19_0x22;
	uint8_t field20_0x23;
};

}
}
}

#pragma pack(pop)

#endif // HANDLES_CHISTORYCONTAINER_HPP_
