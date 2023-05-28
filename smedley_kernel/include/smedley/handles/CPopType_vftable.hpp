#ifndef HANDLES_CPOPTYPE_VFTABLE_HPP_
#define HANDLES_CPOPTYPE_VFTABLE_HPP_

#include <cstdint>

#pragma pack(push, 1)

namespace smedley
{
namespace handles
{

struct CPopType_vftable
{
	void *Destroy_CPopType;
	void *Write;
	void *WriteMembers;
	void *Read;
	void *ReadMember;
	void *field5_0x14;
	void *IsValid;
};

}
}

#pragma pack(pop)

#endif // HANDLES_CPOPTYPE_VFTABLE_HPP_
