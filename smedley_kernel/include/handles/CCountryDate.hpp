#ifndef HANDLES_CCOUNTRYDATE_HPP_
#define HANDLES_CCOUNTRYDATE_HPP_

#include <cstdint>
#include <handles/CCountryTag.hpp>
#include <handles/CEU3Date.hpp>

#pragma pack(push, 1)

namespace smedley
{
namespace handles
{

struct CCountryDate
{
	void **vftable;
	uint8_t field1_0x4;
	uint8_t field2_0x5;
	uint8_t field3_0x6;
	uint8_t field4_0x7;
	CCountryTag tag;
	CEU3Date date;
};

}
}

#pragma pack(pop)

#endif // HANDLES_CCOUNTRYDATE_HPP_
