#ifndef HANDLES_CCOUNTRY_VFTABLE_HPP_
#define HANDLES_CCOUNTRY_VFTABLE_HPP_

#include <cstdint>

#pragma pack(push, 1)

namespace smedley
{
namespace native
{
namespace handles
{

struct CCountry_vftable
{
	void *Destroy_CCountry;
	void *Write;
	void *WriteMembers;
	void *Read;
	void *ReadMember;
	void *field5_0x14;
	void *field6_0x18;
	void *field7_0x1c;
};

}
}
}

#pragma pack(pop)

#endif // HANDLES_CCOUNTRY_VFTABLE_HPP_
