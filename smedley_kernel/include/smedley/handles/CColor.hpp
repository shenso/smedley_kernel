#ifndef HANDLES_CCOLOR_HPP_
#define HANDLES_CCOLOR_HPP_

#include <cstdint>

#pragma pack(push, 1)

namespace smedley
{
namespace handles
{

struct CColor
{
	void *vtable;
	uint32_t field1_0x4;
	float r;
	float g;
	float b;
	float a;
	unsigned int field6_0x18;
};

}
}

#pragma pack(pop)

#endif // HANDLES_CCOLOR_HPP_
