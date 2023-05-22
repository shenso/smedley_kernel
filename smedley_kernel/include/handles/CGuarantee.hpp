#ifndef HANDLES_CGUARANTEE_HPP_
#define HANDLES_CGUARANTEE_HPP_

#include <cstdint>
#include <handles/CCountryTag.hpp>
#include <handles/CEU3Date.hpp>

#pragma pack(push, 1)

namespace smedley
{
namespace handles
{

struct CGuarantee
{
	void *vftable;
	uint32_t field1_0x4;
	CCountryTag first;
	CCountryTag second;
	CEU3Date startDate__;
	CEU3Date endDate__;
	bool cancel;
	uint8_t field7_0x21;
	uint8_t field8_0x22;
	uint8_t field9_0x23;
	uint8_t field10_0x24;
	uint8_t field11_0x25;
	uint8_t field12_0x26;
	uint8_t field13_0x27;
};

}
}

#pragma pack(pop)

#endif // HANDLES_CGUARANTEE_HPP_
