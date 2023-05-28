#ifndef HANDLES_CWAR_HPP_
#define HANDLES_CWAR_HPP_

#include <cstdint>
#include "CCountryTag.hpp"
#include "CWarGoal.hpp"
#include "basic_string.hpp"
#include "CHistoryContainer.hpp"
#include "CEU3Date.hpp"
#include "vector.hpp"

#pragma pack(push, 1)

namespace smedley
{
namespace native
{
namespace handles
{

struct CWar
{
	void **vftable;
	uint8_t field1_0x4;
	uint8_t field2_0x5;
	uint8_t field3_0x6;
	uint8_t field4_0x7;
	bool isRevolutionaryWar;
	uint8_t field6_0x9;
	uint8_t field7_0xa;
	uint8_t field8_0xb;
	CEU3Date action;
	basic_string<char> name;
	vector<CCountryTag> attackers;
	vector<CCountryTag> defenders;
	CHistoryContainer history;
	uint8_t field14_0x70;
	uint8_t field15_0x71;
	uint8_t field16_0x72;
	uint8_t field17_0x73;
	uint8_t field18_0x74;
	uint8_t field19_0x75;
	uint8_t field20_0x76;
	uint8_t field21_0x77;
	uint8_t field22_0x78;
	uint8_t field23_0x79;
	uint8_t field24_0x7a;
	uint8_t field25_0x7b;
	uint8_t field26_0x7c;
	uint8_t field27_0x7d;
	uint8_t field28_0x7e;
	uint8_t field29_0x7f;
	uint8_t field30_0x80;
	uint8_t field31_0x81;
	uint8_t field32_0x82;
	uint8_t field33_0x83;
	CCountryTag target;
	CCountryTag originalAttacker;
	CCountryTag originalDefender;
	CWarGoal originalWargoal;
	uint8_t warGoals__;
	uint8_t field39_0xdd;
	uint8_t field40_0xde;
	uint8_t field41_0xdf;
	uint8_t field42_0xe0;
	uint8_t field43_0xe1;
	uint8_t field44_0xe2;
	uint8_t field45_0xe3;
	uint8_t field46_0xe4;
	uint8_t field47_0xe5;
	uint8_t field48_0xe6;
	uint8_t field49_0xe7;
	uint8_t field50_0xe8;
	uint8_t field51_0xe9;
	uint8_t field52_0xea;
	uint8_t field53_0xeb;
	uint8_t field54_0xec;
	uint8_t field55_0xed;
	uint8_t field56_0xee;
	uint8_t field57_0xef;
	uint8_t field58_0xf0;
	uint8_t field59_0xf1;
	uint8_t field60_0xf2;
	uint8_t field61_0xf3;
	uint8_t field62_0xf4;
	uint8_t field63_0xf5;
	uint8_t field64_0xf6;
	uint8_t field65_0xf7;
	uint8_t field66_0xf8;
	uint8_t field67_0xf9;
	uint8_t field68_0xfa;
	uint8_t field69_0xfb;
	bool greatWarsAreEnabled;
	bool isCrisisWar;
	uint8_t field72_0xfe;
	uint8_t field73_0xff;
	uint8_t field74_0x100;
	uint8_t field75_0x101;
	uint8_t field76_0x102;
	uint8_t field77_0x103;
	uint8_t field78_0x104;
	uint8_t field79_0x105;
	uint8_t field80_0x106;
	uint8_t field81_0x107;
	uint8_t field82_0x108;
	uint8_t field83_0x109;
	uint8_t field84_0x10a;
	uint8_t field85_0x10b;
};

}
}
}

#pragma pack(pop)

#endif // HANDLES_CWAR_HPP_
