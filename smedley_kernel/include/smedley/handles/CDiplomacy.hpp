#ifndef HANDLES_CDIPLOMACY_HPP_
#define HANDLES_CDIPLOMACY_HPP_

#include <cstdint>
#include "CHistoryContainer.hpp"
#include "CList.hpp"

#pragma pack(push, 1)

namespace smedley
{
namespace handles
{

struct CRelation;

struct CDiplomacy
{
	void **vftable;
	uint8_t field1_0x4;
	uint8_t field2_0x5;
	uint8_t field3_0x6;
	uint8_t field4_0x7;
	CList<CRelation *> relations;
	CHistoryContainer history;
};

}
}

#pragma pack(pop)

#endif // HANDLES_CDIPLOMACY_HPP_
