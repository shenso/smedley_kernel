#ifndef HANDLES_CPOPLIST_HPP_
#define HANDLES_CPOPLIST_HPP_

#include <cstdint>
#include "CPop.hpp"

#pragma pack(push, 1)

namespace smedley
{
namespace native
{
namespace handles
{

struct CPopList
{
	struct Iterator : std::iterator<std::bidirectional_iterator_tag, std::ptrdiff_t, CPop, CPop *, CPop &>
	{
		Iterator(CPop *pop) : _pop(pop) {}

		reference operator*() const { return *_pop; }
		pointer operator->() { return _pop; }
		Iterator &operator++() { _pop = _pop->next; return *this; }
		Iterator operator++(int) { Iterator tmp = *this; ++(*this); return tmp; }
		Iterator &operator--() { _pop = _pop->prev; return *this; }
		Iterator operator--(int) { Iterator tmp = *this; --(*this); return tmp; }
		friend bool operator==(const Iterator &a, const Iterator &b) { return a._pop == b._pop; }
		friend bool operator!=(const Iterator &a, const Iterator &b) { return a._pop != b._pop; }
	private:
		CPop *_pop;
	};

	CPop *first;
	CPop *last;
	int count;
	uint32_t field3_0xc;

	Iterator begin() { return Iterator(first); }
	Iterator end() { return Iterator(nullptr); }
};

}
}
}

#pragma pack(pop)

#endif // HANDLES_CPOPLIST_HPP_
