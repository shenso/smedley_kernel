#ifndef HANDLES_CPLAYER_HPP_
#define HANDLES_CPLAYER_HPP_

#include <cstdint>
#include "CCountryTag.hpp"
#include "basic_string.hpp"

#pragma pack(push, 1)

namespace smedley
{
namespace handles
{

struct CPlayer
{
	basic_string<char> name;
	bool field1_0x1c;
	uint8_t field2_0x1d;
	uint8_t field3_0x1e;
	uint8_t field4_0x1f;
	CCountryTag tag;
	uint8_t field6_0x28;
	uint8_t field7_0x29;
	uint8_t field8_0x2a;
	uint8_t field9_0x2b;
	uint8_t field10_0x2c;
	uint8_t field11_0x2d;
	uint8_t field12_0x2e;
	uint8_t field13_0x2f;
	bool automateTrade;
	uint8_t field15_0x31;
	uint8_t field16_0x32;
	uint8_t field17_0x33;
	uint8_t field18_0x34;
	uint8_t field19_0x35;
	uint8_t field20_0x36;
	uint8_t field21_0x37;
};

}
}

#pragma pack(pop)

#endif // HANDLES_CPLAYER_HPP_
