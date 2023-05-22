#ifndef HANDLES_CARRAY_HPP_
#define HANDLES_CARRAY_HPP_

#include <cstdint>

#pragma pack(push, 1)

namespace smedley
{
namespace handles
{

template <typename T>
struct CArray
{
	T *_impl;
	int size;
};

}
}

#pragma pack(pop)

#endif // HANDLES_CARRAY_HPP_
