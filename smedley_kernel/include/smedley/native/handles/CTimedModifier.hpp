#ifndef HANDLES_CTIMEDMODIFIER_HPP_
#define HANDLES_CTIMEDMODIFIER_HPP_

#include <cstdint>
#include "CEU3Date.hpp"

#pragma pack(push, 1)

namespace smedley
{
namespace native
{
namespace handles
{

struct CStaticModifier;

struct CTimedModifier
{
	void **vftable;
	uint8_t field1_0x4;
	uint8_t field2_0x5;
	uint8_t field3_0x6;
	uint8_t field4_0x7;
	CStaticModifier *modifier;
	CEU3Date expiration__;
};

}
}
}

#pragma pack(pop)

#endif // HANDLES_CTIMEDMODIFIER_HPP_
