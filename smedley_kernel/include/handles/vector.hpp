#ifndef HANDLES_VECTOR_HPP_
#define HANDLES_VECTOR_HPP_

#include <cstdint>

#pragma pack(push, 1)

namespace smedley
{
namespace handles
{

template <typename T>
struct vector
{
	T *first;
	T *last;
	T *end;
	uint32_t field3;
};

}
}

#pragma pack(pop)

#endif // HANDLES_BASIC_STRING_HPP_
