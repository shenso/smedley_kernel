#ifndef HANDLES_CCULTURE_HPP_
#define HANDLES_CCULTURE_HPP_

#include <cstdint>
#include "CCountryTag.hpp"
#include "basic_string.hpp"
#include "CColor.hpp"
#include "CFixedPoint64.hpp"
#include "vector.hpp"

#pragma pack(push, 1)

namespace smedley
{
namespace handles
{

struct CCultureGroup;
struct CCulture_vftable;

struct CCulture
{
	CCulture_vftable * vtable;
	uint32_t field1_0x4;
	uint32_t field2_0x8;
	uint32_t field3_0xc;
	CCountryTag primaryTag;
	basic_string<char> name;
	basic_string<char> label;
	CCultureGroup * cultureGroup;
	CColor color;
	vector<basic_string<char>> firstNames;
	vector<basic_string<char>> lastNames;
	CFixedPoint64 radicalism;
};

}
}

#pragma pack(pop)

#endif // HANDLES_CCULTURE_HPP_
