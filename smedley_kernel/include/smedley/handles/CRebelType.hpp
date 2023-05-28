#ifndef HANDLES_CREBELTYPE_HPP_
#define HANDLES_CREBELTYPE_HPP_

#include <cstdint>
#include "CMeanTimeToHappen.hpp"
#include "CAndTrigger.hpp"
#include "basic_string.hpp"
#include "CFixedPoint64.hpp"
#include "CEffect.hpp"
#include "vector.hpp"
#include "DefectionType.hpp"

#pragma pack(push, 1)

namespace smedley
{
namespace handles
{

struct CIdeology;
struct CGovernment;

struct CRebelType
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
	basic_string<char> name;
	CMeanTimeToHappen spawnChance;
	CMeanTimeToHappen movementEvaluation;
	CMeanTimeToHappen willRise;
	CAndTrigger siegeWonTrigger;
	CEffect siegeWonEffect;
	uint8_t field19_0xb8;
	uint8_t field20_0xb9;
	uint8_t field21_0xba;
	uint8_t field22_0xbb;
	CAndTrigger field23_0xbc;
	CEffect demandsEnforcedEffect;
	uint8_t field25_0xf4;
	uint8_t field26_0xf5;
	uint8_t field27_0xf6;
	uint8_t field28_0xf7;
	Area area;
	DefectionType defection;
	uint8_t field31_0x100;
	uint8_t field32_0x101;
	uint8_t field33_0x102;
	uint8_t field34_0x103;
	int defectDelay;
	uint8_t field36_0x108;
	uint8_t field37_0x109;
	uint8_t field38_0x10a;
	uint8_t field39_0x10b;
	uint8_t field40_0x10c;
	uint8_t field41_0x10d;
	uint8_t field42_0x10e;
	uint8_t field43_0x10f;
	uint8_t field44_0x110;
	uint8_t field45_0x111;
	uint8_t field46_0x112;
	uint8_t field47_0x113;
	uint8_t field48_0x114;
	uint8_t field49_0x115;
	uint8_t field50_0x116;
	uint8_t field51_0x117;
	CFixedPoint64 occupationMultiplier;
	bool general;
	bool disbandOnLeaderDeath;
	bool isResilient;
	bool reinforcing;
	bool smart;
	bool unitTransfer;
	bool global;
	uint8_t field60_0x127;
	int icon;
	bool allowAllCultures;
	bool allowAllReligions;
	uint8_t allowAllIdeologies;
	bool allowAllCultureGroups;
	CIdeology * ideology;
	vector<CGovernment *> desiredGovernments;
	bool breakAllianceOnWin;
	uint8_t field69_0x145;
	uint8_t field70_0x146;
	uint8_t field71_0x147;
};

}
}

#pragma pack(pop)

#endif // HANDLES_CREBELTYPE_HPP_
