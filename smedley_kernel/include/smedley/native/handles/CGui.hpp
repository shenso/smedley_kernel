#ifndef HANDLES_CGUI_HPP_
#define HANDLES_CGUI_HPP_

#include <cstdint>
#include "basic_string.hpp"
#include "vector.hpp"
#include "CGuiTypes.hpp"

#pragma pack(push, 1)

namespace smedley
{
namespace native
{
namespace handles
{

struct CGui_TGui_vftable;

struct CGui
{
	CGui_TGui_vftable *TGui_vftable;
	void *CPersistent_vftable;
	uint32_t field2_0x8;
	void *CFactory_vftable;
	uint8_t field4_0x10;
	uint8_t field5_0x11;
	uint8_t field6_0x12;
	uint8_t field7_0x13;
	basic_string<char> field8_0x14;
	uint32_t someID__;
	CGuiTypes guiTypes;
	uint8_t field11_0x58;
	uint8_t field12_0x59;
	uint8_t field13_0x5a;
	uint8_t field14_0x5b;
	vector<void *> field15_0x5c;
	uint8_t field16_0x6c;
	uint8_t field17_0x6d;
	uint8_t field18_0x6e;
	uint8_t field19_0x6f;
	uint8_t field20_0x70;
	uint8_t field21_0x71;
	uint8_t field22_0x72;
	uint8_t field23_0x73;
	uint8_t field24_0x74;
	uint8_t field25_0x75;
	uint8_t field26_0x76;
	uint8_t field27_0x77;
	uint8_t field28_0x78;
	uint8_t field29_0x79;
	uint8_t field30_0x7a;
	uint8_t field31_0x7b;
	uint8_t field32_0x7c;
	uint8_t field33_0x7d;
	uint8_t field34_0x7e;
	uint8_t field35_0x7f;
	uint8_t field36_0x80;
	uint8_t field37_0x81;
	uint8_t field38_0x82;
	uint8_t field39_0x83;
	uint8_t field40_0x84;
	uint8_t field41_0x85;
	uint8_t field42_0x86;
	uint8_t field43_0x87;
	uint8_t field44_0x88;
	uint8_t field45_0x89;
	uint8_t field46_0x8a;
	uint8_t field47_0x8b;
	uint8_t field48_0x8c;
	uint8_t field49_0x8d;
	uint8_t field50_0x8e;
	uint8_t field51_0x8f;
	uint8_t field52_0x90;
	uint8_t field53_0x91;
	uint8_t field54_0x92;
	uint8_t field55_0x93;
	uint8_t field56_0x94;
	uint8_t field57_0x95;
	uint8_t field58_0x96;
	uint8_t field59_0x97;
	uint8_t field60_0x98;
	uint8_t field61_0x99;
	uint8_t field62_0x9a;
	uint8_t field63_0x9b;
	uint8_t field64_0x9c;
	uint8_t field65_0x9d;
	uint8_t field66_0x9e;
	uint8_t field67_0x9f;
};

}
}
}

#pragma pack(pop)

#endif // HANDLES_CGUI_HPP_
