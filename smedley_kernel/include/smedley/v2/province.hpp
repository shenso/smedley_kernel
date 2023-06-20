#pragma once

#include "construction.hpp"
#include "continent.hpp"
#include "eu3idler.hpp"
#include "flags.hpp"
#include "history.hpp"
#include "modifier.hpp"
#include "selectable.hpp"
#include "state.hpp"
#include "unit.hpp"
#include "../clausewitz/persistent.hpp"
#include "../clausewitz/types.hpp"
#include "../std/vector.hpp"

namespace smedley::v2
{

    class CEvent;

    class COwnerArea
    {
    protected:
        uint8_t _uk[0x60];
    public:
        virtual void Unk0();
        virtual void Unk1();
    };

    static_assert(sizeof(COwnerArea) == 0x64);

    class CProvinceTemplate
    {
    };

    /**
     * A building within a province such as a fort, naval base, or railroad.
     */
    class CProvinceBuilding : public CSelectable, public CModifierEntry, public clausewitz::CPersistent
    {
    protected:
        uint32_t _uk_0x18;
        uint32_t _uk_0x1c;
        clausewitz::CFixedPoint _quantity;
        clausewitz::CFixedPoint _quantity2;
    };

    static_assert(sizeof(CProvinceBuilding) == 0x28);

    /**
     * The basic data structure for in-game provinces. This base class handles
     * the province game logic.
     */
    class CProvince : public clausewitz::CPersistent, public CSelectable
    {
    protected:
        uint32_t _uk_0x10;
        sstd::vector<CEvent *> _events; // 14 fired events? 
        uint32_t _uk_0x24;
        uint32_t _uk_0x28;
        uint32_t _uk_0x2c;
        clausewitz::fixed_point<int64_t,48,15> _pop_growth; // 30
        uint32_t _uk_0x38;
        uint32_t _uk_0x3c;
        uint32_t _uk_0x40;
        uint32_t _uk_0x44;
        uint32_t _uk_0x48;
        int _total_raised_regiments; // 4c
        int _max_reinforceable_regiments; // 50
        CInGameIdler *_idler; // 54
        int _id; // 58
        CProvinceTemplate *_template; // 5c
        CProvinceHistory _history; // 60
        CProvinceModifier _modifier; // 84
        uint8_t _uk_0xb8[0x20];
        clausewitz::CList<CConstruction *> _constructions; // d8
        COwnerArea *_owner_area; // e8
        clausewitz::CList<void *> _leaders; // ec (not 100% sure on this one)
        clausewitz::CList<void *> _units; // fc
        uint32_t _uk_0x10c;
        uint32_t _uk_0x110;
        int _garrison; // 114
        sstd::vector<CProvinceBuilding *> _buildings; // 118
        CCountryTag _owner; // 128
        CCountryTag _controller; // 130
        uint32_t _uk_0x138;
        uint32_t _uk_0x13c;
        uint32_t _uk_0x140;
        uint32_t _uk_0x144;
        sstd::vector<CCountryTag> _core_tags; // 148
        uint32_t _uk_0x158;
        clausewitz::CList<void *> _regions; // 15c
        CContinent *_continent;
        uint32_t _uk_0x170;
        sstd::vector<int> _fow_setting; // 174 TODO: enum type
        uint32_t _uk_0x184;
        CState *_state; // 188
        uint32_t _uk_0x18c;
        int _colonial_level; // 190
        sstd::vector<void *> _pops; // 194;
        int _life_rating; // 1a4
        int _num_pops; // 1a8
        uint8_t _uk_0x1ac[0x10c];
        int _infrastructure; // 2b8
        CStaticModifier _static_modifier;
        uint32_t _uk_0x308;
        uint32_t _uk_0x30c;
        uint32_t _uk_0x310;
        uint32_t _uk_0x314;
        uint32_t _uk_0x318;
        uint32_t _uk_0x31c;
        CCrime *_crime; // 320
        uint32_t _uk_0x324;
        CFlags _flags; // 328
        CEU3Date _last_immigration_date; // 354
        CEU3Date _last_controller_change_date; // 358
        CUniqueUnitName _unit_names; // 35c
        uint32_t _uk_0x374;
        uint32_t _uk_0x378;
        uint32_t _uk_0x37c;
        uint32_t _uk_0x380;
        sstd::vector<CEvent *> _event_queue; // 384
        uint32_t _uk_0x394;
    };

    static_assert(sizeof(CProvince) == 0x398);

    /**
     * Class for provinces which are created by CMap.
     */
    class CMapProvince : public CProvince
    {
    };

}