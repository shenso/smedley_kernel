#ifndef HANDLES_CMODIFIERENTRY_HPP_
#define HANDLES_CMODIFIERENTRY_HPP_

#include <cstdint>
#include "CFixedPoint.hpp"

#pragma pack(push, 1)

namespace smedley
{
namespace native
{
namespace handles
{

struct CModifierDefinition;

struct CModifierEntry
{
	CFixedPoint value;
	CModifierDefinition *type;
};

}
}
}

#pragma pack(pop)

#endif // HANDLES_CMODIFIERENTRY_HPP_
