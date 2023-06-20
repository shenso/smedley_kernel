#pragma once

#include <cstdint>
#include "../clausewitz/persistent.hpp"
#include "../clausewitz/types.hpp"
#include "../std/vector.hpp"

namespace smedley::v2
{

    class CTaxSetting : public clausewitz::CPersistent
    {
    protected:
        uint32_t _uk_0x8;
        uint32_t _uk_0xc;
        clausewitz::fixed_point<int64_t,48,15> _current_setting; // 10
        sstd::vector<clausewitz::fixed_point<int64_t,48,15>> _tax_income; // 18
        sstd::vector<clausewitz::fixed_point<int64_t,48,15>> _tax_eff; // 28
        sstd::vector<clausewitz::fixed_point<int64_t,48,15>> _tax_eff2; // 38
        clausewitz::fixed_point<int64_t,48,15> _total; // 48
        clausewitz::fixed_point<int64_t,48,15> _total2; // 50
        uint32_t _uk_0x58;
        uint32_t _uk_0x5c;
        clausewitz::fixed_point<int64_t,48,15> _range_limit_max; // 60
        clausewitz::fixed_point<int64_t,48,15> _range_limit_min; // 68
        int _max_tax; // 70
        int _min_tax; // 74
    };

    static_assert(sizeof(CTaxSetting) == 0x78);

}