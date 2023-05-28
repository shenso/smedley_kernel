#ifndef HANDLES_CTECHNOLOGY_VFTABLE_HPP_
#define HANDLES_CTECHNOLOGY_VFTABLE_HPP_

#include <cstdint>

#pragma pack(push, 1)

namespace smedley
{
namespace handles
{

struct CTechnology_vftable
{
	void *Destroy_CTechnology;
	void *Write;
	void *WriteMembers;
	void *Read;
	void *ReadMember;
	void *field5_0x14;
	void *GetLabel;
	void *GetShortLabel;
	void *IsValid;
	void *field9_0x24;
};

}
}

#pragma pack(pop)

#endif // HANDLES_CTECHNOLOGY_VFTABLE_HPP_
