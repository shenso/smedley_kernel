#ifndef HANDLES_CGAMESTATE_VFTABLE_HPP_
#define HANDLES_CGAMESTATE_VFTABLE_HPP_

#include <cstdint>

#pragma pack(push, 1)

namespace smedley
{
namespace handles
{

struct CGameState_vftable
{
	void *field0_0x0;
	void *field1_0x4;
	void *Write;
	void *field3_0xc;
	void *field4_0x10;
	void *field5_0x14;
	void *GetProvinceCount;
	void *GetCountryCount;
};

}
}

#pragma pack(pop)

#endif // HANDLES_CGAMESTATE_VFTABLE_HPP_
