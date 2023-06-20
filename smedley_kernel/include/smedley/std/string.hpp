#pragma once

#include <cstdint>
#include <cstring>
#include <memory>
#include <string>

namespace smedley::sstd
{

	template <typename T,
	          class Traits = std::char_traits<T>,
			  class Allocator = std::allocator<T>>
	class basic_string
	{
	protected:
		union {
			T buf[16];
			T *ptr;
		} _impl;
		size_t _size;
		size_t _capacity;
		Allocator _alloc;
	public:
		basic_string(const T *str)
		{
			size_t n = Traits::length(str);
			if (n > 0xf) {
				_impl.ptr = _alloc.allocate(n);
			}
			std::memcpy(_impl.ptr, str, n + sizeof(T));
		}

		const T *c_str() const { return _impl.ptr; }
	};

	using string = basic_string<char>;

	static_assert(sizeof(string) == 0x1c);

}