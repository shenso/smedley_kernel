#ifndef HANDLES_C3DOBJECT_HPP_
#define HANDLES_C3DOBJECT_HPP_

#include <cstdint>

#pragma pack(push, 1)

namespace smedley
{
namespace handles
{

struct C3dObject
{
	void **vftable;
};

}
}

#pragma pack(pop)

#endif // HANDLES_C3DOBJECT_HPP_
