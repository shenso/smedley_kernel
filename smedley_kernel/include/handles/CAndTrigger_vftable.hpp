#ifndef HANDLES_CANDTRIGGER_VFTABLE_HPP_
#define HANDLES_CANDTRIGGER_VFTABLE_HPP_

#include <cstdint>

#pragma pack(push, 1)

namespace smedley
{
namespace handles
{

struct CTrigger;
struct CEventScope;

struct CAndTrigger_vftable
{
	void *~CAndTrigger;
	void *Write;
	void *WriteMembers;
	void *Read;
	void *ReadMember;
	void *field5_0x14;
	bool (*Evaluate)(CTrigger * this, CEventScope * scope);
	void *field7_0x1c;
	void *field8_0x20;
	void *field9_0x24;
	void *field10_0x28;
	void *field11_0x2c;
	void *field12_0x30;
};

}
}

#pragma pack(pop)

#endif // HANDLES_CANDTRIGGER_VFTABLE_HPP_
