#ifndef HANDLES_CHASHTABLE_HPP_
#define HANDLES_CHASHTABLE_HPP_

#include <cstdint>

#pragma pack(push, 1)

namespace smedley
{
namespace handles
{

template <typename T>
struct _BucketNode
{
	T val;
	_BucketNode<T> *next;
};


template <typename T>
struct CHashTable
{
	int elemCount;
	int bucketCount;
	_BucketNode<T> **buckets;
};

}
}

#pragma pack(pop)

#endif // HANDLES_CHASHTABLE_HPP_
