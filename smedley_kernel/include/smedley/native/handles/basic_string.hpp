#ifndef HANDLES_BASIC_STRING_HPP_
#define HANDLES_BASIC_STRING_HPP_

#include <cstdint>

#pragma pack(push, 1)

namespace smedley
{
namespace native
{
namespace handles
{

template <typename T>
struct basic_string
{
	T _impl[16];
	int size;
	int capacity;
	uint32_t field3;
};

}
}
}

#pragma pack(pop)

#endif // HANDLES_BASIC_STRING_HPP_
