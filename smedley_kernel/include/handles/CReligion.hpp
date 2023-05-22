#ifndef HANDLES_CRELIGION_HPP_
#define HANDLES_CRELIGION_HPP_

#include <cstdint>
#include <handles/basic_string.hpp>
#include <handles/CColor.hpp>

#pragma pack(push, 1)

namespace smedley
{
namespace handles
{

struct CReligionGroup;

struct CReligion
{
	void *vtable;
	uint32_t field1_0x4;
	unsigned int field2_0x8;
	uint32_t field3_0xc;
	basic_string<char> name;
	basic_string<char> label;
	uint8_t field6_0x48;
	uint8_t field7_0x49;
	uint8_t field8_0x4a;
	uint8_t field9_0x4b;
	CReligionGroup * group;
	CColor color;
	bool isPagan;
	uint8_t field13_0x6d;
	uint8_t field14_0x6e;
	uint8_t field15_0x6f;
	int icon;
};

}
}

#pragma pack(pop)

#endif // HANDLES_CRELIGION_HPP_
