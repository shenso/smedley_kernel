#ifndef HANDLES_OBJECTREFERENCE_HPP_
#define HANDLES_OBJECTREFERENCE_HPP_

#include <cstdint>

#pragma pack(push, 1)

namespace smedley
{
namespace handles
{

struct ObjectReference
{
	unsigned int type;
	unsigned int id;
};

}
}

#pragma pack(pop)

#endif // HANDLES_OBJECTREFERENCE_HPP_
