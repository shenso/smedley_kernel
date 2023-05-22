#ifndef HANDLES_CGOODSPOOL_HPP_
#define HANDLES_CGOODSPOOL_HPP_

#include <cstdint>
#include <handles/CFixedPoint64.hpp>
#include <handles/vector.hpp>

#pragma pack(push, 1)

namespace smedley
{
namespace handles
{

struct CGoodsPool
{
	void **vftable;
	uint8_t field1_0x4;
	uint8_t field2_0x5;
	uint8_t field3_0x6;
	uint8_t field4_0x7;
	uint8_t index[64];
	vector<CFixedPoint64> values;
};

}
}

#pragma pack(pop)

#endif // HANDLES_CGOODSPOOL_HPP_
