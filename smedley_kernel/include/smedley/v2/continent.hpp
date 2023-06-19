#pragma once

#include "modifier.hpp"
#include "../clausewitz/color.hpp"
#include "../clausewitz/types.hpp"
#include "../std/string.hpp"

namespace smedley::v2
{

    class CContinent : public CModifier, public clausewitz::CList<int>
    {
        sstd::string _tag;
        sstd::string _name;
        clausewitz::CColor _color;
    };

    static_assert(sizeof(CContinent) == 0x94);

}