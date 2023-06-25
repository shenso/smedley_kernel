#pragma once

#include "ai.hpp"
#include "dataspread.hpp"
#include "distributionsettings.hpp"
#include "flags.hpp"
#include "history.hpp"
#include "mobilization.hpp"
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

    class CActiveMission;
    class CBank;
    class CCasusBelliGeneration;
    class CColonialDistanceTracker;
    class CCreditor;
    class CCulture;
    class CDiplomaticAction;
    class CDiplomacyStatus;
    class CEvent;
    class CGraphicalCultureType;
    class CLeader;
    class CNationalValue;
    class CNudgeIdler;
    class CPopMovement;
    class CRailroadChunk;
    class CRallyPoint;
    class CRegion;
    class CState;

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
        uint32_t _unk_0x950;
        uint32_t _unk_0x954;
        uint32_t _unk_0x958;
        uint32_t _unk_0x95c;
        uint32_t _unk_0x960;
        uint32_t _unk_0x964;
        uint32_t _unk_0x968;
        uint32_t _unk_0x96c;
        uint32_t _unk_0x970;
        uint32_t _unk_0x974;
        uint32_t _unk_0x978;
        uint32_t _unk_0x97c;
        uint32_t _unk_0x980;
        uint32_t _unk_0x984;
        uint32_t _unk_0x988;
        uint32_t _unk_0x98c;
        uint32_t _unk_0x990;
        uint32_t _unk_0x994;
        uint32_t _unk_0x998;
        uint32_t _unk_0x99c;
        uint32_t _unk_0x9a0;
        uint32_t _unk_0x9a4;
        uint32_t _unk_0x9a8;
        uint32_t _unk_0x9ac;
        uint32_t _unk_0x9b0;
        CCountryHistory _history; // 9b4
        sstd::vector<int> _owned_provinces; // 9d8
        clausewitz::CList<int> _controlled_provinces; // 9e8
        clausewitz::CList<int> _core_provinces; // 9f8
        clausewitz::CList<int> _unk_0xa08;
        uint32_t _unk_0xa18;
        uint32_t _unk_0xa1c;
        uint32_t _unk_0xa20;
        uint32_t _unk_0xa24;
        uint32_t _unk_0xa28;
        uint32_t _unk_0xa2c;
        uint32_t _unk_0xa30;
        uint32_t _unk_0xa34;
        uint32_t _unk_0xa38;
        uint32_t _unk_0xa3c;
        uint32_t _unk_0xa40;
        uint32_t _unk_0xa44;
        CModifier _modifiers; // a48
        CModifier _unk_0xa78;
        CRule _rules; // aa8
        CTechnologyStatus *_tech_status; // bcc
        CGovernment *_government; // bd0
        clausewitz::CList<v2::CLeader *> _leaders; // bd4
        int _capital_province_id; // be4
        sstd::vector<v2::CDiplomacyStatus *> _diplomatic_statuses; // be8
        CActiveMission *_active_mission; // bf8
        uint8_t _unk_0xbfc[0xa4];
        CEU3Date _unk_0xca0;
        sstd::string _unk_0xca4;
        sstd::string _last_mission; // cc0
        CNudgeIdler *_nudge_idler; // cd4
        CGraphicalCultureType *_graphical_culture; // ce0
        clausewitz::CList<CDiplomaticAction *> _diplomatic_actions; // ce4
        bool _is_substate; // cf4
        bool _is_vassal; // cf5
        CCountryTag _overlord; // cf8
        uint8_t _unk_0xd00[0x38];
        sstd::vector<CCountryTag> _vassals; // d38
        sstd::vector<CCountryTag> _unk_0xd48;
        sstd::vector<CCountryTag> _allies; // d58
        sstd::vector<CCountryTag> _unk_0xd68; // also allies?
        sstd::vector<CCountryTag> _guaranteed; // d78
        sstd::vector<CCountryTag> _neighbors; // d88
        sstd::vector<CCountryTag> _unk_0xd98;
        uint32_t _unk_0xda8;
        uint32_t _unk_0xdac;
        uint32_t _unk_0xdb0;
        uint32_t _unk_0xdb4;
        sstd::vector<int> _unk_0xdb8;
        uint8_t _unk_0xdc8[0x38];
        sstd::vector<int> _slider_locks;
        uint32_t _unk_0xe10;
        sstd::vector<CCountryTag> _historical_friends; // e14
        uint32_t _unk_0xe24;
        uint32_t _unk_0xe28;
        uint32_t _unk_0xe2c;
        uint32_t _unk_0xe30;
        uint32_t _unk_0xe34;
        uint32_t _unk_0xe38;
        clausewitz::CFixedPoint _research_points; // e3c
        int _tech_school_id; // e40
        clausewitz::CList<CState *> _states; // e44
        clausewitz::CList<CCulture *> _accepted_cultures; // e54
        CCulture *_primary_culture; // e64
        uint32_t _unk_0xe68;
        uint32_t _unk_0xe6c;
        uint32_t _unk_0xe70;
        uint32_t _unk_0xe74;
        clausewitz::fixed_point<int64_t,48,15> _treasury; // e78
        clausewitz::fixed_point<int64_t,48,15> _treasury_delta; // e80
        CBank *_bank; // e88
        sstd::vector<CCreditor *> _creditors; // e8c
        CEU3Date _last_bankruptcy_date; // e9c
        clausewitz::CFixedPoint _prestige; // ea0
        uint8_t _unk_0xea4[0x20];
        CGoodsPool _land_supply_cost; // ec4
        CGoodsPool _naval_supply_cost; // f1c
        CGoodsPool _naval_need; // f74
        CGoodsPool _unk_0xfcc;
        CGoodsPool _unk_0x1024;
        CGoodsPool _unk_0x107c;
        CGoodsPool _unk_0x10d4;
        CGoodsPool _unk_0x112c;
        CGoodsPool _stockpile; // 118c
        CGoodsPool _stockpile_remaining; // 11dc
        sstd::vector<CDistributionSetting *> _spending_settings; // 1234
        CGoodsPool _unk_0x1244; // domestic purchases?
        bool _buy_from_stockpile; // 129c
        sstd::vector<CTradeSetting> _trade_settings; // 12a0;
        CNationalValue *_national_value; // 12b0
        uint8_t _unk_0x12b4[0x1c];
        bool _is_civilized; // 12d0
        uint8_t _unk_0x12d4[0x11c];
        sstd::vector<int> _unk_0x13f0; // diplomatic influence?
        CEU3Date _unk_0x1400;
        int _ranking; // 1404
        int _military_ranking; // 1408
        int _industrial_ranking; // 140c
        int _prestige_ranking; // 1410
        uint32_t _unk_0x1414;
        sstd::vector<CCountryTag> _spherelings; // 1418
        CCountryTag _sphere_leader; // 1428
        clausewitz::CFixedPoint _infamy; // 1430
        uint32_t _unk_0x1434;
        uint32_t _unk_0x1438;
        uint32_t _unk_0x143c;
        clausewitz::fixed_point<int64_t,48,15> _tariffs; // 1440
        clausewitz::fixed_point<int64_t,48,15> _trade_cap_army; // 1448
        clausewitz::fixed_point<int64_t,48,15> _trade_cap_naval; // 1450
        clausewitz::fixed_point<int64_t,48,15> _trade_cap_projects; // 1458
        clausewitz::fixed_point<int64_t,48,15> _min_spend_on_land_units; // 1460
        clausewitz::fixed_point<int64_t,48,15> _min_spend_on_naval_units; // 1468
        clausewitz::fixed_point<int64_t,48,15> _min_spend_on_constructions; // 1470
        uint8_t _unk_0x1478[0x24];
        clausewitz::CList<CRegion *> _colonies; // 149c
        clausewitz::CList<sstd::string> _first_names; // 14ac
        clausewitz::CList<sstd::string> _last_names; // 14bc
        uint8_t _unk_0x14cc[0x18];
        sstd::vector<void *> _unk_0x14e4;
        sstd::vector<void *> _unk_0x14f4;
        uint8_t _unk_0x1504[0x34];
        clausewitz::fixed_point<int64_t,48,15> _overseas_penalty; // 1538
        uint32_t _unk_0x1540;
        bool _is_releasable_vassal; // 1544
        uint8_t _unk_0x1548[0x18];
        clausewitz::fixed_point<int64_t,48,15> _tax_base; // 1560
        uint32_t _unk_0x1568;
        CCasusBelliGeneration *_cb_generation; // 156c
        sstd::vector<CRallyPoint *> _rally_points; // 1570
        sstd::vector<clausewitz::fixed_point<int64_t,48,15>> _foreign_investment; // 1580
        sstd::vector<CPopMovement *> _movements; // 1590
        uint8_t _unk_15a0[0xc];
        sstd::vector<CRailroadChunk *> _railroad_chunks; // 15ac
        bool _railroad_cache_invalid; // 15bc
        uint8_t _unk_0x15c0[0x1c];
        sstd::vector<CMobilizationSchedule> _scheduled_mobilizations; // 15dc
        sstd::string _region_name; // 15ec
    };

    static_assert(sizeof(CCountry) == 0x1608);

}