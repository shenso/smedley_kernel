#ifndef HANDLES_CMODIFIERDEFINITION_HPP_
#define HANDLES_CMODIFIERDEFINITION_HPP_

#include <cstdint>
#include "basic_string.hpp"

#pragma pack(push, 1)

namespace smedley
{
namespace handles
{

struct CModifierDefinition
{
	void **vftable;
	basic_string<char> name;
	LexerToken token;
	int id;
	uint8_t field4_0x28;
	uint8_t field5_0x29;
	uint8_t field6_0x2a;
	uint8_t field7_0x2b;
};

}
}

#pragma pack(pop)

#endif // HANDLES_CMODIFIERDEFINITION_HPP_
