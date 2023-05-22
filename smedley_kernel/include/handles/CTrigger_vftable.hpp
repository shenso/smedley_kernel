#ifndef HANDLES_CTRIGGER_VFTABLE_HPP_
#define HANDLES_CTRIGGER_VFTABLE_HPP_

#include <cstdint>

#pragma pack(push, 1)

namespace smedley
{
namespace handles
{

struct CTrigger;
struct CEventScope;

struct CTrigger_vftable
{
	void *~CTrigger;
	void *Write;
	void *WriteMembers;
	void *Read;
	void *ReadMember;
	void *field5_0x14;
	bool (*Evaluate)(CTrigger * this, CEventScope * scope);
	void *field7_0x1c;
	void *field8_0x20;
	void *ReadLexeme;
	void *GetLocalization;
	void *GetTooltip;
	void *field12_0x30;
};

}
}

#pragma pack(pop)

#endif // HANDLES_CTRIGGER_VFTABLE_HPP_
