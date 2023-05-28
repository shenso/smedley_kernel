#ifndef HANDLES_CISSUEGROUP_HPP_
#define HANDLES_CISSUEGROUP_HPP_

#include <cstdint>
#include "basic_string.hpp"
#include "vector.hpp"

#pragma pack(push, 1)

namespace smedley
{
namespace native
{
namespace handles
{

struct CIssue;

struct CIssueGroup
{
	void **vftable;
	uint8_t field1_0x4;
	uint8_t field2_0x5;
	uint8_t field3_0x6;
	uint8_t field4_0x7;
	vector<CIssue *> issues;
	basic_string<char> name;
	basic_string<char> label;
	uint8_t field8_0x50;
	uint8_t field9_0x51;
	uint8_t field10_0x52;
	uint8_t field11_0x53;
	uint8_t field12_0x54;
	uint8_t field13_0x55;
	uint8_t field14_0x56;
	uint8_t field15_0x57;
	bool isAdministrative;
	bool allowNextStepOnly;
	uint8_t field18_0x5a;
	uint8_t field19_0x5b;
	uint8_t field20_0x5c;
	uint8_t field21_0x5d;
	uint8_t field22_0x5e;
	uint8_t field23_0x5f;
};

}
}
}

#pragma pack(pop)

#endif // HANDLES_CISSUEGROUP_HPP_
