#ifndef HANDLES_CNATIONALVALUE_HPP_
#define HANDLES_CNATIONALVALUE_HPP_

#include <cstdint>
#include <handles/basic_string.hpp>
#include <handles/CModifierEntry.hpp>
#include <handles/vector.hpp>

#pragma pack(push, 1)

namespace smedley
{
namespace handles
{

struct CNationalValue
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
	vector<CModifierEntry> entries;
	int icon;
	uint8_t field23_0x2c;
	uint8_t field24_0x2d;
	uint8_t field25_0x2e;
	uint8_t field26_0x2f;
	basic_string<char> name;
	uint8_t field28_0x4c;
	uint8_t field29_0x4d;
	uint8_t field30_0x4e;
	uint8_t field31_0x4f;
};

}
}

#pragma pack(pop)

#endif // HANDLES_CNATIONALVALUE_HPP_
