#ifndef HANDLES_CGUITYPES_VFTABLE_HPP_
#define HANDLES_CGUITYPES_VFTABLE_HPP_

#include <cstdint>
#include "basic_string.hpp"

#pragma pack(push, 1)

namespace smedley
{
namespace native
{
namespace handles
{

struct CGuiType;
struct CGuiTypes;

struct CGuiTypes_vftable
{
	void *Destroy_CGuiTypes;
	CGuiType *(__thiscall *LookupString)(CGuiTypes *_this, basic_string<char> *key);
	CGuiType *(__thiscall *LookupBytes)(CGuiTypes *_this, char *key);
	void *UseQueue;
	void *ProcessQueue;
	void *Clear;
	void *Put;
};

}
}
}

#pragma pack(pop)

#endif // HANDLES_CGUITYPES_VFTABLE_HPP_
