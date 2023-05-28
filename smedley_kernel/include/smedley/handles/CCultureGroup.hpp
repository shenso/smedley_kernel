#ifndef HANDLES_CCULTUREGROUP_HPP_
#define HANDLES_CCULTUREGROUP_HPP_

#include <cstdint>
#include "CCountryTag.hpp"
#include "basic_string.hpp"
#include "CList.hpp"
#include "vector.hpp"

#pragma pack(push, 1)

namespace smedley
{
namespace handles
{

struct CCulture;

struct CCultureGroup
{
	void *vftable;
	uint32_t __padding;
	CList<CCulture *> cultures;
	bool isOverseas;
	uint8_t field4_0x19;
	uint8_t field5_0x1a;
	uint8_t field6_0x1b;
	CCountryTag unionLeader__;
	basic_string<char> name__;
	basic_string<char> label__;
	uint8_t field10_0x5c;
	uint8_t field11_0x5d;
	uint8_t field12_0x5e;
	uint8_t field13_0x5f;
	uint8_t field14_0x60;
	uint8_t field15_0x61;
	uint8_t field16_0x62;
	uint8_t field17_0x63;
	uint8_t field18_0x64;
	uint8_t field19_0x65;
	uint8_t field20_0x66;
	uint8_t field21_0x67;
	uint8_t field22_0x68;
	uint8_t field23_0x69;
	uint8_t field24_0x6a;
	uint8_t field25_0x6b;
	uint8_t field26_0x6c;
	uint8_t field27_0x6d;
	uint8_t field28_0x6e;
	uint8_t field29_0x6f;
	uint8_t field30_0x70;
	uint8_t field31_0x71;
	uint8_t field32_0x72;
	uint8_t field33_0x73;
	uint8_t field34_0x74;
	uint8_t field35_0x75;
	uint8_t field36_0x76;
	uint8_t field37_0x77;
	uint8_t field38_0x78;
	uint8_t field39_0x79;
	uint8_t field40_0x7a;
	uint8_t field41_0x7b;
	basic_string<char> unit;
	basic_string<char> unionTagStr;
	vector<basic_string<char>> firstNames;
	vector<basic_string<char>> lastNames;
	basic_string<char> leader;
	uint8_t field47_0xf0;
	uint8_t field48_0xf1;
	uint8_t field49_0xf2;
	uint8_t field50_0xf3;
	uint8_t field51_0xf4;
	uint8_t field52_0xf5;
	uint8_t field53_0xf6;
	uint8_t field54_0xf7;
};

}
}

#pragma pack(pop)

#endif // HANDLES_CCULTUREGROUP_HPP_
