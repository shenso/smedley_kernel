#pragma once

#include "ai.hpp"
#include "culture.hpp"
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
#include "../macros.hpp"
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
    class CDiplomaticAction;
    class CDiplomacyStatus;
    class CEvent;
    class CEventScope;
    class CGameState;
    class CGraphicalCultureType;
    class CLeader;
    class CNationalValue;
    class CNudgeIdler;
    class CPopDataBase;
    class CPopMovement;
    class CRailroadChunk;
    class CRallyPoint;
    class CRebelFaction;
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
        uint32_t _unk_0x24[3];
        bool _unk_0x30;
        bool _is_great_power; // 31
        sstd::vector<void *> _unk_0x34;
        uint32_t _unk_0x44[4];
        clausewitz::CList<sstd::pair<sstd::string, sstd::string>> _unk_0x54; // type may be incorrect. localisation keys?
        uint32_t _unk_0x64;
        sstd::vector<CEvent *> _event_queue; // 68
        CEU3Date _next_quarterly_pulse; // 78
        CEU3Date _next_yearly_pulse; // 7c
        uint32_t _unk_0x80[6];
        int _campaign_counter; // 98
        CEU3Date _last_reform_date; // 9c
        sstd::vector<CTaxSetting *> _tax_settings; // a0
        clausewitz::CVector2<sstd::vector<clausewitz::fixed_point<int64_t,48,15>>> _expenses; // b0
        clausewitz::CVector2<sstd::vector<clausewitz::fixed_point<int64_t,48,15>>> _incomes; // d0
        sstd::string _unk_0xf0;
        CColonialDistanceTracker *_colonial_distance_tracker; // 10c
        //clausewitz::CHashTable<sstd::string, void *> _unk_0x110;
        uint32_t _unk_0x110[4];
        bool _mobilize; // 120
        uint32_t _unk_0x124[5];
        clausewitz::fixed_point<int64_t,48,15> _share_factor; // 138
        uint8_t _unk_0x140[0x44];
        sstd::vector<sstd::string> _ignored_decisions; // 184
        uint32_t _unk_0x194[5];
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
        uint32_t _unk_0x700[7];
        CModifier _unk_0x71c;
        uint32_t _unk_0x74c[7];
        CModifier _unk_0x768;
        uint32_t _unk_0x798[7];
        clausewitz::CList<CUnit *> _units; // 7b4
        uint32_t _unk_0x7c4[3];
        clausewitz::fixed_point<int64_t,48,15> _leadership; // 7d0
        int _num_colonial_provinces; // 7d8
        uint32_t _unk_0x7dc;
        CModifier _unk_0x7e0;
        uint32_t _unk_0x810[7];
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
        CCountryHistory _history;           // 9b4
        sstd::vector<int> _owned_provinces; // 9d8
        clausewitz::CList<int> _controlled_provinces; // 9e8
        clausewitz::CList<int> _core_provinces; // 9f8
        clausewitz::CList<int> _unk_0xa08;
        uint32_t _unk_0xa18[12];
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
        uint32_t _unk_0xda8[4];
        sstd::vector<int> _unk_0xdb8;
        uint8_t _unk_0xdc8[0x38];
        sstd::vector<int> _slider_locks;
        uint32_t _unk_0xe10;
        sstd::vector<CCountryTag> _historical_friends; // e14
        uint32_t _unk_0xe24[6];
        clausewitz::CFixedPoint _research_points; // e3c
        int _tech_school_id; // e40
        clausewitz::CList<CState *> _states; // e44
        clausewitz::CList<CCulture *> _accepted_cultures; // e54
        CCulture *_primary_culture; // e64
        uint32_t _unk_0xe68[4];
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
        uint32_t _unk_0x1434[3];
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
    private:
        DECLARE_MEMBER_FN_CLASS(CCountry);
    protected:
        /// @brief called once each day
        inline DEFINE_MEMBER_FN_0(DailyUpdate, void, 0x00108590);
        /// @brief called once each month
        inline DEFINE_MEMBER_FN_0(MonthlyUpdate, void, 0x0010c2a0);
        inline DEFINE_MEMBER_FN_0(PayDailyInterest, void, 0x00123c30);
        inline DEFINE_MEMBER_FN_3(SubsidizePops, void, 0x0010b9b0, int, num_pop_types, CPopDataBase *, pop_db, CGameState *, game_state);
    public:
        DEFINE_MEMBER_FN_ESI_1(AddAcceptedCulture, void, 0x00122310, CCulture *, culture);
        // TODO: test below:
        inline DEFINE_MEMBER_FN_EDI_4(AddCasusBelli, void, 0x00135fc0, const CCountryTag &, target, const sstd::string &, cb_tag, int, months, bool, send_message);
        inline DEFINE_MEMBER_FN_ESI_2(AddLeader, void, 0x0010e760, CLeader *, leader, bool, add_to_history);
        inline DEFINE_MEMBER_FN_ESI_1(AddPrestige, void, 0x001341a0, clausewitz::CFixedPoint, delta);
        inline DEFINE_MEMBER_FN_2(AddTimedModifier, void, 0x001114d0, sstd::string, modifier_tag, int, days);
        inline DEFINE_MEMBER_FN_1_ESI(AddToSphere, void, 0x00133e50, const CCountryTag &, target);
        inline DEFINE_MEMBER_FN_EDI_EAX_0(AddUnit, void, 0x00113c80, CUnit *, unit);
        inline DEFINE_MEMBER_FN_2(Annex, void, 0x00118620, const CCountryTag *, remove_core_from, CCountryTag, target);
        inline DEFINE_MEMBER_FN_1(Break, void, 0x00116630, CRebelFaction *, faction);
        DEFINE_MEMBER_FN_EDI_0_RET_EAX(CalcDebt, TYPE_IDENTITY((clausewitz::fixed_point<int64_t,48,15>)), 0x00123880);
        inline DEFINE_MEMBER_FN_EDI_ECX_1_RET_ESI(CalcFactoryCost, TYPE_IDENTITY((clausewitz::fixed_point<int64_t,48,15>)), 0x000daa10, const CBuilding &, building, bool, add_owner_cost);
        inline DEFINE_MEMBER_FN_EAX_ESI_1_RET_ESI(CalcGovernmentNeedForGood, TYPE_IDENTITY((clausewitz::fixed_point<int64_t,48,15>)), 0x00139760, int, goods_type);
        inline DEFINE_MEMBER_FN_1(CalcLoanLimitFrom, TYPE_IDENTITY((clausewitz::fixed_point<int64_t,48,15>)), 0x001225a0, CCountryTag, creditor);
        inline DEFINE_MEMBER_FN_EDI_0_RET_1(CalcTariffEfficiency, TYPE_IDENTITY((clausewitz::fixed_point<int64_t,48,15>)), 0x001339d0);
        inline DEFINE_MEMBER_FN_1_RET_ESI(CalcPercentageOfTaxableIncome, TYPE_IDENTITY((clausewitz::fixed_point<int64_t,48,15>)), 0x0012b610, TYPE_IDENTITY((const sstd::vector<clausewitz::fixed_point<int64_t,48,15>> &)), tax_settings);
        inline DEFINE_MEMBER_FN_1(CanTakeLoanFrom, bool, 0x00123130, CCountryTag, tag);
        inline DEFINE_MEMBER_FN_EDI_2(ChangeCapital, void, 0x00135fc0, int, province_id, bool, add_to_history);
        inline DEFINE_MEMBER_FN_3(DelayEvent, void, 0x00140a70, CEvent *, event, CEventScope *, scope, int, days);
        inline DEFINE_MEMBER_FN_2(DiscoverInvention, void, 0x00102090, CInvention *, invention, bool, add_to_news);
        inline DEFINE_MEMBER_FN_EDI_0(DismantleSphere, void, 0x001340a0);

        static constexpr uintptr_t GetMovement_address_0 = 0x00140e40;
        inline DEFINE_MEMBER_FN_EDX_EDI_0_BASE(GetMovement, CPopMovement *, GetMovement_address_0, CIssue *, issue);
        static constexpr uintptr_t GetMovement_address_1 = 0x00140e80;
        inline DEFINE_MEMBER_FN_EDX_1_BASE(GetMovement, CPopMovement *, GetMovement_address_1, const CCountryTag &, country_tag);

        inline DEFINE_MEMBER_FN_ESI_EDX_0(HasStaticModifier, bool, 0x001068b0, CStaticModifier *, modifier);
        inline DEFINE_MEMBER_FN_EDI_0(NationalizeFactories, void, 0x001441f0);
        inline DEFINE_MEMBER_FN_THISCALL_2(PayBackLoan, void, 0x001238d0, bool, param_1, TYPE_IDENTITY((clausewitz::fixed_point<int64_t,48,15>)), amount);
        inline DEFINE_MEMBER_FN_0(RearrangeUpperHouse, void, 0x00127d10);
        inline DEFINE_MEMBER_FN_0(RefreshSubUnits, void, 0x00127d10);
        /// RemoveDebts? 
        inline DEFINE_MEMBER_FN_0(Unk_00111340, void, 0x00111340);
        /// doesn't seem to work
        inline DEFINE_MEMBER_FN_EDI_2(RemoveFoW, void, 0x0011b350, int, months, CCountryTag, target);
        inline DEFINE_MEMBER_FN_1_EDI(RemoveFromSphere, void, 0x00133f20, const CCountryTag &, target);
        inline DEFINE_MEMBER_FN_THISCALL_0(SaveColor, void, 0x0011b870);
        inline DEFINE_MEMBER_FN_EAX_1(SetLeadership, void, 0x00139380, TYPE_IDENTITY((clausewitz::fixed_point<int64_t,48,15>)), val);
        inline DEFINE_MEMBER_FN_EDI_2(SetPrimaryCulture, void, 0x00122430, CCulture *, culture, bool, add_to_history);
        inline DEFINE_MEMBER_FN_EDI_EDX_1(SetRelations, void, 0x001179e0, const CCountryTag &, country_tag, clausewitz::CFixedPoint, n);
        inline DEFINE_MEMBER_FN_ESI_1(SetResearchPoints, void, 0x001366f0, clausewitz::CFixedPoint, n);
        /// @param param_1 show dialog?
        /// @returns if the loan was taken successfully?
        inline DEFINE_MEMBER_FN_2(TakeLoan, bool, 0x00122910, bool, param_1, TYPE_IDENTITY((clausewitz::fixed_point<int64_t,48,15>)), amount);
        inline DEFINE_MEMBER_FN_2_RET_ESI(TakeLoanFrom, TYPE_IDENTITY((clausewitz::fixed_point<int64_t,48,15>)), 0x00122820, const CCountryTag &, creditor_tag, TYPE_IDENTITY((clausewitz::fixed_point<int64_t,48,15>)), amount);
        inline DEFINE_MEMBER_FN_1(UpdateCapital, void, 0x0010e540);
        //inline DEFINE_MEMBER_FN_ESI_0(UpdateOverlord, void, 0x00119920);
        inline DEFINE_MEMBER_FN_0(Westernize, void, 0x00142370);

        DEFINE_MEMBER_FN_EAX_0_RET_ECX(name, sstd::string, 0x000f97a0);

        inline bool exists() const { return _owned_provinces.size() > 0; }
    };

    static_assert(sizeof(CCountry) == 0x1608);

}