#pragma once

namespace smedley::sstd
{

	template <typename T>
	class allocator
	{
	};

	template <typename T, class Allocator = allocator<T>>
	class vector
	{
	protected:
		T *_first;
		T *_last;
		T *_end;
		Allocator *_al_val;
	};

	static_assert(sizeof(vector<int>) == 0x10);

}