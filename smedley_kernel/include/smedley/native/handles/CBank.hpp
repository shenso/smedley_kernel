#ifndef HANDLES_CBANK_HPP_
#define HANDLES_CBANK_HPP_

#include <cstdint>
#include "CFixedPoint64.hpp"

#pragma pack(push, 1)

namespace smedley
{
namespace native
{
namespace handles
{

struct CCountry;

struct CBank
{
	void **vftable;
	uint8_t field1_0x4;
	uint8_t field2_0x5;
	uint8_t field3_0x6;
	uint8_t field4_0x7;
	CCountry *country;
	uint8_t field6_0xc;
	uint8_t field7_0xd;
	uint8_t field8_0xe;
	uint8_t field9_0xf;
	CFixedPoint64 money;
	CFixedPoint64 totalLent;
	CFixedPoint64 interestPayments;
};

}
}
}

#pragma pack(pop)

#endif // HANDLES_CBANK_HPP_
