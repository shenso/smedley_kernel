#ifndef HANDLES_CFILE_HPP_
#define HANDLES_CFILE_HPP_

#include <cstdint>
#include "basic_string.hpp"

#pragma pack(push, 1)

namespace smedley
{
namespace handles
{

struct PHYSFS_File;
struct CFile_vftable;

struct CFile
{
	CFile_vftable * vftable;
	uint8_t field1_0x4;
	uint8_t field2_0x5;
	uint8_t field3_0x6;
	uint8_t field4_0x7;
	uint8_t field5_0x8;
	uint8_t field6_0x9;
	uint8_t field7_0xa;
	uint8_t field8_0xb;
	uint8_t field9_0xc;
	uint8_t field10_0xd;
	uint8_t field11_0xe;
	uint8_t field12_0xf;
	unsigned int mask;
	basic_string<char> filename__;
	PHYSFS_File * handle;
	unsigned int pos;
	uint8_t field17_0x38;
	uint8_t field18_0x39;
	uint8_t field19_0x3a;
	uint8_t field20_0x3b;
};

}
}

#pragma pack(pop)

#endif // HANDLES_CFILE_HPP_
