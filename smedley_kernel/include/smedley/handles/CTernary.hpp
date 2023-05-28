#ifndef HANDLES_TRIENODE_HPP_
#define HANDLES_TRIENODE_HPP_

#include <cstdint>
#include "handles/CList.hpp"
#include "handles/TrieNode.hpp"

#pragma pack(push, 1)

namespace smedley
{
namespace handles
{

template <typename T>
struct CTernary
{
	void **vftable;
	TrieNode<T> *root;
	bool useQueue;
	uint8_t field3;
	uint8_t field4;
	uint8_t field5;
	uint32_t count__;
	uint8_t field7;
	uint8_t field8;
	uint8_t field9;
	uint8_t field10;
	CList<T> elemQueue;
};

}
}

#pragma pack(pop)

#endif // HANDLES_TRIENODE_HPP_
