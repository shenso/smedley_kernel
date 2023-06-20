#pragma once

#include "goods.hpp"
#include "modifier.hpp"
#include "../util.hpp"
#include "../clausewitz/persistent.hpp"
#include "../clausewitz/types.hpp"
#include "../std/vector.hpp"

namespace smedley::v2
{

    class CProductionType;

    class CBuilding : public CModifierEntry, public clausewitz::CPersistent 
    {
    protected:
        int _type; // 10
        uint8_t _uk_0x14[0x48];
        clausewitz::CFixedPoint _construction_cost; // 5c
        CGoodsPool _goods_cost; // 60
        int _days_to_build; // b8
        bool _capital_only; // bc
        bool _is_port; // bd
        bool _one_per_state; // be
        uint32_t _uk_0xc0;
        int _max_level; // c4
        sstd::vector<int> _colonial_points; // c8
        bool _produced_sail_boats; // d8
        bool _produced_steam_boats; // d9
        clausewitz::CFixedPoint _colonial_range; // dc
        bool _is_on_map; // e0
        bool _is_visible; // e1
        uint32_t _uk_0xe4;
        uint32_t _uk_0xe8;
        uint32_t _uk_0xec;
        uint32_t _uk_0xf0;
        uint32_t _uk_0xf4;
        clausewitz::CList<sstd::string> _prerequisites; // f8
        uint32_t _uk_0x108;
        uint32_t _uk_0x10c;
        uint32_t _uk_0x110;
        uint32_t _uk_0x114;
        clausewitz::CList<sstd::string> _not_if_already_exists; // 118
        bool _confirm; // 128
        bool _orientation; // 129
        CProductionType *_prod_type; // 12c
        bool _default_enabled; // 130
        bool _is_province_building; // 131
        int _id; // 134
        bool _pops_can_build; // 138
        bool _spawns_railways; // 139
        bool _is_advanced_factory; // 13a
        clausewitz::CFixedPoint _infrastructure; // 13c
    };

    static_assert(sizeof(CBuilding) == 0x140);

}