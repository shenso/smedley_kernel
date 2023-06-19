#pragma once

#include "persistent.hpp"
#include <cstdint>

namespace smedley::clausewitz
{

    class CColor : public CPersistent
    {
        float _r;
        float _g;
        float _b;
        float _a;
        uint32_t _uk_0x18;
    };

    static_assert(sizeof(CColor) == 0x1c);

}