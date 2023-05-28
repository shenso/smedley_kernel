#ifndef HANDLES_CPOPLIST_HPP_
#define HANDLES_CPOPLIST_HPP_

#include <cstdint>

#pragma pack(push, 1)

namespace smedley
{
namespace handles
{

struct CPop;

struct CPopList
{
	CPop * first;
	CPop * last;
	int count;
	uint32_t field3_0xc;
};

}
}

#pragma pack(pop)

#endif // HANDLES_CPOPLIST_HPP_
