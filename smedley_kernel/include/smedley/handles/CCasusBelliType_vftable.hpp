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
	void *Destroy_CCasusBelliType;
	void *Write;
	void *WriteMembers;
	void *Read;
	void *ReadMember;
	void *field5_0x14;
	void *IsValidInternal__;
	void *IsValid;
	bool (*CanUse)(CCasusBelliType * _this, CEventScope * scope);
};

}
}

#pragma pack(pop)

#endif // HANDLES_CCASUSBELLITYPE_VFTABLE_HPP_
