#ifndef HANDLES_CCREDITOR_HPP_
#define HANDLES_CCREDITOR_HPP_

#include <cstdint>
#include "CCountryTag.hpp"
#include "CFixedPoint64.hpp"

#pragma pack(push, 1)

namespace smedley
{
namespace native
{
namespace handles
{

struct CCreditor
{
	void **vftable;
	uint8_t field1_0x4;
	uint8_t field2_0x5;
	uint8_t field3_0x6;
	uint8_t field4_0x7;
	CCountryTag tag;
	CFixedPoint64 interest;
	CFixedPoint64 debt;
	bool wasPaid;
	uint8_t field9_0x21;
	uint8_t field10_0x22;
	uint8_t field11_0x23;
	uint8_t field12_0x24;
	uint8_t field13_0x25;
	uint8_t field14_0x26;
	uint8_t field15_0x27;
};

}
}
}

#pragma pack(pop)

#endif // HANDLES_CCREDITOR_HPP_
