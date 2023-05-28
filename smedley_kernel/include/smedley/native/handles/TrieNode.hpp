#ifndef HANDLES_TRIENODE_HPP_
#define HANDLES_TRIENODE_HPP_

#include <cstdint>

#pragma pack(push, 1)

namespace smedley
{
namespace native
{
namespace handles
{

template <typename T>
struct TrieNode
{
	T val;
	int ch;
	TrieNode<T> *left;
	TrieNode<T> *right;
	TrieNode<T> *next;
};

}
}
}

#pragma pack(pop)

#endif // HANDLES_TRIENODE_HPP_
