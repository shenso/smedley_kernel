#ifndef HANDLES_CCASUSBELLITYPE_VFTABLE_HPP_
#define HANDLES_CCASUSBELLITYPE_VFTABLE_HPP_

#include <cstdint>

#pragma pack(push, 1)

namespace smedley
{
namespace handles
{

struct CEventScope;
struct CCasusBelliType;

struct CCasusBelliType_vftable
{
	void *~CCasusBelliType;
	void *Write;
	void *WriteMembers;
	void *Read;
	void *ReadMember;
	void *field5_0x14;
	void *IsValidInternal?;
	void *IsValid;
	bool (*CanUse)(CCasusBelliType * this, CEventScope * scope);
};

}
}

#pragma pack(pop)

#endif // HANDLES_CCASUSBELLITYPE_VFTABLE_HPP_
