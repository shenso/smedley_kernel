#ifndef HANDLES_CLISTNODE_HPP_
#define HANDLES_CLISTNODE_HPP_

#include <cstdint>

#pragma pack(push, 1)

namespace smedley
{
namespace native
{
namespace handles
{

template <typename T>
struct CListNode
{
	T val;
	struct CListNode<T> *prev;
	struct CListNode<T> *next;
	uint32_t field3;
};

}
}
}

#pragma pack(pop)

#endif // HANDLES_CLISTNODE_HPP_
