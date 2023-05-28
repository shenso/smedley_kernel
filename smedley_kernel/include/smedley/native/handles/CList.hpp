#ifndef HANDLES_CLIST_HPP_
#define HANDLES_CLIST_HPP_

#include <cstdint>
#include "CListNode.hpp"

#pragma pack(push, 1)

namespace smedley
{
namespace native
{
namespace handles
{

template <typename T>
struct CList
{
	struct Iterator : std::iterator<std::bidirectional_iterator_tag, std::ptrdiff_t, T, T*, T&>
	{
		Iterator(CListNode<T> *node) : _node(node) {}

		reference operator*() const { return _node->val; }
		pointer operator->() { return &(_node->val); }
		Iterator &operator++() { _node = _node->next; return *this; }
		Iterator operator++(int) { Iterator tmp = *this; ++(*this); return tmp; }
		Iterator &operator--() { _node = _node->prev; return *this; }
		Iterator operator--(int) { Iterator tmp = *this; --(*this); return tmp; }
		friend bool operator==(const Iterator &a, const Iterator &b) { return a._node == b._node; }
		friend bool operator!=(const Iterator &a, const Iterator &b) { return a._node != b._node; }
	private:
		CListNode<T> *_node;
	};

	struct CListNode<T> *first;
	struct CListNode<T> *last;
	int count;
	uint32_t field3_0xc;

	Iterator begin() { return Iterator(first); };
	Iterator end() { return Iterator(nullptr); }
};

}
}
}

#pragma pack(pop)

#endif // HANDLES_CLIST_HPP_
