#pragma once

#include <cstdint>

namespace smedley::sstd
{

	template <typename T>
	class basic_string
	{
	protected:
		T _impl[16];
		size_t _size;
		size_t _capacity;
		uint32_t _unk_4;
	public:
		const T *c_str() const { return _impl; }
	};

	using string = basic_string<char>;

	static_assert(sizeof(string) == 0x1c);

}