#pragma once

#include "countryvalue.hpp"
#include "provincevalue.hpp"
#include "tag.hpp"
#include "../clausewitz/persistent.hpp"

namespace smedley::v2
{

    class CCountryAI
    {
    };

    class CAIStrategy : public clausewitz::CPersistent
    {
    protected:
        CCountryTag _tag; // 8
        CEU3Date _last_recalc; // 10 not 100% on this name
        uint32_t _unk_0x14;
        bool _initalized; // 18
        bool _is_static; // 19
        bool _consolidate; // 1a
        int _personality; // 1c
        clausewitz::CList<CProvinceValue *> _conquer_prov; // 20
        clausewitz::CList<CProvinceValue *> _colonize_prov; // 30
        clausewitz::CList<CCountryValue *> _threats; // 40
        clausewitz::CHashTable<CCountryTag, CCountryValue> _threat_table; // 50
        clausewitz::CList<CCountryValue *> _rivals; // 5c
        clausewitz::CHashTable<CCountryTag, CCountryValue> _rival_table; // 6c
        clausewitz::CList<CCountryValue *> _antagonize; // 78
        clausewitz::CHashTable<CCountryTag, CCountryValue> _antagonize_table; // 88
        clausewitz::CList<CCountryValue *> _befriend; // 94
        clausewitz::CHashTable<CCountryTag, CCountryValue> _befriend_table; // a4
        clausewitz::CList<CCountryValue *> _vassalize; // b0
        clausewitz::CHashTable<CCountryTag, CCountryValue> _vassalize_table; // c0
        clausewitz::CList<CCountryValue *> _access; // cc
        clausewitz::CHashTable<CCountryTag, CCountryValue> _access_table; // dc
        clausewitz::CList<CCountryValue *> _protect; // e8
        clausewitz::CHashTable<CCountryTag, CCountryValue> _protect_table; // f8
        clausewitz::CList<CCountryValue *> _pinatas; // 104
        clausewitz::CHashTable<CCountryTag, CCountryValue> _pinata_table; // 114
        uint32_t _unk_0x120;
        uint32_t _unk_0x124;
        uint32_t _unk_0x128;
        uint32_t _unk_0x12c;
        clausewitz::CList<CProvinceValue *> _building_prov; // 130
        clausewitz::CList<CCountryValue *> _war_targets; // 140
        int _status; // 150
        uint32_t _unk_0x154;
    };

    static_assert(sizeof(CAIStrategy) == 0x158);

}