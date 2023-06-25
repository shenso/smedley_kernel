#pragma once

#include "../memory.hpp"
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
		basic_string() : _size(0), _capacity(0)
		{
			_impl.buf[0] = static_cast<T>(0x0);
		}

		basic_string(const T *str)
		{
			size_t n = Traits::length(str);
			if (n > 0xf) {
				DWORD old_protect;
				_impl.ptr = reinterpret_cast<T *>(HeapAlloc(memory::Map::game_heap, 0, (n * sizeof(T)) + 1));
				std::memcpy(_impl.ptr, str, n * sizeof(T));
				_capacity = n;
			} else {
				std::memcpy(_impl.buf, str, sizeof(_impl.buf));
				_capacity = 0xf;
			}

			_size = n;
		}

		const T *c_str() const { return _impl.ptr; }
	};

	using string = basic_string<char>;

	static_assert(sizeof(string) == 0x1c);

}