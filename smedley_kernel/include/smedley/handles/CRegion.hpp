#ifndef HANDLES_CREGION_HPP_
#define HANDLES_CREGION_HPP_

#include <cstdint>
#include "basic_string.hpp"
#include "CList.hpp"
#include "CColonizationData.hpp"
#include "CColor.hpp"

#pragma pack(push, 1)

namespace smedley
{
namespace handles
{

struct CRegion
{
	void **vftable;
	uint8_t field1_0x4;
	uint8_t field2_0x5;
	uint8_t field3_0x6;
	uint8_t field4_0x7;
	CList<void *> provinceIds;
	basic_string<char> name__;
	uint8_t field7_0x34;
	uint8_t field8_0x35;
	uint8_t field9_0x36;
	uint8_t field10_0x37;
	uint8_t field11_0x38;
	uint8_t field12_0x39;
	uint8_t field13_0x3a;
	uint8_t field14_0x3b;
	uint8_t field15_0x3c;
	uint8_t field16_0x3d;
	uint8_t field17_0x3e;
	uint8_t field18_0x3f;
	uint8_t field19_0x40;
	uint8_t field20_0x41;
	uint8_t field21_0x42;
	uint8_t field22_0x43;
	uint8_t field23_0x44;
	uint8_t field24_0x45;
	uint8_t field25_0x46;
	uint8_t field26_0x47;
	uint8_t field27_0x48;
	uint8_t field28_0x49;
	uint8_t field29_0x4a;
	uint8_t field30_0x4b;
	uint8_t field31_0x4c;
	uint8_t field32_0x4d;
	uint8_t field33_0x4e;
	uint8_t field34_0x4f;
	CColor field35_0x50;
	uint8_t field36_0x6c;
	uint8_t field37_0x6d;
	uint8_t field38_0x6e;
	uint8_t field39_0x6f;
	uint8_t field40_0x70;
	uint8_t field41_0x71;
	uint8_t field42_0x72;
	uint8_t field43_0x73;
	CColonizationData colonizationData;
};

}
}

#pragma pack(pop)

#endif // HANDLES_CREGION_HPP_
