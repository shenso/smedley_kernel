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
	struct CListNode<T> *first;
	struct CListNode<T> *last;
	int count;
	uint32_t field3;
};

}
}
}

#pragma pack(pop)

#endif // HANDLES_CLIST_HPP_
