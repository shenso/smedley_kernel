#pragma once

#include "../memory.hpp"
#include <cstring>
#include <memory>
#include <type_traits>

namespace smedley::sstd
{

	template <typename T>
	class vector
	{
	public:
		using size_type = size_t;
		using reference = T &;
	protected:
		T *_first;
		T *_last;
		T *_end;
		uint32_t _al_val;

		void _change_array(T *new_vec, size_type new_size, size_type new_capacity)
		{
			if (_first != nullptr) {
				HeapFree(memory::Map::game_heap, NULL, reinterpret_cast<void *>(_first));
			}

			_first = new_vec;
			_last = new_vec + new_size;
			_end = new_vec + new_capacity;
		}

		void _uninit_move(T *first, T *last, T *where)
		{
			for (T *cur = first; cur != last && where != nullptr; cur++, where++) {
				*cur = std::move(T(*where));
			}
		}

		void _uninit_copy(T *first, T *last, T *where)
		{
			std::memmove(where, first, (last - first) * sizeof(T));
		}
	public:
		vector() : _first(nullptr), _last(nullptr), _end(nullptr), _al_val(0)
		{
		}

		/// @param n the new capacity (size of the internal array).
		void reserve(size_t n)
		{
			if (n > capacity()) {
				T *new_vec = reinterpret_cast<T *>(HeapAlloc(memory::Map::game_heap, HEAP_ZERO_MEMORY, sizeof(T) * n));

				_uninit_copy(_first, _last, new_vec);
					/*
				if constexpr (std::is_nothrow_move_constructible_v<T> || !std::is_copy_constructible_v<T>) {
					_uninit_move(_first, _last, new_vec);
				} else {
					_uninit_copy(_first, _last, new_vec);
				}
				*/

				_change_array(new_vec, size(), n);
			}
		}

		void push_back(const T &val)
		{
			if (_last == _end) {
				if (_first == nullptr) {
					reserve(0x10);
				} else {
					reserve(capacity() << 1);
				}
			}

			/*
			if constexpr (std::is_nothrow_move_constructible_v<T> || !std::is_copy_constructible_v<T>) {
				*_last = std::move(T(val));
			} else {
				std::memmove(_last, &val, sizeof(T));
			}
			*/
			*_last = val;
			++_last;
		}

		inline size_type capacity() const noexcept { return _end - _first; }
		inline size_type size() const noexcept { return _last - _first; }

		reference operator[](size_type i) { return _first[i]; }
		const reference operator[](size_type i) const { return _first[i]; }
	};

	static_assert(sizeof(vector<int>) == 0x10);

}