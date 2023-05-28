#ifndef HANDLES_CWRITER_HPP_
#define HANDLES_CWRITER_HPP_

#include <cstdint>

#pragma pack(push, 1)

namespace smedley
{
namespace native
{
namespace handles
{

struct CFile;

struct CWriter
{
	void *vftable;
	uint32_t indent;
	CFile *file;
	bool numbersAreInts__;
	uint8_t field4_0xd;
	uint8_t field5_0xe;
	uint8_t field6_0xf;
};

}
}
}

#pragma pack(pop)

#endif // HANDLES_CWRITER_HPP_
