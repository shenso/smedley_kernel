#pragma once

#include "../clausewitz/persistent.hpp"

namespace smedley::v2
{

    class CProvinceValue : public clausewitz::CPersistent
    {
    public:
        int id;
        int value;
    };

    static_assert(sizeof(CProvinceValue) == 0x10);

}