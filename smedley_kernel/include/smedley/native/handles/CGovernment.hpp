#ifndef HANDLES_CGOVERNMENT_HPP_
#define HANDLES_CGOVERNMENT_HPP_

#include <cstdint>
#include "basic_string.hpp"
#include "CList.hpp"

#pragma pack(push, 1)

namespace smedley
{
namespace native
{
namespace handles
{

struct CGovernment
{
	void **vftable;
	uint8_t field1_0x4;
	uint8_t field2_0x5;
	uint8_t field3_0x6;
	uint8_t field4_0x7;
	int duration;
	bool appointRulingParty;
	uint8_t field7_0xd;
	uint8_t field8_0xe;
	uint8_t field9_0xf;
	CList<void *> field10_0x10;
	uint8_t field11_0x20;
	uint8_t field12_0x21;
	uint8_t field13_0x22;
	uint8_t field14_0x23;
	basic_string<char> name;
	int id;
	bool validForNewCountry;
	uint8_t field18_0x45;
	uint8_t field19_0x46;
	uint8_t field20_0x47;
	uint8_t field21_0x48;
	uint8_t field22_0x49;
	uint8_t field23_0x4a;
	uint8_t field24_0x4b;
	uint8_t field25_0x4c;
	uint8_t field26_0x4d;
	uint8_t field27_0x4e;
	uint8_t field28_0x4f;
	uint8_t field29_0x50;
	uint8_t field30_0x51;
	uint8_t field31_0x52;
	uint8_t field32_0x53;
	uint8_t field33_0x54;
	uint8_t field34_0x55;
	uint8_t field35_0x56;
	uint8_t field36_0x57;
	uint8_t field37_0x58;
	uint8_t field38_0x59;
	uint8_t field39_0x5a;
	uint8_t field40_0x5b;
	bool election;
	uint8_t field42_0x5d;
	uint8_t field43_0x5e;
	uint8_t field44_0x5f;
	basic_string<char> flagType;
};

}
}
}

#pragma pack(pop)

#endif // HANDLES_CGOVERNMENT_HPP_
