#pragma once

#include "modifier.hpp"
#include "../clausewitz/color.hpp"
#include "../clausewitz/types.hpp"
#include "../std/string.hpp"

namespace smedley::v2
{

    /**
     * Represents a continent as defined in map/continents.txt
     * Is also a list of province ids
     */
    class CContinent : public CModifier, public clausewitz::CList<int>
    {
    protected:
        sstd::string _tag;
        sstd::string _name;
        clausewitz::CColor _color;
    };

    static_assert(sizeof(CContinent) == 0x94);

}