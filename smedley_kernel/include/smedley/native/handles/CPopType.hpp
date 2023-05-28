#ifndef HANDLES_CPOPTYPE_HPP_
#define HANDLES_CPOPTYPE_HPP_

#include <cstdint>
#include "CMeanTimeToHappen.hpp"
#include "CGoodsPool.hpp"
#include "basic_string.hpp"
#include "CPopIncome.hpp"
#include "CFixedPoint64.hpp"
#include "CColor.hpp"
#include "vector.hpp"
#include "CFixedPoint.hpp"
#include "PopStrata.hpp"

#pragma pack(push, 1)

namespace smedley
{
namespace native
{
namespace handles
{

struct CPopType_vftable;
struct CPopType;

struct CPopType
{
	CPopType_vftable *vtable;
	uint32_t field1_0x4;
	basic_string<char> name;
	uint8_t field3_0x24;
	uint8_t field4_0x25;
	uint8_t field5_0x26;
	uint8_t field6_0x27;
	int id;
	bool allowedToVote;
	uint8_t field9_0x2d;
	uint8_t field10_0x2e;
	uint8_t field11_0x2f;
	int field12_0x30;
	int mergeMaxSize;
	int sprite;
	PopStrata strata;
	bool allowUnemployment__;
	bool canReduceConsciousness;
	bool canBeRecruited;
	uint8_t field19_0x43;
	uint8_t field20_0x44;
	uint8_t field21_0x45;
	uint8_t field22_0x46;
	uint8_t field23_0x47;
	uint8_t field24_0x48;
	uint8_t field25_0x49;
	uint8_t field26_0x4a;
	uint8_t field27_0x4b;
	uint8_t field28_0x4c;
	uint8_t field29_0x4d;
	uint8_t field30_0x4e;
	uint8_t field31_0x4f;
	bool isFactoryWorker;
	bool isRgoWorker;
	uint8_t field34_0x52;
	uint8_t field35_0x53;
	CFixedPoint workplaceOutput;
	CFixedPoint workplaceInput;
	uint8_t field38_0x5c;
	uint8_t field39_0x5d;
	uint8_t field40_0x5e;
	uint8_t field41_0x5f;
	CFixedPoint64 researchPoints;
	CFixedPoint64 researchOptimum;
	vector<void *> issues;
	vector<CMeanTimeToHappen> ideologies;
	CMeanTimeToHappen field46_0x90;
	CMeanTimeToHappen countryMigrationTarget;
	vector<void *> promoteTo;
	uint8_t field49_0xd8;
	uint8_t field50_0xd9;
	uint8_t field51_0xda;
	uint8_t field52_0xdb;
	uint8_t field53_0xdc;
	uint8_t field54_0xdd;
	uint8_t field55_0xde;
	uint8_t field56_0xdf;
	uint8_t field57_0xe0;
	uint8_t field58_0xe1;
	uint8_t field59_0xe2;
	uint8_t field60_0xe3;
	uint8_t field61_0xe4;
	uint8_t field62_0xe5;
	uint8_t field63_0xe6;
	uint8_t field64_0xe7;
	CColor color;
	uint8_t field66_0x104;
	uint8_t field67_0x105;
	uint8_t field68_0x106;
	uint8_t field69_0x107;
	CFixedPoint64 startedShare;
	CGoodsPool lifeNeeds;
	CGoodsPool everydayNeeds;
	CGoodsPool luxuryNeeds;
	CGoodsPool field74_0x218;
	CGoodsPool field75_0x270;
	CGoodsPool field76_0x2c8;
	uint8_t field77_0x320;
	uint8_t field78_0x321;
	uint8_t field79_0x322;
	uint8_t field80_0x323;
	uint8_t field81_0x324;
	uint8_t field82_0x325;
	uint8_t field83_0x326;
	uint8_t field84_0x327;
	uint8_t field85_0x328;
	uint8_t field86_0x329;
	uint8_t field87_0x32a;
	uint8_t field88_0x32b;
	uint8_t field89_0x32c;
	uint8_t field90_0x32d;
	uint8_t field91_0x32e;
	uint8_t field92_0x32f;
	uint8_t field93_0x330;
	uint8_t field94_0x331;
	uint8_t field95_0x332;
	uint8_t field96_0x333;
	uint8_t field97_0x334;
	uint8_t field98_0x335;
	uint8_t field99_0x336;
	uint8_t field100_0x337;
	CPopIncome lifeNeedsIncome;
	uint8_t field102_0x354;
	uint8_t field103_0x355;
	uint8_t field104_0x356;
	uint8_t field105_0x357;
	CPopIncome everydayNeedsIncome;
	uint8_t field107_0x374;
	uint8_t field108_0x375;
	uint8_t field109_0x376;
	uint8_t field110_0x377;
	CPopIncome luxuryNeedsIncome;
	uint8_t field112_0x394;
	uint8_t field113_0x395;
	uint8_t field114_0x396;
	uint8_t field115_0x397;
	uint8_t field116_0x398;
	uint8_t field117_0x399;
	uint8_t field118_0x39a;
	uint8_t field119_0x39b;
	uint8_t field120_0x39c;
	uint8_t field121_0x39d;
	uint8_t field122_0x39e;
	uint8_t field123_0x39f;
	uint8_t field124_0x3a0;
	uint8_t field125_0x3a1;
	uint8_t field126_0x3a2;
	uint8_t field127_0x3a3;
	uint8_t field128_0x3a4;
	uint8_t field129_0x3a5;
	uint8_t field130_0x3a6;
	uint8_t field131_0x3a7;
	uint8_t field132_0x3a8;
	uint8_t field133_0x3a9;
	uint8_t field134_0x3aa;
	uint8_t field135_0x3ab;
	uint8_t field136_0x3ac;
	uint8_t field137_0x3ad;
	uint8_t field138_0x3ae;
	uint8_t field139_0x3af;
	uint32_t field140_0x3b0;
	unsigned int field141_0x3b4;
	uint8_t field142_0x3b8;
	uint8_t field143_0x3b9;
	uint8_t field144_0x3ba;
	uint8_t field145_0x3bb;
	uint8_t field146_0x3bc;
	uint8_t field147_0x3bd;
	uint8_t field148_0x3be;
	uint8_t field149_0x3bf;
	uint8_t field150_0x3c0;
	uint8_t field151_0x3c1;
	uint8_t field152_0x3c2;
	uint8_t field153_0x3c3;
	uint8_t field154_0x3c4;
	uint8_t field155_0x3c5;
	uint8_t field156_0x3c6;
	uint8_t field157_0x3c7;
	int minimumPromotion;
	uint8_t field159_0x3cc;
	uint8_t field160_0x3cd;
	uint8_t field161_0x3ce;
	uint8_t field162_0x3cf;
	uint8_t field163_0x3d0;
	uint8_t field164_0x3d1;
	uint8_t field165_0x3d2;
	uint8_t field166_0x3d3;
	CPopType *equivalent;
	bool demoteMigrant;
	bool isSlave;
	bool canBuild;
	bool givesAdminEfficiency;
	vector<CFixedPoint> rebelSubUnits;
	bool stateCapitalOnly;
	uint8_t field174_0x3ed;
	uint8_t field175_0x3ee;
	uint8_t field176_0x3ef;
};

}
}
}

#pragma pack(pop)

#endif // HANDLES_CPOPTYPE_HPP_
