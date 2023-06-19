#pragma once

#include "../clausewitz/persistent.hpp"
#include "../clausewitz/types.hpp"
#include "../std/string.hpp"

namespace smedley::v2
{

    class CFlag
    {
        sstd::string _key;
        bool _val;
    };

    static_assert(sizeof(CFlag) == 0x20);

    class CFlags : public clausewitz::CTernary<CFlag *>, public clausewitz::CPersistent
    {
    };

    static_assert(sizeof(CFlags) == 0x2c);

}