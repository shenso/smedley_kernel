#pragma once

#include "ai.hpp"
#include "dataspread.hpp"
#include "distributionsettings.hpp"
#include "flags.hpp"
#include "history.hpp"
#include "modifier.hpp"
#include "politics.hpp"
#include "rules.hpp"
#include "tag.hpp"
#include "tech.hpp"
#include "variables.hpp"
#include "../clausewitz/color.hpp"
#include "../clausewitz/persistent.hpp"
#include "../clausewitz/types.hpp"
#include "../std/pair.hpp"
#include "../std/string.hpp"
#include "../std/vector.hpp"

namespace smedley::v2
{

    class CColonialDistanceTracker;
    class CEvent;

    /**
     * CCountry corresponds a playable country in Victoria 2. It also includes
     * entities not commonly though of as countries, such as the Rebel Country (owner
     * of the rebel units and placeholder for rebel controlled territory), as well as 
     * the NULL country (owner of the "unowned" uncolonized territory in-game).
     */
    class CCountry : public clausewitz::CPersistent
    {
    protected:
        sstd::vector<CEvent *> _events; // 8 fired events?
        uint32_t _unk_0x18;
        CCountryTag _tag; // 1c
        uint32_t _unk_0x24;
        uint32_t _unk_0x28;
        uint32_t _unk_0x2c;
        bool _unk_0x30;
        bool _is_great_power; // 31
        sstd::vector<void *> _unk_0x34;
        uint32_t _unk_0x44;
        uint32_t _unk_0x48;
        uint32_t _unk_0x4c;
        uint32_t _unk_0x50;
        clausewitz::CList<sstd::pair<sstd::string, sstd::string>> _unk_0x54; // type may be incorrect. localisation keys?
        uint32_t _unk_0x64;
        sstd::vector<CEvent *> _event_queue; // 68
        CEU3Date _next_quarterly_pulse; // 78
        CEU3Date _next_yearly_pulse; // 7c
        uint32_t _unk_0x80;
        uint32_t _unk_0x84;
        uint32_t _unk_0x88;
        uint32_t _unk_0x8c;
        uint32_t _unk_0x90;
        uint32_t _unk_0x94;
        int _campaign_counter; // 98
        CEU3Date _last_reform_date; // 9c
        sstd::vector<CTaxSetting *> _tax_settings; // a0
        clausewitz::CVector2<sstd::vector<clausewitz::fixed_point<int64_t,48,15>>> _expenses; // b0
        clausewitz::CVector2<sstd::vector<clausewitz::fixed_point<int64_t,48,15>>> _incomes; // d0
        sstd::string _unk_0xf0;
        CColonialDistanceTracker *_colonial_distance_tracker; // 10c
        //clausewitz::CHashTable<sstd::string, void *> _unk_0x110;
        uint32_t _unk_0x110;
        uint32_t _unk_0x114;
        uint32_t _unk_0x118;
        uint32_t _unk_0x11c;
        bool _mobilize; // 120
        uint32_t _unk_0x124;
        uint32_t _unk_0x128;
        uint32_t _unk_0x12c;
        uint32_t _unk_0x130;
        uint32_t _unk_0x134;
        clausewitz::fixed_point<int64_t,48,15> _share_factor; // 138
        uint8_t _unk_0x140[0x44];
        sstd::vector<sstd::string> _ignored_decisions; // 184
        uint32_t _unk_0x194;
        uint32_t _unk_0x198;
        uint32_t _unk_0x19c;
        uint32_t _unk_0x1a0;
        uint32_t _unk_0x1a4;
        clausewitz::CFixedPoint _plurality; // 1a8
        clausewitz::CFixedPoint _revanchism; // 1ac
        CFlags _flags; // 1b0
        CVariables _variables; // 1dc
        CCountryAI *_ai; // 208
        CAIStrategy _ai_hard_strategy; // 20c
        CAIStrategy _ai_default_strategy; // 364
        CEU3Date _last_party_change; // 4bc
        CEU3Date _last_lost_war; // 4c0
        uint8_t _tech_projects[16]; // 4c4
        uint32_t _unk_0x4d4;
        clausewitz::CList<CTimedModifier *> _timed_modifiers; // 4d8
        clausewitz::CList<CStaticModifier *> _static_modifiers; // 4e8
        clausewitz::CList<CInvention *> _active_inventions; // 4f8
        clausewitz::CList<CInvention *> _potential_inventions; // 508
        clausewitz::CList<CInvention *> _illegal_inventions; // 518
        CStaticModifier _unk_0x528;
        CStaticModifier _unk_0x574;
        CStaticModifier _unk_0x5c0;
        CStaticModifier _unk_0x60c;
        bool _auto_assign_leaders; // 658
        bool _auto_create_leaders; // 659
        clausewitz::CFixedPoint _diplomatic_points; // 65c
        CEU3Date _last_election;
        CEU3Date _election_date;
        CEU3Date _last_rebel_acceptance;
        clausewitz::CList<CCountryDate *> _fow_lifted; // 66c
        uint32_t _unk_0x67c;
        clausewitz::CFixedPoint _war_exhaustion; // 680
        CStaticModifier _unk_0x684;
        CModifier _unk_0x6d0;
        uint32_t _unk_0x700;
        uint32_t _unk_0x704;
        uint32_t _unk_0x708;
        uint32_t _unk_0x70c;
        uint32_t _unk_0x710;
        uint32_t _unk_0x714;
        uint32_t _unk_0x718;
        CModifier _unk_0x71c;
        uint32_t _unk_0x74c;
        uint32_t _unk_0x750;
        uint32_t _unk_0x754;
        uint32_t _unk_0x758;
        uint32_t _unk_0x75c;
        uint32_t _unk_0x760;
        uint32_t _unk_0x764;
        CModifier _unk_0x768;
        uint32_t _unk_0x798;
        uint32_t _unk_0x79c;
        uint32_t _unk_0x7a0;
        uint32_t _unk_0x7a4;
        uint32_t _unk_0x7a8;
        uint32_t _unk_0x7ac;
        uint32_t _unk_0x7b0;
        clausewitz::CList<CUnit *> _units; // 7b4
        uint32_t _unk_0x7c4;
        uint32_t _unk_0x7c8;
        uint32_t _unk_0x7cc;
        clausewitz::fixed_point<int64_t,48,15> _leadership; // 7d0
        int _num_colonial_provinces; // 7d8
        uint32_t _unk_0x7dc;
        CModifier _unk_0x7e0;
        uint32_t _unk_0x810;
        uint32_t _unk_0x814;
        uint32_t _unk_0x818;
        uint32_t _unk_0x81c;
        uint32_t _unk_0x820;
        uint32_t _unk_0x824;
        uint32_t _unk_0x828;
        clausewitz::CList<CParty *> _parties; // 82c
        clausewitz::CList<CParty *> _active_parties; // 83c
        CParty *_ruling_party; // 84c
        sstd::vector<CIssue *> _social_reforms; // 850
        sstd::vector<CIssue *> _political_reforms; // 860
        sstd::vector<CIssue *> _military_reforms; // 870
        sstd::vector<CIssue *> _economic_reforms; // 880
        sstd::vector<CIssue *> _policies; // 890
        sstd::vector<CIssue *> _unk_0x8a0; // enacted reforms?
        CUpperHouse _upper_house; // 8b0
        CDataSpread<clausewitz::fixed_point<int64_t,48,15>,int,100> _unk_0x8d0; // people or voter ideologies?
        CDataSpread<clausewitz::fixed_point<int64_t,48,15>,int,100> _important_issues;
        clausewitz::CColor _color; // 920
        uint32_t _unk_0x93c; // color flag?
        sstd::vector<clausewitz::CColor> _colors; // 940
        uint8_t _unk_0x950[0x64];
        CCountryHistory _history; // 9b4
        sstd::vector<int> _owned_provinces; // 9d8
        clausewitz::CList<int> _controlled_provinces; // 9e8
        clausewitz::CList<int> _core_provinces; // 9f8
        clausewitz::CList<int> _unk_0xa08;
        uint8_t _unk_0xa18[0x30];
        CModifier _modifiers; // a48
        CModifier _unk_0xa78;
        CRule _rules; // aa8
        CTechnologyStatus *_status; // bcc
        CGovernment *_government;  // bd0
    };

    //static_assert(sizeof(CCountry) == 0xbd8);

}