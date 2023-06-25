#pragma once

#include <cstdint>
#include "../clausewitz/persistent.hpp"
#include "../clausewitz/types.hpp"
#include "../std/vector.hpp"

namespace smedley::v2
{

    class CCountry;

    class CDistributionSetting : public clausewitz::CPersistent
    {
    protected:
        clausewitz::fixed_point<int64_t,48,15> _temp_setting; // 8
        clausewitz::fixed_point<int64_t,48,15> _setting; // 10
        clausewitz::fixed_point<int64_t,48,15> _factor; // 18
        CCountry *_country; // 20
        uint32_t _unk_0x24;
        clausewitz::fixed_point<int64_t,48,15> _reserve; // 28
        clausewitz::fixed_point<int64_t,48,15> _max_value; // 30
        clausewitz::fixed_point<int64_t,48,15> _range_limit_max; // 38
        clausewitz::fixed_point<int64_t,48,15> _range_limit_min; // 40
        int _max_tax; // 48
        int _min_tax; // 4c
    };

    static_assert(sizeof(CDistributionSetting) == 0x50);

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

    class CTradeSetting : public clausewitz::CPersistent
    {
    protected:
        clausewitz::fixed_point<int64_t,48,15> _limit; // 8
        bool _do_buy; // 10
        bool _automate_trade; // 11
        uint32_t _unk_0x14;
    };

    static_assert(sizeof(CTradeSetting) == 0x18);

}