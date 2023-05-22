#ifndef HANDLES_CEFFECT_VFTABLE_HPP_
#define HANDLES_CEFFECT_VFTABLE_HPP_

#include <cstdint>
#include <handles/Lexeme.hpp>
#include <handles/basic_string.hpp>

#pragma pack(push, 1)

namespace smedley
{
namespace handles
{

struct CEventScope;
struct CEffect;

struct CEffect_vftable
{
	void *~CEffect;
	void *Write;
	void *WriteMembers;
	void *Read;
	void *ReadMember;
	void *field5_0x14;
	void *GetType;
	void (*ReadLexeme)(CEffect * this, Lexeme lexeme);
	void *GetTooltip;
	basic_string<char> * (*GetLocalization)(CEffect * this, basic_string<char> * out_str, CEventScope * scope, basic_string<char> param_4);
	basic_string<char> * (*GetScopeLabel)(CEffect * this, basic_string<char> * out_str, CEventScope * scope);
	void (*Execute)(CEffect * this, CEventScope * scope);
	void *IsValid;
};

}
}

#pragma pack(pop)

#endif // HANDLES_CEFFECT_VFTABLE_HPP_
