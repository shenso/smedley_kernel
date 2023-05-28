#ifndef HANDLES_PAIR_HPP_
#define HANDLES_PAIR_HPP_

#include <cstdint>

#pragma pack(push, 1)

namespace smedley
{
namespace native
{
namespace handles
{

template <typename A, typename B>
struct pair
{
	A left;
	B right;
};

}
}
}

#pragma pack(pop)

#endif // HANDLES_PAIR_HPP_
