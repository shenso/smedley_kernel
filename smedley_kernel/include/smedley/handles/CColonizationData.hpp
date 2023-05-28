#ifndef HANDLES_CCOLONIZATIONDATA_HPP_
#define HANDLES_CCOLONIZATIONDATA_HPP_

#include <cstdint>
#include "SColonist.hpp"
#include "CEU3Date.hpp"

#pragma pack(push, 1)

namespace smedley
{
namespace handles
{

struct CColonizationData
{
	void **vftable;
	uint8_t field1_0x4;
	uint8_t field2_0x5;
	uint8_t field3_0x6;
	uint8_t field4_0x7;
	uint8_t field5_0x8;
	uint8_t field6_0x9;
	uint8_t field7_0xa;
	uint8_t field8_0xb;
	uint8_t field9_0xc;
	uint8_t field10_0xd;
	uint8_t field11_0xe;
	uint8_t field12_0xf;
	CEU3Date date__;
	uint8_t field14_0x14;
	uint8_t field15_0x15;
	uint8_t field16_0x16;
	uint8_t field17_0x17;
	SColonist colonists[4];
};

}
}

#pragma pack(pop)

#endif // HANDLES_CCOLONIZATIONDATA_HPP_
