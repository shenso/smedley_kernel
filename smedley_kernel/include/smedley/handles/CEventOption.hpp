#ifndef HANDLES_CEVENTOPTION_HPP_
#define HANDLES_CEVENTOPTION_HPP_

#include <cstdint>
#include "basic_string.hpp"
#include "CEffect.hpp"
#include "CAIMTTHChance.hpp"

#pragma pack(push, 1)

namespace smedley
{
namespace handles
{

struct CEventOption
{
	void **field0_0x0;
	uint8_t field1_0x4;
	uint8_t field2_0x5;
	uint8_t field3_0x6;
	uint8_t field4_0x7;
	CAIMTTHChance aiChance;
	CEffect effect;
	uint8_t field7_0x44;
	uint8_t field8_0x45;
	uint8_t field9_0x46;
	uint8_t field10_0x47;
	basic_string<char> name;
};

}
}

#pragma pack(pop)

#endif // HANDLES_CEVENTOPTION_HPP_
