#pragma once

#include "../clausewitz/persistent.hpp"
#include "../clausewitz/types.hpp"
#include "../std/vector.hpp"

namespace smedley::v2
{

    template <typename V, typename K, int total>
    class CDataSpread : public clausewitz::CPersistent
    {
    protected:
        sstd::vector<V> _values;
        sstd::vector<K> _index;
    };

    static_assert(sizeof(CDataSpread<clausewitz::fixed_point<int64_t,48,15>,int,100>) == 0x28);

}