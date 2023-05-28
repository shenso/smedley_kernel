#ifndef HANDLES_CSTATE_HPP_
#define HANDLES_CSTATE_HPP_

#include <cstdint>
#include "CCountryTag.hpp"
#include "CGoodsPool.hpp"
#include "CModifier.hpp"
#include "CStateBuilding.hpp"
#include "ObjectReference.hpp"
#include "CList.hpp"
#include "CFixedPoint64.hpp"
#include "vector.hpp"
#include "CFixedPoint.hpp"

#pragma pack(push, 1)

namespace smedley
{
namespace handles
{

struct CProvinceTemplate;
struct CState;

struct CState
{
	void **CReferenceObject_vftable;
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
	void **CSelectable_vftable;
	uint8_t field39_0x34;
	uint8_t field40_0x35;
	uint8_t field41_0x36;
	uint8_t field42_0x37;
	CList<void *> modifiers;
	vector<int> provinces;
	CCountryTag owner__;
	CList<CStateBuilding> buildings;
	uint8_t field47_0x70;
	uint8_t field48_0x71;
	uint8_t field49_0x72;
	uint8_t field50_0x73;
	uint8_t field51_0x74;
	uint8_t field52_0x75;
	uint8_t field53_0x76;
	uint8_t field54_0x77;
	uint8_t field55_0x78;
	uint8_t field56_0x79;
	uint8_t field57_0x7a;
	uint8_t field58_0x7b;
	uint8_t field59_0x7c;
	uint8_t field60_0x7d;
	uint8_t field61_0x7e;
	uint8_t field62_0x7f;
	bool slaveryAllowed;
	uint8_t field64_0x81;
	uint8_t field65_0x82;
	uint8_t field66_0x83;
	int colonial;
	CModifier field68_0x88;
	uint8_t field69_0xb8;
	uint8_t field70_0xb9;
	uint8_t field71_0xba;
	uint8_t field72_0xbb;
	uint8_t field73_0xbc;
	uint8_t field74_0xbd;
	uint8_t field75_0xbe;
	uint8_t field76_0xbf;
	uint8_t field77_0xc0;
	uint8_t field78_0xc1;
	uint8_t field79_0xc2;
	uint8_t field80_0xc3;
	uint8_t field81_0xc4;
	uint8_t field82_0xc5;
	uint8_t field83_0xc6;
	uint8_t field84_0xc7;
	int popCount;
	uint8_t field86_0xcc;
	uint8_t field87_0xcd;
	uint8_t field88_0xce;
	uint8_t field89_0xcf;
	uint8_t field90_0xd0;
	uint8_t field91_0xd1;
	uint8_t field92_0xd2;
	uint8_t field93_0xd3;
	uint8_t field94_0xd4;
	uint8_t field95_0xd5;
	uint8_t field96_0xd6;
	uint8_t field97_0xd7;
	uint8_t field98_0xd8;
	uint8_t field99_0xd9;
	uint8_t field100_0xda;
	uint8_t field101_0xdb;
	uint8_t field102_0xdc;
	uint8_t field103_0xdd;
	uint8_t field104_0xde;
	uint8_t field105_0xdf;
	uint8_t field106_0xe0;
	uint8_t field107_0xe1;
	uint8_t field108_0xe2;
	uint8_t field109_0xe3;
	uint8_t field110_0xe4;
	uint8_t field111_0xe5;
	uint8_t field112_0xe6;
	uint8_t field113_0xe7;
	uint8_t field114_0xe8;
	uint8_t field115_0xe9;
	uint8_t field116_0xea;
	uint8_t field117_0xeb;
	uint8_t field118_0xec;
	uint8_t field119_0xed;
	uint8_t field120_0xee;
	uint8_t field121_0xef;
	uint8_t field122_0xf0;
	uint8_t field123_0xf1;
	uint8_t field124_0xf2;
	uint8_t field125_0xf3;
	uint8_t field126_0xf4;
	uint8_t field127_0xf5;
	uint8_t field128_0xf6;
	uint8_t field129_0xf7;
	uint8_t field130_0xf8;
	uint8_t field131_0xf9;
	uint8_t field132_0xfa;
	uint8_t field133_0xfb;
	uint8_t field134_0xfc;
	uint8_t field135_0xfd;
	uint8_t field136_0xfe;
	uint8_t field137_0xff;
	uint8_t field138_0x100;
	uint8_t field139_0x101;
	uint8_t field140_0x102;
	uint8_t field141_0x103;
	uint8_t field142_0x104;
	uint8_t field143_0x105;
	uint8_t field144_0x106;
	uint8_t field145_0x107;
	uint8_t field146_0x108;
	uint8_t field147_0x109;
	uint8_t field148_0x10a;
	uint8_t field149_0x10b;
	uint8_t field150_0x10c;
	uint8_t field151_0x10d;
	uint8_t field152_0x10e;
	uint8_t field153_0x10f;
	uint8_t field154_0x110;
	uint8_t field155_0x111;
	uint8_t field156_0x112;
	uint8_t field157_0x113;
	uint8_t field158_0x114;
	uint8_t field159_0x115;
	uint8_t field160_0x116;
	uint8_t field161_0x117;
	uint8_t field162_0x118;
	uint8_t field163_0x119;
	uint8_t field164_0x11a;
	uint8_t field165_0x11b;
	uint8_t field166_0x11c;
	uint8_t field167_0x11d;
	uint8_t field168_0x11e;
	uint8_t field169_0x11f;
	uint8_t field170_0x120;
	uint8_t field171_0x121;
	uint8_t field172_0x122;
	uint8_t field173_0x123;
	uint8_t field174_0x124;
	uint8_t field175_0x125;
	uint8_t field176_0x126;
	uint8_t field177_0x127;
	uint8_t field178_0x128;
	uint8_t field179_0x129;
	uint8_t field180_0x12a;
	uint8_t field181_0x12b;
	uint8_t field182_0x12c;
	uint8_t field183_0x12d;
	uint8_t field184_0x12e;
	uint8_t field185_0x12f;
	uint8_t field186_0x130;
	uint8_t field187_0x131;
	uint8_t field188_0x132;
	uint8_t field189_0x133;
	uint8_t field190_0x134;
	uint8_t field191_0x135;
	uint8_t field192_0x136;
	uint8_t field193_0x137;
	uint8_t field194_0x138;
	uint8_t field195_0x139;
	uint8_t field196_0x13a;
	uint8_t field197_0x13b;
	uint8_t field198_0x13c;
	uint8_t field199_0x13d;
	uint8_t field200_0x13e;
	uint8_t field201_0x13f;
	uint8_t field202_0x140;
	uint8_t field203_0x141;
	uint8_t field204_0x142;
	uint8_t field205_0x143;
	uint8_t field206_0x144;
	uint8_t field207_0x145;
	uint8_t field208_0x146;
	uint8_t field209_0x147;
	uint8_t field210_0x148;
	uint8_t field211_0x149;
	uint8_t field212_0x14a;
	uint8_t field213_0x14b;
	uint8_t field214_0x14c;
	uint8_t field215_0x14d;
	uint8_t field216_0x14e;
	uint8_t field217_0x14f;
	uint8_t field218_0x150;
	uint8_t field219_0x151;
	uint8_t field220_0x152;
	uint8_t field221_0x153;
	uint8_t field222_0x154;
	uint8_t field223_0x155;
	uint8_t field224_0x156;
	uint8_t field225_0x157;
	uint8_t field226_0x158;
	uint8_t field227_0x159;
	uint8_t field228_0x15a;
	uint8_t field229_0x15b;
	uint8_t field230_0x15c;
	uint8_t field231_0x15d;
	uint8_t field232_0x15e;
	uint8_t field233_0x15f;
	uint8_t field234_0x160;
	uint8_t field235_0x161;
	uint8_t field236_0x162;
	uint8_t field237_0x163;
	uint8_t field238_0x164;
	uint8_t field239_0x165;
	uint8_t field240_0x166;
	uint8_t field241_0x167;
	uint8_t field242_0x168;
	uint8_t field243_0x169;
	uint8_t field244_0x16a;
	uint8_t field245_0x16b;
	uint8_t field246_0x16c;
	uint8_t field247_0x16d;
	uint8_t field248_0x16e;
	uint8_t field249_0x16f;
	uint8_t field250_0x170;
	uint8_t field251_0x171;
	uint8_t field252_0x172;
	uint8_t field253_0x173;
	uint8_t field254_0x174;
	uint8_t field255_0x175;
	uint8_t field256_0x176;
	uint8_t field257_0x177;
	uint8_t field258_0x178;
	uint8_t field259_0x179;
	uint8_t field260_0x17a;
	uint8_t field261_0x17b;
	uint8_t field262_0x17c;
	uint8_t field263_0x17d;
	uint8_t field264_0x17e;
	uint8_t field265_0x17f;
	uint8_t field266_0x180;
	uint8_t field267_0x181;
	uint8_t field268_0x182;
	uint8_t field269_0x183;
	uint8_t field270_0x184;
	uint8_t field271_0x185;
	uint8_t field272_0x186;
	uint8_t field273_0x187;
	uint8_t field274_0x188;
	uint8_t field275_0x189;
	uint8_t field276_0x18a;
	uint8_t field277_0x18b;
	uint8_t field278_0x18c;
	uint8_t field279_0x18d;
	uint8_t field280_0x18e;
	uint8_t field281_0x18f;
	uint8_t field282_0x190;
	uint8_t field283_0x191;
	uint8_t field284_0x192;
	uint8_t field285_0x193;
	uint8_t field286_0x194;
	uint8_t field287_0x195;
	uint8_t field288_0x196;
	uint8_t field289_0x197;
	uint8_t field290_0x198;
	uint8_t field291_0x199;
	uint8_t field292_0x19a;
	uint8_t field293_0x19b;
	uint8_t field294_0x19c;
	uint8_t field295_0x19d;
	uint8_t field296_0x19e;
	uint8_t field297_0x19f;
	uint8_t field298_0x1a0;
	uint8_t field299_0x1a1;
	uint8_t field300_0x1a2;
	uint8_t field301_0x1a3;
	uint8_t field302_0x1a4;
	uint8_t field303_0x1a5;
	uint8_t field304_0x1a6;
	uint8_t field305_0x1a7;
	uint8_t field306_0x1a8;
	uint8_t field307_0x1a9;
	uint8_t field308_0x1aa;
	uint8_t field309_0x1ab;
	uint8_t field310_0x1ac;
	uint8_t field311_0x1ad;
	uint8_t field312_0x1ae;
	uint8_t field313_0x1af;
	uint8_t field314_0x1b0;
	uint8_t field315_0x1b1;
	uint8_t field316_0x1b2;
	uint8_t field317_0x1b3;
	uint8_t field318_0x1b4;
	uint8_t field319_0x1b5;
	uint8_t field320_0x1b6;
	uint8_t field321_0x1b7;
	uint8_t field322_0x1b8;
	uint8_t field323_0x1b9;
	uint8_t field324_0x1ba;
	uint8_t field325_0x1bb;
	uint8_t field326_0x1bc;
	uint8_t field327_0x1bd;
	uint8_t field328_0x1be;
	uint8_t field329_0x1bf;
	uint8_t field330_0x1c0;
	uint8_t field331_0x1c1;
	uint8_t field332_0x1c2;
	uint8_t field333_0x1c3;
	uint8_t field334_0x1c4;
	uint8_t field335_0x1c5;
	uint8_t field336_0x1c6;
	uint8_t field337_0x1c7;
	uint8_t popProject;
	uint8_t field339_0x1c9;
	uint8_t field340_0x1ca;
	uint8_t field341_0x1cb;
	uint8_t field342_0x1cc;
	uint8_t field343_0x1cd;
	uint8_t field344_0x1ce;
	uint8_t field345_0x1cf;
	CGoodsPool field346_0x1d0;
	uint8_t field347_0x228;
	uint8_t field348_0x229;
	uint8_t field349_0x22a;
	uint8_t field350_0x22b;
	uint8_t field351_0x22c;
	uint8_t field352_0x22d;
	uint8_t field353_0x22e;
	uint8_t field354_0x22f;
	uint8_t field355_0x230;
	uint8_t field356_0x231;
	uint8_t field357_0x232;
	uint8_t field358_0x233;
	CState * field359_0x234;
	uint8_t field360_0x238;
	uint8_t field361_0x239;
	uint8_t field362_0x23a;
	uint8_t field363_0x23b;
	uint8_t field364_0x23c;
	uint8_t field365_0x23d;
	uint8_t field366_0x23e;
	uint8_t field367_0x23f;
	uint8_t field368_0x240;
	uint8_t field369_0x241;
	uint8_t field370_0x242;
	uint8_t field371_0x243;
	uint8_t field372_0x244;
	uint8_t field373_0x245;
	uint8_t field374_0x246;
	uint8_t field375_0x247;
	uint8_t field376_0x248;
	uint8_t field377_0x249;
	uint8_t field378_0x24a;
	uint8_t field379_0x24b;
	uint8_t field380_0x24c;
	uint8_t field381_0x24d;
	uint8_t field382_0x24e;
	uint8_t field383_0x24f;
	CProvinceTemplate * template__;
	uint8_t field385_0x254;
	uint8_t field386_0x255;
	uint8_t field387_0x256;
	uint8_t field388_0x257;
	CFixedPoint64 savingsInBank;
	CFixedPoint64 interestPayments;
	uint8_t field391_0x268;
	uint8_t field392_0x269;
	uint8_t field393_0x26a;
	uint8_t field394_0x26b;
	uint8_t field395_0x26c;
	uint8_t field396_0x26d;
	uint8_t field397_0x26e;
	uint8_t field398_0x26f;
	uint8_t field399_0x270;
	uint8_t field400_0x271;
	uint8_t field401_0x272;
	uint8_t field402_0x273;
	uint8_t field403_0x274;
	uint8_t field404_0x275;
	uint8_t field405_0x276;
	uint8_t field406_0x277;
	uint8_t field407_0x278;
	uint8_t field408_0x279;
	uint8_t field409_0x27a;
	uint8_t field410_0x27b;
	bool isFlashpoint;
	uint8_t field412_0x27d;
	uint8_t field413_0x27e;
	uint8_t field414_0x27f;
	CFixedPoint tension;
	CCountryTag crisisTag__;
	uint8_t field417_0x28c;
	uint8_t field418_0x28d;
	uint8_t field419_0x28e;
	uint8_t field420_0x28f;
};

}
}

#pragma pack(pop)

#endif // HANDLES_CSTATE_HPP_
