#pragma once

#include "trigger.hpp"
#include "../clausewitz/persistent.hpp"
#include "../clausewitz/types.hpp"
#include "../std/string.hpp"
#include "../std/vector.hpp"

namespace smedley::v2
{

    enum class ModifierType : uint32_t
    {
        NONE = 0,
        SUPPLY_LIMIT = 1,
        ATTRITION = 2,
        MAX_ATTRITION = 3,
        WAR_EXHAUSTION = 4,
        MAX_WAR_EXHAUSTION = 5,
        FORT_LEVEL = 6,
        LEADERSHIP = 7,
        GLOBAL_LEADERSHIP_MODIFIER = 8,
        SUPPLY_CONSUMPTION = 9,
        UNIT_RECRUITMENT_TIME = 10,
        ORG_REGAIN = 11,
        REINFORCE_SPEED = 12,
        LAND_ORGANISATION = 13,
        NAVAL_ORGANISATION = 14,
        RESEARCH_POINTS = 15,
        RESEARCH_POINTS_MODIFIER = 16,
        RESEARCH_POINTS_ON_CONQUER = 17,
        DEBT_DEFAULT_TO = 18,
        IMPORT_COST = 19,
        LOAN_INTEREST = 20,
        TAX_EFFICIENCY = 21,
        MIN_TAX = 22,
        MAX_TAX = 23,
        MIN_MILITARY_SPENDING = 24,
        MAX_MILITARY_SPENDING = 25,
        MIN_SOCIAL_SPENDING = 26,
        MAX_SOCIAL_SPENDING = 27,
        FACTORY_OWNER_COST = 28,
        MIN_TARIFF = 29,
        MAX_TARIFF = 30,
        RULING_PARTY_SUPPORT = 31,
        LOCAL_RULING_PARTY_SUPPORT = 32,
        RICH_VOTE = 33,
        MIDDLE_VOTE = 34,
        POOR_VOTE = 35,
        MINIMUM_WAGE = 36,
        FACTORY_MAINTENANCE = 37,
        POOR_LIFE_NEEDS = 38,
        RICH_LIFE_NEEDS = 39,
        MIDDLE_LIFE_NEEDS = 40,
        POOR_EVERYDAY_NEEDS = 41,
        RICH_EVERYDAY_NEEDS = 42,
        MIDDLE_EVERYDAY_NEEDS = 43,
        POOR_LUXURY_NEEDS = 44,
        MIDDLE_LUXURY_NEEDS = 45,
        RICH_LUXURY_NEEDS = 46,
        UNEMPLOYMENT_BENEFIT = 47,
        PENSION_LEVEL = 48,
        POPULATION_GROWTH = 49,
        GLOBAL_POPULATION_GROWTH = 50,
        FACTORY_INPUT = 51,
        FACTORY_OUTPUT = 52,
        FACTORY_THROUGHPUT = 53,
        RGO_INPUT = 54,
        RGO_OUTPUT = 55,
        RGO_THROUGHPUT = 56,
        ARTISAN_INPUT = 57,
        ARTISAN_OUTPUT = 58,
        ARTISAN_THROUGHPUT = 59,
        LOCAL_FACTORY_INPUT = 60,
        LOCAL_FACTORY_OUTPUT = 61,
        LOCAL_FACTORY_THROUGHPUT = 62,
        LOCAL_RGO_INPUT = 63,
        LOCAL_RGO_OUTPUT = 64,
        LOCAL_RGO_THROUGHPUT = 65,
        LOCAL_ARTISAN_INPUT = 66,
        LOCAL_ARTISAN_OUTPUT = 67,
        LOCAL_ARTISAN_THROUGHPUT = 68,
        NUMBER_OF_VOTERS = 69,
        GOODS_DEMAND = 70,
        BADBOY = 71,
        ASSIMILATION_RATE = 72,
        GLOBAL_ASSIMILATION_RATE = 73,
        PRESTIGE = 74,
        FACTORY_COST = 75,
        LIFE_RATING = 76,
        FARM_EFFICIENCY = 77,
        MINE_EFFICIENCY = 78,
        FARM_SIZE = 79,
        MINE_SIZE = 80,
        ISSUE_CHANGE_SPEED = 81,
        SOCIAL_REFORM_DESIRE = 82,
        POLITICAL_REFORM_DESIRE = 83,
        LITERACY_CON_IMPACT = 84,
        POP_MILITANCY = 85,
        POP_CONSCIOUSNESS = 86,
        RICH_INCOME = 87,
        MIDDLE_INCOME = 88,
        POOR_INCOME = 89,
        BOOST_STRONGEST_PARTY = 90,
        GLOBAL_IMMIGRANT_ATTRACT = 91,
        IMMIGRANT_ATTRACT = 92,
        IMMIGRANT_PUSH = 93,
        LOCAL_REPAIR = 94,
        LOCAL_SHIP_BUILD = 95,
        POOR_SAVINGS_MODIFIER = 96,
        GREATPOWER_INFLUENCE_GAIN = 97,
        DIPLOPOINTS_GAIN = 98,
        MOBILISATION_SIZE = 99,
        MOBILISATION_ECONOMY_IMPACT = 100,
        GLOBAL_POP_MILITANCY_MODIFIER = 101,
        GLOBAL_POP_CONSCIOUSNESS_MODIFIER = 102,
        CORE_POP_MILITANCY_MODIFIER = 103,
        CORE_POP_CONSCIOUSNESS_MODIFIER = 104,
        NON_ACCEPTED_POP_MILITANCY_MODIFIER = 105,
        NON_ACCEPTED_POP_CONSCIOUSNESS_MODIFIER = 106,
        CB_GENERATION_SPEED_MODIFIER = 107,
        MOBILIZATION_IMPACT = 108,
        SUPPRESSION_POINT_GAIN = 109,
        EDUCATION_EFFICIENCY = 110,
        CIVILIZATION_PROGRESS = 111,
        ADMINISTRATIVE_EFFICIENCY = 112,
        LAND_UNIT_START_EXPERIENCE = 113,
        NAVAL_UNIT_START_EXPERIENCE = 114,
        NAVAL_ATTACK = 115,
        NAVAL_DEFENSE = 116,
        LAND_ATTACK = 117,
        LAND_DEFENSE = 118,
        TARIFF_EFFICIENCY = 119,
        MAX_LOAN_AMOUNT = 120,
        MOVEMENT_COST = 121,
        UNCIV_ECONOMIC = 122,
        UNCIV_MILITARY = 123,
        SELF_UNCIV_ECONOMIC = 124,
        SELF_UNCIV_MILITARY = 125,
    };

    class CModifierDefinition
    {
        sstd::string _name; // 4
        int _tok_type; // 20
        int _ordinal; // 24
        bool _show_as_percent; // 28
        bool _is_good; // 29
    public:
        virtual bool IsValid();
    };

    static_assert(sizeof(CModifierDefinition) == 0x2c);

    class CModifierEntry
    {
        clausewitz::CFixedPoint _value; // 0
        CModifierDefinition *_def; // 4
    };

    static_assert(sizeof(CModifierEntry) == 0x8);

    class CModifier : public clausewitz::CPersistent
    {
        clausewitz::CList<void *> _uk_0x8;
        sstd::vector<CModifierEntry> _entries; // 18
        int _icon; // 28
        uint32_t _uk_0x2c;
    public:
        virtual ~CModifier(); // 0
        virtual sstd::string GetName(); // 18
        virtual sstd::string GetFullDescription(); // 1c
        virtual sstd::string GetActualDescription(int type, clausewitz::CFixedPoint scalar); // 20
        virtual sstd::string Unk24(); // 24
        virtual bool IsProvinceModifier(); // 28
    };

    static_assert(sizeof(CModifier) == 0x30);

    class CStaticModifier : public CModifier
    {
        sstd::string _tag; // 30
    };

    static_assert(sizeof(CStaticModifier) == 0x4c);

    class CProvince;

    class CProvinceModifier : public CModifier
    {
        CProvince *_province; // 30
    };

    static_assert(sizeof(CProvinceModifier) == 0x34);

    class CCrime : public CModifier
    {
        sstd::string _tag; // 30
        int _ordinal; // 4c
        CAndTrigger _trigger; // 50
        bool _is_active; // 6c
    };

    static_assert(sizeof(CCrime) == 0x70);

}