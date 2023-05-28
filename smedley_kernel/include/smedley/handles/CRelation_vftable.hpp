#ifndef HANDLES_CRELATION_VFTABLE_HPP_
#define HANDLES_CRELATION_VFTABLE_HPP_

#include <cstdint>

#pragma pack(push, 1)

namespace smedley
{
namespace handles
{

struct CRelation_vftable
{
	void *Destroy_CRelation;
	void *Write;
	void *WriteMembers;
	void *Read;
	void *ReadMember;
	void *field5_0x14;
	void *field6_0x18;
	void *GetType;
	void *field8_0x20;
	void *field9_0x24;
	void *Activate;
	void *Deactivate;
};

}
}

#pragma pack(pop)

#endif // HANDLES_CRELATION_VFTABLE_HPP_
