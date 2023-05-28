#ifndef HANDLES_CPOPINCOME_HPP_
#define HANDLES_CPOPINCOME_HPP_

#include <cstdint>
#include "CFixedPoint64.hpp"

#pragma pack(push, 1)

namespace smedley
{
namespace handles
{

struct CPopIncome
{
	void *field0_0x0;
	uint32_t field1_0x4;
	CFixedPoint64 amount__;
	uint8_t field3_0x10;
	uint8_t field4_0x11;
	uint8_t field5_0x12;
	uint8_t field6_0x13;
	uint8_t field7_0x14;
	uint8_t field8_0x15;
	uint8_t field9_0x16;
	uint8_t field10_0x17;
	uint8_t field11_0x18;
	uint8_t field12_0x19;
	uint8_t field13_0x1a;
	uint8_t field14_0x1b;
};

}
}

#pragma pack(pop)

#endif // HANDLES_CPOPINCOME_HPP_
