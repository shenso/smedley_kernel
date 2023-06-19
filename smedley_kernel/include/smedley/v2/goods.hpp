#pragma once

#include <cstdint>
#include "../clausewitz/persistent.hpp"
#include "../clausewitz/types.hpp"
#include "../std/vector.hpp"

namespace smedley::v2
{

    class CGoodsPool : public clausewitz::CPersistent
    {
        uint8_t _index[64];
        sstd::vector<clausewitz::fixed_point<int64_t,48,15>> _values;
    };

    static_assert(sizeof(CGoodsPool) == 0x58);

    class CGoodsProject : public clausewitz::CPersistent
    {
        CGoodsPool _input;
        CGoodsPool _demand;
        clausewitz::fixed_point<int64_t,48,15> _money;
    };

}