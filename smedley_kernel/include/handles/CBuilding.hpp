#ifndef HANDLES_CBUILDING_HPP_
#define HANDLES_CBUILDING_HPP_

#include <cstdint>
#include <handles/CGoodsPool.hpp>
#include <handles/_*.hpp>
#include <handles/CList.hpp>
#include <handles/vector.hpp>
#include <handles/CFixedPoint.hpp>

#pragma pack(push, 1)

namespace smedley
{
namespace handles
{

struct CModifierDefinition;
struct CProductionType;
struct _;

struct CBuilding
{
	void **vftable;
	uint8_t field1_0x4;
	uint8_t field2_0x5;
	uint8_t field3_0x6;
	uint8_t field4_0x7;
	CFixedPoint field5_0x8;
	CModifierDefinition * field6_0xc;
	int type;
	uint8_t field8_0x14;
	uint8_t field9_0x15;
	uint8_t field10_0x16;
	uint8_t field11_0x17;
	uint8_t field12_0x18;
	uint8_t field13_0x19;
	uint8_t field14_0x1a;
	uint8_t field15_0x1b;
	uint8_t field16_0x1c;
	uint8_t field17_0x1d;
	uint8_t field18_0x1e;
	uint8_t field19_0x1f;
	uint8_t field20_0x20;
	uint8_t field21_0x21;
	uint8_t field22_0x22;
	uint8_t field23_0x23;
	uint8_t field24_0x24;
	uint8_t field25_0x25;
	uint8_t field26_0x26;
	uint8_t field27_0x27;
	uint8_t field28_0x28;
	uint8_t field29_0x29;
	uint8_t field30_0x2a;
	uint8_t field31_0x2b;
	uint8_t field32_0x2c;
	uint8_t field33_0x2d;
	uint8_t field34_0x2e;
	uint8_t field35_0x2f;
	uint8_t field36_0x30;
	uint8_t field37_0x31;
	uint8_t field38_0x32;
	uint8_t field39_0x33;
	uint8_t field40_0x34;
	uint8_t field41_0x35;
	uint8_t field42_0x36;
	uint8_t field43_0x37;
	uint8_t field44_0x38;
	uint8_t field45_0x39;
	uint8_t field46_0x3a;
	uint8_t field47_0x3b;
	uint8_t field48_0x3c;
	uint8_t field49_0x3d;
	uint8_t field50_0x3e;
	uint8_t field51_0x3f;
	uint8_t field52_0x40;
	uint8_t field53_0x41;
	uint8_t field54_0x42;
	uint8_t field55_0x43;
	uint8_t field56_0x44;
	uint8_t field57_0x45;
	uint8_t field58_0x46;
	uint8_t field59_0x47;
	uint8_t field60_0x48;
	uint8_t field61_0x49;
	uint8_t field62_0x4a;
	uint8_t field63_0x4b;
	uint8_t field64_0x4c;
	uint8_t field65_0x4d;
	uint8_t field66_0x4e;
	uint8_t field67_0x4f;
	uint8_t field68_0x50;
	uint8_t field69_0x51;
	uint8_t field70_0x52;
	uint8_t field71_0x53;
	uint8_t field72_0x54;
	uint8_t field73_0x55;
	uint8_t field74_0x56;
	uint8_t field75_0x57;
	uint8_t field76_0x58;
	uint8_t field77_0x59;
	uint8_t field78_0x5a;
	uint8_t field79_0x5b;
	CFixedPoint constructionCost;
	CGoodsPool goodsCost;
	int daysToBuild;
	bool capitalOnly__;
	bool isPort;
	bool onePerState;
	uint8_t field86_0xbf;
	uint8_t field87_0xc0;
	uint8_t field88_0xc1;
	uint8_t field89_0xc2;
	uint8_t field90_0xc3;
	int maxLevel;
	vector<int> colonialPoints;
	bool producesSailBoats;
	bool producesSteamBoats;
	uint8_t field95_0xda;
	uint8_t field96_0xdb;
	CFixedPoint colonialRange;
	bool isOnMap;
	bool isVisible;
	uint8_t field100_0xe2;
	uint8_t field101_0xe3;
	uint8_t field102_0xe4;
	uint8_t field103_0xe5;
	uint8_t field104_0xe6;
	uint8_t field105_0xe7;
	uint8_t field106_0xe8;
	uint8_t field107_0xe9;
	uint8_t field108_0xea;
	uint8_t field109_0xeb;
	uint8_t field110_0xec;
	uint8_t field111_0xed;
	uint8_t field112_0xee;
	uint8_t field113_0xef;
	uint8_t field114_0xf0;
	uint8_t field115_0xf1;
	uint8_t field116_0xf2;
	uint8_t field117_0xf3;
	uint8_t field118_0xf4;
	uint8_t field119_0xf5;
	uint8_t field120_0xf6;
	uint8_t field121_0xf7;
	CList<basic_string<char>_*> prerequisites;
	uint8_t field123_0x108;
	uint8_t field124_0x109;
	uint8_t field125_0x10a;
	uint8_t field126_0x10b;
	uint8_t field127_0x10c;
	uint8_t field128_0x10d;
	uint8_t field129_0x10e;
	uint8_t field130_0x10f;
	uint8_t field131_0x110;
	uint8_t field132_0x111;
	uint8_t field133_0x112;
	uint8_t field134_0x113;
	uint8_t field135_0x114;
	uint8_t field136_0x115;
	uint8_t field137_0x116;
	uint8_t field138_0x117;
	CList<basic_string<char>_*> notIfAlreadyExists;
	bool confirm;
	bool orientation;
	uint8_t field142_0x12a;
	uint8_t field143_0x12b;
	CProductionType * upgradeType__;
	bool defaultEnabled;
	bool isProvinceBuilding;
	uint8_t field147_0x132;
	uint8_t field148_0x133;
	int index__;
	bool popsCanBuild;
	bool spawnsRailways;
	bool isAdvancedFactory;
	uint8_t field153_0x13b;
	CFixedPoint infastructure;
};

}
}

#pragma pack(pop)

#endif // HANDLES_CBUILDING_HPP_
