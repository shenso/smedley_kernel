#ifndef HANDLES_CAIMTTHCHANCE_HPP_
#define HANDLES_CAIMTTHCHANCE_HPP_

#include <cstdint>
#include <handles/vector.hpp>

#pragma pack(push, 1)

namespace smedley
{
namespace handles
{

struct CMTTHModifier;

struct CAIMTTHChance
{
	void **vftable;
	uint32_t field1_0x4;
	int baseDays;
	vector<CMTTHModifier *> modifiers;
	int baseChance__;
};

}
}

#pragma pack(pop)

#endif // HANDLES_CAIMTTHCHANCE_HPP_
