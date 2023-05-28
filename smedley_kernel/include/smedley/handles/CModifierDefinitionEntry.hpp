#ifndef HANDLES_CMODIFIERDEFINITIONENTRY_HPP_
#define HANDLES_CMODIFIERDEFINITIONENTRY_HPP_

#include <cstdint>

#pragma pack(push, 1)

namespace smedley
{
namespace handles
{

struct CModifierDefinition;

struct CModifierDefinitionEntry
{
	int num;
	CModifierDefinition * val;
};

}
}

#pragma pack(pop)

#endif // HANDLES_CMODIFIERDEFINITIONENTRY_HPP_
