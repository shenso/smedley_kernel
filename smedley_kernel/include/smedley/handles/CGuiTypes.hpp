#ifndef HANDLES_CGUITYPES_HPP_
#define HANDLES_CGUITYPES_HPP_

#include <cstdint>
#include "CList.hpp"
#include "TrieNode.hpp"

#pragma pack(push, 1)

namespace smedley
{
namespace handles
{

struct CGuiTypes_vftable;

struct CGuiTypes
{
	CGuiTypes_vftable * vftable;
	TrieNode<void *> * root;
	bool field2_0x8;
	uint8_t field3_0x9;
	uint8_t field4_0xa;
	uint8_t field5_0xb;
	uint32_t count__;
	uint8_t field7_0x10;
	uint8_t field8_0x11;
	uint8_t field9_0x12;
	uint8_t field10_0x13;
	CList<void *> elements__;
	uint8_t *field12_0x20;
};

}
}

#pragma pack(pop)

#endif // HANDLES_CGUITYPES_HPP_
