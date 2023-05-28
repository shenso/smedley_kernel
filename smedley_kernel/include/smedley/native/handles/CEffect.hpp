#ifndef HANDLES_CEFFECT_HPP_
#define HANDLES_CEFFECT_HPP_

#include <cstdint>
#include "CList.hpp"
#include "LexerToken.hpp"

#pragma pack(push, 1)

namespace smedley
{
namespace native
{
namespace handles
{

struct CEffect_vftable;
struct CEffect;

struct CEffect
{
	CEffect_vftable *vftable;
	uint32_t field1_0x4;
	CList<CEffect *> children;
	uint32_t field3_0x14;
	LexerToken type;
};

}
}
}

#pragma pack(pop)

#endif // HANDLES_CEFFECT_HPP_
