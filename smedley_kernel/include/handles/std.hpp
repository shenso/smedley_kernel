#ifndef HANDLES_STD_HPP_
#define HANDLES_STD_HPP_

#pragma pack(push, 1)

#include <cstdint>

namespace smedley
{
namespace handles
{

template <typename T>
struct basic_string
{
	T _impl[16];
	int size;
	int capacity;
	uint32_t field3_0x18;
};

template <typename T>
struct vector
{
	T *first;
	T *last;
	T *end;
	uint32_t field3_0xc;
};

}
}

#pragma pack(pop)

#endif // HANDLES_STD_HPP_