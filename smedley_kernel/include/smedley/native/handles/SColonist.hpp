#ifndef HANDLES_SCOLONIST_HPP_
#define HANDLES_SCOLONIST_HPP_

#include <cstdint>
#include "CCountryTag.hpp"
#include "CEU3Date.hpp"

#pragma pack(push, 1)

namespace smedley
{
namespace native
{
namespace handles
{

struct SColonist
{
	void **vftable;
	uint32_t field1_0x4;
	CCountryTag tag;
	int points;
	int investment;
	CEU3Date sentOrLastInvestDate__;
};

}
}
}

#pragma pack(pop)

#endif // HANDLES_SCOLONIST_HPP_
