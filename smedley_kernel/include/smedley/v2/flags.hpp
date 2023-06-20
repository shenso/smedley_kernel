#pragma once

#include "../clausewitz/persistent.hpp"
#include "../clausewitz/types.hpp"
#include "../std/string.hpp"

namespace smedley::v2
{

    struct CFlag
    {
        sstd::string key;
        bool val;
    };

    static_assert(sizeof(CFlag) == 0x20);

    /**
     * A set of flag values. Stores the flags referenced by effects/triggers like
     * set_country_flag and has_country_flag.
     */
    class CFlags : public clausewitz::CTernary<CFlag *>, public clausewitz::CPersistent
    {
    };

    static_assert(sizeof(CFlags) == 0x2c);

}