#ifndef HANDLES_CPROVINCEBUILDING_HPP_
#define HANDLES_CPROVINCEBUILDING_HPP_

#include <cstdint>
#include "CFixedPoint.hpp"

#pragma pack(push, 1)

namespace smedley
{
namespace handles
{

struct CProvinceBuilding
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
	uint8_t field13_0x10;
	uint8_t field14_0x11;
	uint8_t field15_0x12;
	uint8_t field16_0x13;
	uint8_t field17_0x14;
	uint8_t field18_0x15;
	uint8_t field19_0x16;
	uint8_t field20_0x17;
	uint8_t field21_0x18;
	uint8_t field22_0x19;
	uint8_t field23_0x1a;
	uint8_t field24_0x1b;
	uint8_t field25_0x1c;
	uint8_t field26_0x1d;
	uint8_t field27_0x1e;
	uint8_t field28_0x1f;
	CFixedPoint quantity;
	CFixedPoint quantity2;
};

}
}

#pragma pack(pop)

#endif // HANDLES_CPROVINCEBUILDING_HPP_
