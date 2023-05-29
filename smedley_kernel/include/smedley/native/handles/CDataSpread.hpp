#ifndef HANDLES_CDATASPREAD_HPP_
#define HANDLES_CDATASPREAD_HPP_

#include <cstdint>
#include "vector.hpp"

#pragma pack(push, 1)

namespace smedley
{
namespace native
{
namespace handles
{

template <typename T>
struct CDataSpread
{
	void *vftable;
	uint32_t field1_0x4;
	vector<T> values;
	vector<int> index;
};

}
}
}

#pragma pack(pop)

#endif // HANDLES_CDATASPREAD_HPP_
