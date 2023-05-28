#ifndef HANDLES_CWARGOAL_HPP_
#define HANDLES_CWARGOAL_HPP_

#include <cstdint>
#include "CCountryTag.hpp"
#include "CEU3Date.hpp"
#include "CFixedPoint.hpp"

#pragma pack(push, 1)

namespace smedley
{
namespace handles
{

struct CCasusBelliType;
struct CRegion;

struct CWarGoal
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
	CCasusBelliType * cbType;
	CCountryTag country;
	CCountryTag actor;
	CCountryTag receiver;
	int stateProvinceId;
	uint8_t field14_0x2c;
	uint8_t field15_0x2d;
	uint8_t field16_0x2e;
	uint8_t field17_0x2f;
	CFixedPoint change;
	CEU3Date date;
	bool isFulfilled;
	uint8_t field21_0x39;
	uint8_t field22_0x3a;
	uint8_t field23_0x3b;
	CRegion * region;
};

}
}

#pragma pack(pop)

#endif // HANDLES_CWARGOAL_HPP_
