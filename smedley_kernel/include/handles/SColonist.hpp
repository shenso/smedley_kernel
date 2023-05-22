#ifndef HANDLES_SCOLONIST_HPP_
#define HANDLES_SCOLONIST_HPP_

#include <cstdint>
#include <handles/CCountryTag.hpp>
#include <handles/CEU3Date.hpp>

#pragma pack(push, 1)

namespace smedley
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

#pragma pack(pop)

#endif // HANDLES_SCOLONIST_HPP_
