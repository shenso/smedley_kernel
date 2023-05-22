#ifndef HANDLES_CGUNBOATING_HPP_
#define HANDLES_CGUNBOATING_HPP_

#include <cstdint>
#include <handles/CCountryTag.hpp>
#include <handles/CEU3Date.hpp>

#pragma pack(push, 1)

namespace smedley
{
namespace handles
{

struct CRelation_vftable;

struct CGunboating
{
	CRelation_vftable * vftable;
	uint32_t field1_0x4;
	CCountryTag target;
	CCountryTag thisTag;
	CEU3Date creationDate;
	CEU3Date expirationDate;
	bool cancel;
	uint8_t field7_0x21;
	uint8_t field8_0x22;
	uint8_t field9_0x23;
	uint8_t field10_0x24;
	uint8_t field11_0x25;
	uint8_t field12_0x26;
	uint8_t field13_0x27;
	uint8_t field14_0x28;
	uint8_t field15_0x29;
	uint8_t field16_0x2a;
	uint8_t field17_0x2b;
	uint8_t field18_0x2c;
	uint8_t field19_0x2d;
	uint8_t field20_0x2e;
	uint8_t field21_0x2f;
};

}
}

#pragma pack(pop)

#endif // HANDLES_CGUNBOATING_HPP_
