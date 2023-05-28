#ifndef HANDLES_CFLAGS_HPP_
#define HANDLES_CFLAGS_HPP_

#include <cstdint>
#include "TrieNode.hpp"

#pragma pack(push, 1)

namespace smedley
{
namespace handles
{

struct CFlags_CPersistent_vftable;
struct CFlag;

struct CFlags
{
	void **CTernarty_vftable;
	TrieNode<CFlag *> * root;
	uint8_t field2_0x8;
	uint8_t field3_0x9;
	uint8_t field4_0xa;
	uint8_t field5_0xb;
	uint8_t count__;
	uint8_t field7_0xd;
	uint8_t field8_0xe;
	uint8_t field9_0xf;
	uint8_t field10_0x10;
	uint8_t field11_0x11;
	uint8_t field12_0x12;
	uint8_t field13_0x13;
	uint8_t field14_0x14;
	uint8_t field15_0x15;
	uint8_t field16_0x16;
	uint8_t field17_0x17;
	uint8_t field18_0x18;
	uint8_t field19_0x19;
	uint8_t field20_0x1a;
	uint8_t field21_0x1b;
	uint8_t field22_0x1c;
	uint8_t field23_0x1d;
	uint8_t field24_0x1e;
	uint8_t field25_0x1f;
	uint8_t field26_0x20;
	uint8_t field27_0x21;
	uint8_t field28_0x22;
	uint8_t field29_0x23;
	CFlags_CPersistent_vftable * CPersistent_vftable;
	uint8_t field31_0x28;
	uint8_t field32_0x29;
	uint8_t field33_0x2a;
	uint8_t field34_0x2b;
};

}
}

#pragma pack(pop)

#endif // HANDLES_CFLAGS_HPP_
