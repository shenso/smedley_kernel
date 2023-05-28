#ifndef HANDLES_CEFFECT_VFTABLE_HPP_
#define HANDLES_CEFFECT_VFTABLE_HPP_

#include <cstdint>
#include "Lexeme.hpp"
#include "basic_string.hpp"

#pragma pack(push, 1)

namespace smedley
{
namespace handles
{

struct CEventScope;
struct CEffect;

struct CEffect_vftable
{
	void *Destroy_CEffect;
	void *Write;
	void *WriteMembers;
	void *Read;
	void *ReadMember;
	void *field5_0x14;
	void *GetType;
	void (__thiscall *ReadLexeme)(CEffect * _this, Lexeme lexeme);
	void *GetTooltip;
	basic_string<char> * (__thiscall *GetLocalization)(CEffect * _this, basic_string<char> * out_str, CEventScope * scope, basic_string<char> param_4);
	basic_string<char> * (__thiscall *GetScopeLabel)(CEffect * _this, basic_string<char> * out_str, CEventScope * scope);
	void (__thiscall *Execute)(CEffect * _this, CEventScope * scope);
	void *IsValid;
};

}
}

#pragma pack(pop)

#endif // HANDLES_CEFFECT_VFTABLE_HPP_
