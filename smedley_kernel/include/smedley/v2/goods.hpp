#pragma once

#include <cstdint>
#include "../clausewitz/persistent.hpp"
#include "../clausewitz/types.hpp"
#include "../std/vector.hpp"

namespace smedley::v2
{

    /**
     * A collection of goods.
     */
    class CGoodsPool : public clausewitz::CPersistent
    {
    protected:
        /// @brief the ordinals of the goods types in _values
        uint8_t _index[64];
        /// @brief the quantities of the goods
        sstd::vector<clausewitz::fixed_point<int64_t,48,15>> _values;
    };

    static_assert(sizeof(CGoodsPool) == 0x58);

    class CGoodsProject : public clausewitz::CPersistent
    {
    protected:
        CGoodsPool _input;
        CGoodsPool _demand;
        clausewitz::fixed_point<int64_t,48,15> _money;
    };

}