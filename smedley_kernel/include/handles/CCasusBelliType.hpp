#ifndef HANDLES_CCASUSBELLITYPE_HPP_
#define HANDLES_CCASUSBELLITYPE_HPP_

#include <cstdint>
#include <handles/CAndTrigger.hpp>
#include <handles/basic_string.hpp>
#include <handles/CList.hpp>
#include <handles/CEffect.hpp>
#include <handles/CFixedPoint.hpp>

#pragma pack(push, 1)

namespace smedley
{
namespace handles
{

struct CCasusBelliType_vftable;

struct CCasusBelliType
{
	CCasusBelliType_vftable * vftable;
	uint8_t field1_0x4;
	uint8_t field2_0x5;
	uint8_t field3_0x6;
	uint8_t field4_0x7;
	int id;
	int spriteIndex;
	uint8_t field7_0x10;
	uint8_t field8_0x11;
	uint8_t field9_0x12;
	uint8_t field10_0x13;
	basic_string<char> name;
	CAndTrigger isValid;
	CAndTrigger canUse;
	CAndTrigger prerequisites;
	CAndTrigger allowedStatesInCrisis;
	CAndTrigger allowedStates;
	CAndTrigger allowedSubstateRegions;
	CAndTrigger allowedCountries;
	CFixedPoint badboyfactor;
	CFixedPoint prestigeFactor;
	CFixedPoint peaceCostFactor;
	CFixedPoint penaltyFactor;
	CFixedPoint breakTrucePrestigeFactor;
	CFixedPoint breakTruceInfamyFactor;
	CFixedPoint breakTruceMilitancyFactor;
	int truceMonths;
	CFixedPoint goodRelationInfamyFactor;
	CFixedPoint goodRelationPrestigeFactor;
	CFixedPoint goodRelationMilitancyFactor;
	CList<LexerToken> peaceOffers;
	bool isTriggeredOnly;
	bool mutual;
	bool always;
	bool crisis;
	int months;
	basic_string<char> warName;
	basic_string<char> countryDesc;
	basic_string<char> provDesc;
	CEffect onAdd;
	uint8_t field40_0x1a8;
	uint8_t field41_0x1a9;
	uint8_t field42_0x1aa;
	uint8_t field43_0x1ab;
	CEffect onPoAccepted;
	uint8_t field45_0x1c8;
	uint8_t field46_0x1c9;
	uint8_t field47_0x1ca;
	uint8_t field48_0x1cb;
	bool isCivilWar;
	bool constructingCb;
	uint8_t field51_0x1ce;
	uint8_t field52_0x1cf;
	CFixedPoint constructionSpeed;
	uint8_t field54_0x1d4;
	uint8_t field55_0x1d5;
	uint8_t field56_0x1d6;
	uint8_t field57_0x1d7;
	CFixedPoint twsBattleFactor;
	bool allAllowedStates;
	uint8_t field60_0x1dd;
	uint8_t field61_0x1de;
	uint8_t field62_0x1df;
};

}
}

#pragma pack(pop)

#endif // HANDLES_CCASUSBELLITYPE_HPP_
