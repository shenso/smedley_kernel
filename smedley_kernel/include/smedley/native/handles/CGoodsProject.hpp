#ifndef HANDLES_CGOODSPROJECT_HPP_
#define HANDLES_CGOODSPROJECT_HPP_

#include <cstdint>
#include "CGoodsPool.hpp"
#include "CFixedPoint64.hpp"

#pragma pack(push, 1)

namespace smedley
{
namespace native
{
namespace handles
{

struct CGoodsProject
{
	void **vftable;
	uint8_t field1_0x4;
	uint8_t field2_0x5;
	uint8_t field3_0x6;
	uint8_t field4_0x7;
	CGoodsPool input;
	CGoodsPool demand;
	CFixedPoint64 money;
};

}
}
}

#pragma pack(pop)

#endif // HANDLES_CGOODSPROJECT_HPP_
