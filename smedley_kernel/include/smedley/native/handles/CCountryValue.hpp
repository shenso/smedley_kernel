#ifndef HANDLES_CCOUNTRYVALUE_HPP_
#define HANDLES_CCOUNTRYVALUE_HPP_

#include <cstdint>
#include "CCountryTag.hpp"

#pragma pack(push, 1)

namespace smedley
{
namespace native
{
namespace handles
{

struct CCountryValue
{
	void **vftable;
	uint8_t field1_0x4;
	uint8_t field2_0x5;
	uint8_t field3_0x6;
	uint8_t field4_0x7;
	CCountryTag tag;
	int value;
};

}
}
}

#pragma pack(pop)

#endif // HANDLES_CCOUNTRYVALUE_HPP_
