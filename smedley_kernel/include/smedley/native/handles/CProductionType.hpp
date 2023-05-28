#ifndef HANDLES_CPRODUCTIONTYPE_HPP_
#define HANDLES_CPRODUCTIONTYPE_HPP_

#include <cstdint>
#include "CGoodsPool.hpp"
#include "basic_string.hpp"
#include "CEmployee.hpp"
#include "CFixedPoint64.hpp"
#include "vector.hpp"

#pragma pack(push, 1)

namespace smedley
{
namespace native
{
namespace handles
{

struct CProductionType
{
	void **vftable;
	uint8_t field1_0x4;
	uint8_t field2_0x5;
	uint8_t field3_0x6;
	uint8_t field4_0x7;
	basic_string<char> name;
	CGoodsPool inputGoods;
	bool isCoastal;
	uint8_t field8_0x7d;
	uint8_t field9_0x7e;
	uint8_t field10_0x7f;
	uint8_t field11_0x80;
	uint8_t field12_0x81;
	uint8_t field13_0x82;
	uint8_t field14_0x83;
	uint8_t field15_0x84;
	uint8_t field16_0x85;
	uint8_t field17_0x86;
	uint8_t field18_0x87;
	CFixedPoint64 value;
	CGoodsPool efficiency;
	CEmployee owner;
	vector<void *> employees;
	uint8_t field23_0x118;
	uint8_t field24_0x119;
	uint8_t field25_0x11a;
	uint8_t field26_0x11b;
	uint8_t field27_0x11c;
	uint8_t field28_0x11d;
	uint8_t field29_0x11e;
	uint8_t field30_0x11f;
	uint8_t field31_0x120;
	uint8_t field32_0x121;
	uint8_t field33_0x122;
	uint8_t field34_0x123;
	uint8_t field35_0x124;
	uint8_t field36_0x125;
	uint8_t field37_0x126;
	uint8_t field38_0x127;
	int workforceSize;
	uint8_t field40_0x12c;
	uint8_t field41_0x12d;
	uint8_t field42_0x12e;
	uint8_t field43_0x12f;
	uint8_t field44_0x130;
	uint8_t field45_0x131;
	uint8_t field46_0x132;
	uint8_t field47_0x133;
	uint8_t field48_0x134;
	uint8_t field49_0x135;
	uint8_t field50_0x136;
	uint8_t field51_0x137;
	uint8_t field52_0x138;
	uint8_t field53_0x139;
	uint8_t field54_0x13a;
	uint8_t field55_0x13b;
	bool isMine;
	bool isFarm;
	bool limitByLocalSupply;
	uint8_t field59_0x13f;
	uint8_t field60_0x140;
	uint8_t field61_0x141;
	uint8_t field62_0x142;
	uint8_t field63_0x143;
	uint8_t field64_0x144;
	uint8_t field65_0x145;
	uint8_t field66_0x146;
	uint8_t field67_0x147;
	CFixedPoint64 artisanMinProductivity__;
	vector<void *> bonuses;
};

}
}
}

#pragma pack(pop)

#endif // HANDLES_CPRODUCTIONTYPE_HPP_
