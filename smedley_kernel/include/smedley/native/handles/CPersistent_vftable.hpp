#ifndef HANDLES_CPERSISTENT_VFTABLE_HPP_
#define HANDLES_CPERSISTENT_VFTABLE_HPP_

#include <cstdint>

#pragma pack(push, 1)

namespace smedley
{
namespace native
{
namespace handles
{

struct CPersistent_vftable
{
	void *Destroy_CPersistent;
	void *Write;
	void *WriteMembers;
	void *Read;
	void *ReadMember;
	void *field5_0x14;
};

}
}
}

#pragma pack(pop)

#endif // HANDLES_CPERSISTENT_VFTABLE_HPP_
