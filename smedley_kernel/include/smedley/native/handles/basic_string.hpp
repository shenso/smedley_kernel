#ifndef HANDLES_BASIC_STRING_HPP_
#define HANDLES_BASIC_STRING_HPP_

#include <cstdint>
#include <string>

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

	std::basic_string<T> transform()
	{
		return std::basic_string<T>(_impl, size);
	}
};

}
}
}

#pragma pack(pop)

#endif // HANDLES_BASIC_STRING_HPP_
