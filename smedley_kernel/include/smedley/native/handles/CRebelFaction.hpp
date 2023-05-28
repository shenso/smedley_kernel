#ifndef HANDLES_CREBELFACTION_HPP_
#define HANDLES_CREBELFACTION_HPP_

#include <cstdint>
#include "CCountryTag.hpp"
#include "CUniqueUnitName.hpp"
#include "basic_string.hpp"
#include "ObjectReference.hpp"
#include "CList.hpp"
#include "CFixedPoint64.hpp"

#pragma pack(push, 1)

namespace smedley
{
namespace native
{
namespace handles
{

struct CPop;
struct CProvince;
struct CCulture;
struct CReligion;
struct CGovernment;
struct CRebelType;

struct CRebelFaction
{
	void **vftable;
	uint8_t field1_0x4;
	uint8_t field2_0x5;
	uint8_t field3_0x6;
	uint8_t field4_0x7;
	ObjectReference ref;
	uint8_t field6_0x10;
	uint8_t field7_0x11;
	uint8_t field8_0x12;
	uint8_t field9_0x13;
	uint8_t field10_0x14;
	uint8_t field11_0x15;
	uint8_t field12_0x16;
	uint8_t field13_0x17;
	uint8_t field14_0x18;
	uint8_t field15_0x19;
	uint8_t field16_0x1a;
	uint8_t field17_0x1b;
	uint8_t field18_0x1c;
	uint8_t field19_0x1d;
	uint8_t field20_0x1e;
	uint8_t field21_0x1f;
	uint8_t field22_0x20;
	uint8_t field23_0x21;
	uint8_t field24_0x22;
	uint8_t field25_0x23;
	uint8_t field26_0x24;
	uint8_t field27_0x25;
	uint8_t field28_0x26;
	uint8_t field29_0x27;
	uint8_t field30_0x28;
	uint8_t field31_0x29;
	uint8_t field32_0x2a;
	uint8_t field33_0x2b;
	uint8_t field34_0x2c;
	uint8_t field35_0x2d;
	uint8_t field36_0x2e;
	uint8_t field37_0x2f;
	CRebelType *type;
	CProvince *controller;
	CCountryTag target;
	CGovernment *government;
	CCountryTag supportedNation;
	CCulture *culture;
	CReligion *religion;
	CCountryTag field45_0x54;
	basic_string<char> name;
	uint8_t leaderRef;
	uint8_t field48_0x79;
	uint8_t field49_0x7a;
	uint8_t field50_0x7b;
	uint8_t field51_0x7c;
	uint8_t field52_0x7d;
	uint8_t field53_0x7e;
	uint8_t field54_0x7f;
	uint8_t field55_0x80;
	uint8_t field56_0x81;
	uint8_t field57_0x82;
	uint8_t field58_0x83;
	uint8_t field59_0x84;
	uint8_t field60_0x85;
	uint8_t field61_0x86;
	uint8_t field62_0x87;
	uint8_t field63_0x88;
	uint8_t field64_0x89;
	uint8_t field65_0x8a;
	uint8_t field66_0x8b;
	uint8_t field67_0x8c;
	uint8_t field68_0x8d;
	uint8_t field69_0x8e;
	uint8_t field70_0x8f;
	uint8_t field71_0x90;
	uint8_t field72_0x91;
	uint8_t field73_0x92;
	uint8_t field74_0x93;
	uint8_t provinces;
	uint8_t field76_0x95;
	uint8_t field77_0x96;
	uint8_t field78_0x97;
	uint8_t field79_0x98;
	uint8_t field80_0x99;
	uint8_t field81_0x9a;
	uint8_t field82_0x9b;
	uint8_t field83_0x9c;
	uint8_t field84_0x9d;
	uint8_t field85_0x9e;
	uint8_t field86_0x9f;
	uint8_t field87_0xa0;
	uint8_t field88_0xa1;
	uint8_t field89_0xa2;
	uint8_t field90_0xa3;
	CList<CPop *> pops;
	uint8_t field92_0xb4;
	uint8_t field93_0xb5;
	uint8_t field94_0xb6;
	uint8_t field95_0xb7;
	CFixedPoint64 organization;
	uint8_t field97_0xc0;
	uint8_t field98_0xc1;
	uint8_t field99_0xc2;
	uint8_t field100_0xc3;
	uint8_t field101_0xc4;
	uint8_t field102_0xc5;
	uint8_t field103_0xc6;
	uint8_t field104_0xc7;
	uint8_t field105_0xc8;
	uint8_t field106_0xc9;
	uint8_t field107_0xca;
	uint8_t field108_0xcb;
	CUniqueUnitName unitNames;
	int nextUnit;
};

}
}
}

#pragma pack(pop)

#endif // HANDLES_CREBELFACTION_HPP_
