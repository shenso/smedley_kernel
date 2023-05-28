#ifndef HANDLES_CEVENTSCOPE_HPP_
#define HANDLES_CEVENTSCOPE_HPP_

#include <cstdint>
#include "CCountryTag.hpp"
#include "ObjectReference.hpp"

#pragma pack(push, 1)

namespace smedley
{
namespace native
{
namespace handles
{

struct CPop;
struct CEventScope_vftable;
struct CEventScope;

struct CEventScope
{
	CEventScope_vftable *vftable;
	uint32_t field1_0x4;
	CCountryTag thisTag;
	int provinceId;
	CPop *pop;
	int stateProvinceId;
	CEventScope *field6_0x1c;
	uint8_t field7_0x20;
	uint8_t field8_0x21;
	uint8_t field9_0x22;
	uint8_t field10_0x23;
	CEventScope *parent__;
	uint8_t field12_0x28;
	uint8_t field13_0x29;
	uint8_t field14_0x2a;
	uint8_t field15_0x2b;
	CCountryTag fromTag;
	int fromProvinceId;
	ObjectReference rebelFaction__;
	unsigned int field19_0x40;
	uint8_t field20_0x44;
	uint8_t field21_0x45;
	uint8_t field22_0x46;
	uint8_t field23_0x47;
};

}
}
}

#pragma pack(pop)

#endif // HANDLES_CEVENTSCOPE_HPP_
