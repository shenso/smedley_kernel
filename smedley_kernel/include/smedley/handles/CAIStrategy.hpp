#ifndef HANDLES_CAISTRATEGY_HPP_
#define HANDLES_CAISTRATEGY_HPP_

#include <cstdint>
#include "CCountryTag.hpp"
#include "CList.hpp"

#pragma pack(push, 1)

namespace smedley
{
namespace handles
{

struct CCountryValue;

struct CAIStrategy
{
	uint8_t **vtable;
	uint32_t field1_0x4;
	CCountryTag tag;
	uint8_t **field3_0x10;
	uint32_t field4_0x14;
	uint8_t field5_0x18;
	bool isStatic;
	bool consolidate;
	uint8_t field8_0x1b;
	uint32_t field9_0x1c;
	uint8_t **field10_0x20;
	uint32_t field11_0x24;
	uint8_t **field12_0x28;
	uint8_t field13_0x2c;
	uint8_t field14_0x2d;
	uint8_t field15_0x2e;
	uint8_t field16_0x2f;
	uint8_t **field17_0x30;
	uint32_t field18_0x34;
	uint8_t **field19_0x38;
	uint8_t field20_0x3c;
	uint8_t field21_0x3d;
	uint8_t field22_0x3e;
	uint8_t field23_0x3f;
	CList<CCountryValue *> threats;
	uint8_t **field25_0x50;
	int field26_0x54;
	uint8_t **field27_0x58;
	CList<CCountryValue *> rivals;
	uint32_t field29_0x6c;
	uint8_t **field30_0x70;
	uint32_t field31_0x74;
	CList<CCountryValue *> antagonize;
	uint8_t **field33_0x88;
	int field34_0x8c;
	uint8_t **field35_0x90;
	CList<CCountryValue *> befriend;
	uint32_t field37_0xa4;
	uint8_t **field38_0xa8;
	uint32_t field39_0xac;
	CList<CCountryValue *> vassalize;
	uint8_t **field41_0xc0;
	int field42_0xc4;
	uint8_t **field43_0xc8;
	CList<CCountryValue *> access;
	uint32_t field45_0xdc;
	uint8_t **field46_0xe0;
	uint32_t field47_0xe4;
	CList<CCountryValue *> protect;
	uint8_t **field49_0xf8;
	int field50_0xfc;
	uint8_t **field51_0x100;
	CList<CCountryValue *> pinatas;
	uint32_t field53_0x114;
	uint8_t **field54_0x118;
	uint32_t field55_0x11c;
	uint8_t **field56_0x120;
	int field57_0x124;
	uint8_t **field58_0x128;
	uint8_t field59_0x12c;
	uint8_t field60_0x12d;
	uint8_t field61_0x12e;
	uint8_t field62_0x12f;
	uint8_t **field63_0x130;
	uint32_t field64_0x134;
	uint8_t **field65_0x138;
	uint8_t field66_0x13c;
	uint8_t field67_0x13d;
	uint8_t field68_0x13e;
	uint8_t field69_0x13f;
	CList<CCountryValue *> warTargets;
	int status;
	uint32_t field72_0x154;
};

}
}

#pragma pack(pop)

#endif // HANDLES_CAISTRATEGY_HPP_
