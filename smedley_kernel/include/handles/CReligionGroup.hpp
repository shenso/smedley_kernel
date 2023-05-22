#ifndef HANDLES_CRELIGIONGROUP_HPP_
#define HANDLES_CRELIGIONGROUP_HPP_

#include <cstdint>
#include <handles/basic_string.hpp>
#include <handles/CList.hpp>

#pragma pack(push, 1)

namespace smedley
{
namespace handles
{

struct CReligionGroup
{
	void **vftable;
	CList<void *> religions;
	basic_string<char> name;
	uint8_t field3_0x2c;
	uint8_t field4_0x2d;
	uint8_t field5_0x2e;
	uint8_t field6_0x2f;
	uint8_t field7_0x30;
	uint8_t field8_0x31;
	uint8_t field9_0x32;
	uint8_t field10_0x33;
	uint8_t field11_0x34;
	uint8_t field12_0x35;
	uint8_t field13_0x36;
	uint8_t field14_0x37;
	uint8_t field15_0x38;
	uint8_t field16_0x39;
	uint8_t field17_0x3a;
	uint8_t field18_0x3b;
	uint8_t field19_0x3c;
	uint8_t field20_0x3d;
	uint8_t field21_0x3e;
	uint8_t field22_0x3f;
	uint8_t field23_0x40;
	uint8_t field24_0x41;
	uint8_t field25_0x42;
	uint8_t field26_0x43;
	uint8_t field27_0x44;
	uint8_t field28_0x45;
	uint8_t field29_0x46;
	uint8_t field30_0x47;
	uint8_t field31_0x48;
	uint8_t field32_0x49;
	uint8_t field33_0x4a;
	uint8_t field34_0x4b;
};

}
}

#pragma pack(pop)

#endif // HANDLES_CRELIGIONGROUP_HPP_
