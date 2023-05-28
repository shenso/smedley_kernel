#ifndef HANDLES_CEVENTSCOPE_VFTABLE_HPP_
#define HANDLES_CEVENTSCOPE_VFTABLE_HPP_

#include <cstdint>

#pragma pack(push, 1)

namespace smedley
{
namespace handles
{

struct CPersistent;
struct CWriter;

struct CEventScope_vftable
{
	void *field0_0x0;
	void *field1_0x4;
	void (__thiscall *Write)(CPersistent * _this, CWriter * writer);
	void *field3_0xc;
	void *field4_0x10;
	void *field5_0x14;
};

}
}

#pragma pack(pop)

#endif // HANDLES_CEVENTSCOPE_VFTABLE_HPP_
