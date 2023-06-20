#pragma once

#include "../clausewitz/persistent.hpp"
#include "../clausewitz/types.hpp"
#include "../std/string.hpp"

namespace smedley::v2
{

    struct CVariable
    {
        sstd::string key;
        clausewitz::CFixedPoint val;
    };

    static_assert(sizeof(CVariable) == 0x20);

    /**
     * A dictionary of fixed point values. Stores the variables referenced by effects/triggers
     * like set_variable and check_variable.
     */
    class CVariables : public clausewitz::CTernary<CVariable *>, public clausewitz::CPersistent
    {
    };

    static_assert(sizeof(CVariables) == 0x2c);

}