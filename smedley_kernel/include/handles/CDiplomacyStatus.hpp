#ifndef HANDLES_CDIPLOMACYSTATUS_HPP_
#define HANDLES_CDIPLOMACYSTATUS_HPP_

#include <cstdint>
#include <handles/CCountryTag.hpp>
#include <handles/CList.hpp>
#include <handles/CEU3Date.hpp>
#include <handles/CFixedPoint.hpp>

#pragma pack(push, 1)

namespace smedley
{
namespace handles
{

struct CGuarantee;
struct CVassal;
struct CWar;
struct CGunboating;

struct CDiplomacyStatus
{
	void **vftable;
	uint8_t field1_0x4;
	uint8_t field2_0x5;
	uint8_t field3_0x6;
	uint8_t field4_0x7;
	CCountryTag sphereLeader__;
	uint8_t field6_0x10;
	uint8_t field7_0x11;
	uint8_t field8_0x12;
	uint8_t field9_0x13;
	uint8_t field10_0x14;
	uint8_t field11_0x15;
	uint8_t field12_0x16;
	uint8_t field13_0x17;
	CCountryTag unitCommandGivenTo;
	uint8_t field15_0x20;
	uint8_t field16_0x21;
	uint8_t field17_0x22;
	uint8_t field18_0x23;
	CVassal * vassal;
	CGuarantee * guarantee;
	uint8_t field21_0x2c;
	uint8_t field22_0x2d;
	uint8_t field23_0x2e;
	uint8_t field24_0x2f;
	CGunboating * gunboating;
	CWar * war;
	uint8_t field27_0x38;
	uint8_t field28_0x39;
	uint8_t field29_0x3a;
	uint8_t field30_0x3b;
	CFixedPoint relations;
	int opinion;
	CEU3Date opinionLastChanged;
	int influence;
	CFixedPoint influenceOverflow;
	CList<void *> casusBellisAgainst;
	bool militaryAccess;
	uint8_t field38_0x61;
	uint8_t field39_0x62;
	uint8_t field40_0x63;
	CEU3Date field41_0x64;
	CEU3Date lastWar;
	CEU3Date field43_0x6c;
	uint8_t field44_0x70;
	uint8_t hasGuarantee;
	uint8_t field46_0x72;
	uint8_t field47_0x73;
	uint8_t field48_0x74;
	uint8_t field49_0x75;
	uint8_t field50_0x76;
	uint8_t field51_0x77;
	uint8_t field52_0x78;
	uint8_t field53_0x79;
	uint8_t field54_0x7a;
	uint8_t field55_0x7b;
	uint8_t field56_0x7c;
	uint8_t field57_0x7d;
	uint8_t field58_0x7e;
	uint8_t field59_0x7f;
	uint8_t field60_0x80;
	uint8_t field61_0x81;
	uint8_t field62_0x82;
	uint8_t field63_0x83;
	CFixedPoint debt;
	CFixedPoint dailyRepay;
	bool debactionAction;
	uint8_t field67_0x8d;
	uint8_t field68_0x8e;
	uint8_t field69_0x8f;
	CEU3Date discreditedUntil;
	CCountryTag discreditor;
	CEU3Date embassyBannedUntil__;
	CCountryTag embassyBanner;
	uint8_t field74_0xa8;
	uint8_t field75_0xa9;
	uint8_t field76_0xaa;
	uint8_t field77_0xab;
};

}
}

#pragma pack(pop)

#endif // HANDLES_CDIPLOMACYSTATUS_HPP_
