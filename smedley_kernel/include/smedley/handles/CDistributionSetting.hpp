#ifndef HANDLES_CDISTRIBUTIONSETTING_HPP_
#define HANDLES_CDISTRIBUTIONSETTING_HPP_

#include <cstdint>
#include "CFixedPoint64.hpp"

#pragma pack(push, 1)

namespace smedley
{
namespace handles
{

struct CCountry;

struct CDistributionSetting
{
	void **vftable;
	uint8_t field1_0x4;
	uint8_t field2_0x5;
	uint8_t field3_0x6;
	uint8_t field4_0x7;
	CFixedPoint64 tempSetting;
	CFixedPoint64 setting;
	CFixedPoint64 factor;
	CCountry * country;
	uint8_t field9_0x24;
	uint8_t field10_0x25;
	uint8_t field11_0x26;
	uint8_t field12_0x27;
	CFixedPoint64 reserve;
	CFixedPoint64 maxValue;
	CFixedPoint64 rangeLimitMax;
	CFixedPoint64 rangeLimitMin;
	int maxTax;
	int minTax;
};

}
}

#pragma pack(pop)

#endif // HANDLES_CDISTRIBUTIONSETTING_HPP_
