#ifndef HANDLES_CRELATION_HPP_
#define HANDLES_CRELATION_HPP_

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

struct CRelation_vftable;

struct CRelation
{
	CRelation_vftable *vftable;
	uint32_t field1_0x4;
	CCountryTag target;
	CCountryTag thisTag;
	CEU3Date creationDate;
	CEU3Date expirationDate;
	bool cancel;
	uint8_t field7_0x21;
	uint8_t field8_0x22;
	uint8_t field9_0x23;
};

}
}
}

#pragma pack(pop)

#endif // HANDLES_CRELATION_HPP_
