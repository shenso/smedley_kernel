#ifndef HANDLES_CEMPLOYEE_HPP_
#define HANDLES_CEMPLOYEE_HPP_

#include <cstdint>
#include <handles/CFixedPoint64.hpp>

#pragma pack(push, 1)

namespace smedley
{
namespace handles
{

struct CEmployee
{
	void **employee;
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
	CFixedPoint64 effectMultiplier;
	uint8_t field14_0x18;
	uint8_t field15_0x19;
	uint8_t field16_0x1a;
	uint8_t field17_0x1b;
	uint8_t field18_0x1c;
	uint8_t field19_0x1d;
	uint8_t field20_0x1e;
	uint8_t field21_0x1f;
};

}
}

#pragma pack(pop)

#endif // HANDLES_CEMPLOYEE_HPP_
