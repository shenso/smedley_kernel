#ifndef HANDLES_CCOUNTRYAI_HPP_
#define HANDLES_CCOUNTRYAI_HPP_

#include <cstdint>
#include "CCountryTag.hpp"
#include "CModifier.hpp"

#pragma pack(push, 1)

namespace smedley
{
namespace handles
{

struct CAIKing;

struct CCountryAI
{
	CModifier modifier;
	CCountryTag field1_0x30;
	CAIKing * agent;
};

}
}

#pragma pack(pop)

#endif // HANDLES_CCOUNTRYAI_HPP_
