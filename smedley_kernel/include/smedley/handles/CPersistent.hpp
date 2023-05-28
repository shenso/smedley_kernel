#ifndef HANDLES_CPERSISTENT_HPP_
#define HANDLES_CPERSISTENT_HPP_

#include <cstdint>

#pragma pack(push, 1)

namespace smedley
{
namespace handles
{

struct CPersistent_vftable;

struct CPersistent
{
	CPersistent_vftable * vftable;
};

}
}

#pragma pack(pop)

#endif // HANDLES_CPERSISTENT_HPP_
