#pragma once

#include "building.hpp"
#include "modifier.hpp"
#include "mtth.hpp"
#include "trigger.hpp"
#include "unit.hpp"
#include "../clausewitz/persistent.hpp"
#include "../clausewitz/types.hpp"
#include "../std/string.hpp"
#include "../std/vector.hpp"

namespace smedley::v2
{

    class CTechnologyFolder
    {
    };

    class CTechStatistics : public clausewitz::CPersistent
    {
    protected:
        sstd::vector<int> _max_building_level; // 8
        clausewitz::CFixedPoint _factory_cost; // 18
        clausewitz::CFixedPoint _digin_cap; // 1c
        clausewitz::CFixedPoint _land_attrition; // 20
        clausewitz::CFixedPoint _naval_attrition; // 24
        clausewitz::CFixedPoint _supply_range; // 28
        clausewitz::CFixedPoint _supply_limit; // 2c
        clausewitz::CFixedPoint _repair_rate; // 30
        clausewitz::CFixedPoint _plurality; // 34
        clausewitz::CFixedPoint _combat_width; // 38
        clausewitz::CFixedPoint _morale; // 3c
        clausewitz::CFixedPoint _reinforce_rate; // 40
        clausewitz::CFixedPoint _soldier_to_pop_loss; // 44
        clausewitz::CFixedPoint _regular_experience_level; // 48
        clausewitz::CFixedPoint _mobilization_size; // 4c
        clausewitz::CFixedPoint _mobilization_economy_impact; // 50
        clausewitz::CFixedPoint _colonial_life_rating; // 54
        clausewitz::CFixedPoint _cb_creation_speed; // 58
        clausewitz::CFixedPoint _colonial_points; // 5c
        clausewitz::CFixedPoint _administrative_efficiency; // 60
        clausewitz::CFixedPoint _education_efficiency; // 64
        clausewitz::CFixedPoint _loan_interest; // 68
        clausewitz::CFixedPoint _war_exhaustion; // 6c
        clausewitz::CFixedPoint _military_tactics; // 70
        clausewitz::CFixedPoint _seperatism; // 74
        clausewitz::CFixedPoint _influence; // 78
        clausewitz::CFixedPoint _increase_research; // 7c
        clausewitz::fixed_point<int64_t,48,15> _pop_growth; // 80
        sstd::vector<clausewitz::CFixedPoint> _rebel_org_gain; // 88
        sstd::vector<int> _activate_trade_goods; // 98
        uint8_t _unk_0xa8[0x30];
        clausewitz::fixed_point<int64_t,48,15> _tax_efficiency; // d8
        clausewitz::fixed_point<int64_t,48,15> _rgo_input; // e0
        clausewitz::fixed_point<int64_t,48,15> _rgo_output; // e8
        clausewitz::fixed_point<int64_t,48,15> _rgo_throughput; // f0
        clausewitz::fixed_point<int64_t,48,15> _unk_0xf8;
        clausewitz::fixed_point<int64_t,48,15> _factory_input;
        clausewitz::fixed_point<int64_t,48,15> _factory_output;
        clausewitz::fixed_point<int64_t,48,15> _factory_throughput;
        clausewitz::fixed_point<int64_t,48,15> _unk_0x118;
        clausewitz::fixed_point<int64_t,48,15> _artisan_input;
        clausewitz::fixed_point<int64_t,48,15> _artisan_output;
        clausewitz::fixed_point<int64_t,48,15> _artisan_throughput;
        uint8_t _unk_0x138[0x28];
        sstd::vector<clausewitz::CFixedPoint> _rgo_size; // 160
        sstd::vector<clausewitz::CFixedPoint> _rgo_goods_input;
        sstd::vector<clausewitz::CFixedPoint> _rgo_goods_output;
        sstd::vector<clausewitz::CFixedPoint> _rgo_goods_throughput;
        sstd::vector<clausewitz::CFixedPoint> _unk_0x1a0;
        sstd::vector<clausewitz::CFixedPoint> _factory_goods_input;
        sstd::vector<clausewitz::CFixedPoint> _factory_goods_output;
        sstd::vector<clausewitz::CFixedPoint> _factory_goods_throughput;
        sstd::vector<clausewitz::CFixedPoint> _unk_0x1e0;
        sstd::vector<clausewitz::CFixedPoint> _artisan_goods_input;
        sstd::vector<clausewitz::CFixedPoint> _artisan_goods_output;
        uint8_t _unk_0x210[0x60];
        clausewitz::CFixedPoint _mine_rgo_eff;
        clausewitz::CFixedPoint _farm_rgo_eff;
        clausewitz::CFixedPoint _mine_rgo_size;
        clausewitz::CFixedPoint _farm_rgo_size;
        int _max_national_foci;
        uint32_t _unk_0x284;
        clausewitz::CFixedPoint _prestige;
        clausewitz::CFixedPoint _permanent_prestige;
        clausewitz::CFixedPoint _colonial_prestige;
        clausewitz::CFixedPoint _unk_0x294;
        clausewitz::CFixedPoint _diplomatic_points;
        clausewitz::CFixedPoint _colonial_migration;
        bool _has_gas_attack;
        bool _has_gas_defense;
    };

    static_assert(sizeof(CTechStatistics) == 0x2a8);

    class CTechnology : public CTechStatistics
    {
    protected:
        int _token; // 0x2a8
        sstd::string _name;
        sstd::string _label;
        int _id;
        int _cost;
        uint32_t _unk_0x2ec;
        CAndTrigger _allow;
        bool _change;
        CTechnologyFolder *_folder;
        sstd::string _area;
        uint32_t _unk_0x330;
        uint32_t _unk_0x334;
        uint32_t _unk_0x338;
        uint32_t _unk_0x33c;
        int _year;
        int _difficulty;
        CSubUnitDefinition *_deactivate_unit;
        CSubUnitDefinition *_activate_unit;
        CCrime *_enable_crime;
        CBuilding *_activate_building;
        bool _can_upgrade;
        uint32_t _unk_0x35c;
        uint32_t _unk_0x360;
        uint32_t _unk_0x364;
        uint32_t _unk_0x368;
        clausewitz::CFixedPoint _shared_prestige;
        CMeanTimeToHappen _ai_chance;
        bool _unciv_military;
    };

    static_assert(sizeof(CTechnology) == 0x390);

    class CInvention : public CStaticModifier
    {
    protected:
        int _token; // 4c
        int _id; // 50
        CAndTrigger _limit; // 54
        CTechnology _effect; // 70
        CAdditiveMTTH _chance; // 400
        uint32_t _unk_0x430;
        bool _newsworthy; // 434
    };

    static_assert(sizeof(CInvention) == 0x438);

    class CTechnologyStatus
    {
    };

}
