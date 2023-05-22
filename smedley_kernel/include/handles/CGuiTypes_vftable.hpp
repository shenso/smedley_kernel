#ifndef HANDLES_CGUITYPES_VFTABLE_HPP_
#define HANDLES_CGUITYPES_VFTABLE_HPP_

#include <cstdint>
#include <handles/basic_string.hpp>

#pragma pack(push, 1)

namespace smedley
{
namespace handles
{

struct CGuiType;
struct char;
struct CGuiTypes;

struct CGuiTypes_vftable
{
	void *~CGuiTypes;
	CGuiType * (*LookupString)(CGuiTypes * this, basic_string<char> * key);
	CGuiType * (*LookupBytes)(CGuiTypes * this, char * key);
	void *UseQueue;
	void *ProcessQueue;
	void *Clear;
	void *Put;
};

}
}

#pragma pack(pop)

#endif // HANDLES_CGUITYPES_VFTABLE_HPP_
