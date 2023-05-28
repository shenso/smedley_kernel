#ifndef HANDLES_VECTOR_HPP_
#define HANDLES_VECTOR_HPP_

#include <cstdint>
#include <iterator>

#pragma pack(push, 1)

namespace smedley
{
namespace native
{
namespace handles
{

template <typename T>
struct vector
{
	struct iterator : std::iterator<std::bidirectional_iterator_tag, std::ptrdiff_t, T, T*, T&>
	{
		iterator(pointer ptr) : _ptr(ptr) {}

		reference operator*() const { return *_ptr; }
		pointer operator->() { return _ptr; }
		iterator &operator++() { _ptr++;  return *this; }
		iterator operator++(int) { iterator tmp = *this; ++(*this); return tmp; }
		iterator &operator--() { _ptr--;  return *this; }
		iterator operator--(int) { iterator tmp = *this; --(*this); return tmp; }
		friend bool operator==(const iterator &a, const iterator &b) { return a._ptr == b._ptr; }
		friend bool operator!=(const iterator &a, const iterator &b) { return a._ptr != b._ptr; }
	private:
		pointer _ptr;
	};

	T *_first;
	T *_last;
	T *_end;
	uint32_t field3;

	iterator begin() { return iterator(_first); }
	iterator end() { return iterator(_last); }

	T &operator[](std::size_t i) { return _first[i]; }
};

}
}
}

#pragma pack(pop)

#endif // HANDLES_BASIC_STRING_HPP_
