#ifndef HANDLES_CDATASPREAD_HPP_
#define HANDLES_CDATASPREAD_HPP_

#include <cstdint>

#pragma pack(push, 1)

namespace smedley
{
namespace handles
{

template <typename T>
struct CDataSpread
{
	void *vtable;
	uint8_t field1_0x4;
	uint8_t field2_0x5;
	uint8_t field3_0x6;
	uint8_t field4_0x7;
	vector<T> values;
	vector<int> index;
};

}
}

#pragma pack(pop)

#endif // HANDLES_CDATASPREAD_HPP_
