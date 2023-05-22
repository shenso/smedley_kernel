#ifndef HANDLES_CVASSAL_HPP_
#define HANDLES_CVASSAL_HPP_

#include <cstdint>
#include <handles/CCountryTag.hpp>
#include <handles/CEU3Date.hpp>

#pragma pack(push, 1)

namespace smedley
{
namespace handles
{

struct CRelation_vftable;

struct CVassal
{
	CRelation_vftable * vftable;
	uint32_t field1_0x4;
	CCountryTag first;
	CCountryTag second;
	CEU3Date startDate__;
	CEU3Date endDate__;
	bool cancel;
	uint8_t field7_0x21;
	uint8_t field8_0x22;
	uint8_t field9_0x23;
};

}
}

#pragma pack(pop)

#endif // HANDLES_CVASSAL_HPP_
