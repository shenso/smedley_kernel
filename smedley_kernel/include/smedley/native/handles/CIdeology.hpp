#ifndef HANDLES_CIDEOLOGY_HPP_
#define HANDLES_CIDEOLOGY_HPP_

#include <cstdint>
#include "CAdditiveForUpperHouseMTTH.hpp"
#include "CColor.hpp"
#include "CEU3Date.hpp"

#pragma pack(push, 1)

namespace smedley
{
namespace native
{
namespace handles
{

struct CIdeology
{
	void **vftable;
	uint8_t field1_0x4;
	uint8_t field2_0x5;
	uint8_t field3_0x6;
	uint8_t field4_0x7;
	LexerToken token;
	uint8_t field6_0xc;
	uint8_t field7_0xd;
	uint8_t field8_0xe;
	uint8_t field9_0xf;
	uint8_t field10_0x10;
	uint8_t field11_0x11;
	uint8_t field12_0x12;
	uint8_t field13_0x13;
	uint8_t field14_0x14;
	uint8_t field15_0x15;
	uint8_t field16_0x16;
	uint8_t field17_0x17;
	uint8_t field18_0x18;
	uint8_t field19_0x19;
	uint8_t field20_0x1a;
	uint8_t field21_0x1b;
	uint8_t field22_0x1c;
	uint8_t field23_0x1d;
	uint8_t field24_0x1e;
	uint8_t field25_0x1f;
	uint8_t field26_0x20;
	uint8_t field27_0x21;
	uint8_t field28_0x22;
	uint8_t field29_0x23;
	uint8_t field30_0x24;
	uint8_t field31_0x25;
	uint8_t field32_0x26;
	uint8_t field33_0x27;
	uint8_t field34_0x28;
	uint8_t field35_0x29;
	uint8_t field36_0x2a;
	uint8_t field37_0x2b;
	CColor color;
	uint8_t field39_0x48;
	uint8_t field40_0x49;
	uint8_t field41_0x4a;
	uint8_t field42_0x4b;
	bool canReduceMilitancy;
	uint8_t field44_0x4d;
	uint8_t field45_0x4e;
	uint8_t field46_0x4f;
	CAdditiveForUpperHouseMTTH addPoliticalReformMTTH;
	CAdditiveForUpperHouseMTTH removePoliticalReformMTTH;
	CAdditiveForUpperHouseMTTH addSocialReformMTTH;
	CAdditiveForUpperHouseMTTH removeSocialReformMTTH;
	CAdditiveForUpperHouseMTTH addMilitaryReformMTTH;
	CAdditiveForUpperHouseMTTH addEconomicReformMTTH;
	CAdditiveForUpperHouseMTTH removeMilitaryReformMTTH;
	CAdditiveForUpperHouseMTTH removeEconomicReformMTTH;
	CEU3Date date;
	CEU3Date enableAt;
	bool requireCivilizedStatus;
	uint8_t field58_0x1d9;
	uint8_t field59_0x1da;
	uint8_t field60_0x1db;
};

}
}
}

#pragma pack(pop)

#endif // HANDLES_CIDEOLOGY_HPP_
