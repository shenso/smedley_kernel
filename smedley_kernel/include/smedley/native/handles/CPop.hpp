#ifndef HANDLES_CPOP_HPP_
#define HANDLES_CPOP_HPP_

#include <cstdint>
#include "basic_string.hpp"
#include "CDataSpread.hpp"
#include "ObjectReference.hpp"
#include "CFixedPoint64.hpp"
#include "vector.hpp"

#pragma pack(push, 1)

namespace smedley
{
namespace native
{
namespace handles
{

struct CMapProvince;
struct CPop;
struct CCulture;
struct CPopType;
struct CReligion;
struct CPopEconomy;

struct CPop
{
	void **vtable;
	ObjectReference ref;
	basic_string<char> field2_0xc;
	uint32_t field3_0x28;
	uint8_t field4_0x2c;
	uint8_t field5_0x2d;
	uint8_t field6_0x2e;
	uint8_t field7_0x2f;
	uint32_t field8_0x30;
	uint32_t field9_0x34;
	uint8_t field10_0x38;
	uint8_t field11_0x39;
	uint8_t field12_0x3a;
	uint8_t field13_0x3b;
	vector<void *> subunits__;
	uint8_t field15_0x4c;
	uint8_t field16_0x4d;
	uint8_t field17_0x4e;
	uint8_t field18_0x4f;
	uint32_t field19_0x50;
	uint32_t field20_0x54;
	int size;
	unsigned int prevPopCount;
	unsigned int employedPops;
	CMapProvince *province;
	CPopType *popType;
	CCulture *culture;
	CReligion *religion;
	CDataSpread<CFixedPoint64> ideology;
	CDataSpread<CFixedPoint64> issues;
	CDataSpread<CFixedPoint64> peoplesIdeologies__;
	CDataSpread<CFixedPoint64> peoplesIssues__;
	uint32_t field32_0x114;
	CFixedPoint64 consciousness;
	CFixedPoint64 militancy;
	CFixedPoint64 literacy;
	CFixedPoint64 lifeNeedsMet__;
	CFixedPoint64 everydayNeedsMet__;
	CFixedPoint64 luxuryNeedsMet__;
	uint8_t field39_0x148;
	uint8_t field40_0x149;
	uint8_t field41_0x14a;
	uint8_t field42_0x14b;
	uint8_t field43_0x14c;
	uint8_t field44_0x14d;
	uint8_t field45_0x14e;
	uint8_t field46_0x14f;
	CFixedPoint64 revoltRisk;
	uint32_t field48_0x158;
	uint32_t field49_0x15c;
	uint32_t field50_0x160;
	uint32_t field51_0x164;
	uint32_t field52_0x168;
	uint32_t field53_0x16c;
	uint32_t field54_0x170;
	uint32_t field55_0x174;
	uint32_t field56_0x178;
	uint8_t field57_0x17c;
	uint8_t field58_0x17d;
	uint8_t field59_0x17e;
	uint8_t field60_0x17f;
	long long int money;
	long long int dailyMoney__;
	int promoted;
	int demoted;
	int converted;
	int assimilated;
	int localMigration;
	int colonialMigration;
	int externalMigration;
	uint32_t field70_0x1ac;
	CFixedPoint64 consciousnessFactor;
	uint32_t field72_0x1b8;
	uint32_t field73_0x1bc;
	uint32_t field74_0x1c0;
	uint32_t field75_0x1c4;
	uint32_t field76_0x1c8;
	uint32_t field77_0x1cc;
	uint32_t field78_0x1d0;
	CPopEconomy *economy;
	CFixedPoint64 cashFlow[9];
	uint8_t field81_0x220;
	uint8_t field82_0x221;
	uint8_t field83_0x222;
	uint8_t field84_0x223;
	uint8_t field85_0x224;
	uint8_t field86_0x225;
	uint8_t field87_0x226;
	uint8_t field88_0x227;
	uint8_t field89_0x228;
	uint8_t field90_0x229;
	uint8_t field91_0x22a;
	uint8_t field92_0x22b;
	uint8_t field93_0x22c;
	uint8_t field94_0x22d;
	uint8_t field95_0x22e;
	uint8_t field96_0x22f;
	uint32_t field97_0x230;
	uint32_t field98_0x234;
	uint32_t field99_0x238;
	uint32_t field100_0x23c;
	uint32_t field101_0x240;
	uint32_t field102_0x244;
	uint8_t field103_0x248;
	uint8_t field104_0x249;
	uint8_t field105_0x24a;
	uint8_t field106_0x24b;
	uint8_t field107_0x24c;
	uint8_t field108_0x24d;
	uint8_t field109_0x24e;
	uint8_t field110_0x24f;
	long long int savingsInBank;
	int random;
	uint8_t field113_0x25c;
	uint8_t field114_0x25d;
	uint8_t field115_0x25e;
	uint8_t field116_0x25f;
	uint8_t field117_0x260;
	uint8_t field118_0x261;
	uint8_t field119_0x262;
	uint8_t field120_0x263;
	uint8_t field121_0x264;
	uint8_t field122_0x265;
	uint8_t field123_0x266;
	uint8_t field124_0x267;
	uint8_t field125_0x268;
	uint8_t field126_0x269;
	uint8_t field127_0x26a;
	uint8_t field128_0x26b;
	int daysOfLoss;
	int movement;
	uint8_t field131_0x274;
	uint8_t field132_0x275;
	uint8_t field133_0x276;
	uint8_t field134_0x277;
	CPop *prev;
	CPop *next;
	uint8_t field137_0x280;
	uint8_t field138_0x281;
	uint8_t field139_0x282;
	uint8_t field140_0x283;
	uint8_t field141_0x284;
	uint8_t field142_0x285;
	uint8_t field143_0x286;
	uint8_t field144_0x287;
};

}
}
}

#pragma pack(pop)

#endif // HANDLES_CPOP_HPP_
