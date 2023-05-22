#ifndef HANDLES_CSUBUNIT_HPP_
#define HANDLES_CSUBUNIT_HPP_

#include <cstdint>
#include <handles/CCountryTag.hpp>
#include <handles/basic_string.hpp>
#include <handles/ObjectReference.hpp>
#include <handles/CFixedPoint.hpp>

#pragma pack(push, 1)

namespace smedley
{
namespace handles
{

struct CSubUnitDefinition;
struct CPop;

struct CSubUnit
{
	void **vftable;
	uint32_t field1_0x4;
	ObjectReference ref;
	bool isRegistered__;
	uint8_t field4_0x11;
	uint8_t field5_0x12;
	uint8_t field6_0x13;
	uint8_t field7_0x14;
	uint8_t field8_0x15;
	uint8_t field9_0x16;
	uint8_t field10_0x17;
	uint8_t field11_0x18;
	uint8_t field12_0x19;
	uint8_t field13_0x1a;
	uint8_t field14_0x1b;
	uint8_t field15_0x1c;
	uint8_t field16_0x1d;
	uint8_t field17_0x1e;
	uint8_t field18_0x1f;
	uint8_t field19_0x20;
	uint8_t field20_0x21;
	uint8_t field21_0x22;
	uint8_t field22_0x23;
	uint8_t field23_0x24;
	uint8_t field24_0x25;
	uint8_t field25_0x26;
	uint8_t field26_0x27;
	uint8_t field27_0x28;
	uint8_t field28_0x29;
	uint8_t field29_0x2a;
	uint8_t field30_0x2b;
	uint8_t field31_0x2c;
	uint8_t field32_0x2d;
	uint8_t field33_0x2e;
	uint8_t field34_0x2f;
	CPop * pop;
	CFixedPoint experience;
	CSubUnitDefinition * def;
	CFixedPoint strength;
	CFixedPoint organization;
	basic_string<char> name;
	CCountryTag tag__;
	int home;
	uint8_t field43_0x6c;
	uint8_t field44_0x6d;
	uint8_t field45_0x6e;
	uint8_t field46_0x6f;
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
	uint8_t field63_0x80;
	uint8_t field64_0x81;
	uint8_t field65_0x82;
	uint8_t field66_0x83;
	CFixedPoint currentDistance;
	short count__;
	uint8_t field69_0x8a;
	uint8_t field70_0x8b;
};

}
}

#pragma pack(pop)

#endif // HANDLES_CSUBUNIT_HPP_
