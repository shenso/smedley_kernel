#pragma once

#include "effect.hpp"
#include "eu3date.hpp"
#include "modifier.hpp"
#include "rules.hpp"
#include "tag.hpp"
#include "../clausewitz/color.hpp"
#include "../clausewitz/refobj.hpp"
#include "../std/string.hpp"
#include "../std/vector.hpp"

namespace smedley::v2
{

    class CIdeology
    {
    };

    class CIssueGroup
    {
    };

    class CIssueOnExecute : public clausewitz::CPersistent
    {
    protected:
        CAndTrigger *_trigger;
        CEffect *_effect;
    };

    static_assert(sizeof(CIssueOnExecute) == 0x10);

    class CIssue : public CModifier
    {
    protected:
        sstd::string _tag; // 34
        int _id; // 50
        CIssueGroup *_group; // 54
        CAndTrigger _allow; // 58
        CRule _rules; // 74
        clausewitz::CColor _color; // 198
        int _administrative_multiplier; // 1b4
        clausewitz::fixed_point<int64_t,48,15> _tech_cost; // 1c0
        bool _is_jinoism; // 1c4
        CIssueOnExecute _on_execute; // 1c8
    public:
        virtual sstd::string GetLabel(); // 2c
        virtual sstd::string GetDescription(); // 30
        virtual bool Unk34();
    };

    static_assert(sizeof(CIssue) == 0x1d8);

    class CNullIssue : CIssue
    {
    };

    class CParty : public clausewitz::CReferenceObject
    {
    protected:
        sstd::string _name; // 30
        CCountryTag _country_tag; // 4c
        CIdeology *_ideology; // 54
        sstd::vector<CIssue *> _issues; // 58
        CEU3Date _start_date; // 68
        CEU3Date _end_date; // 6c
    };

    static_assert(sizeof(CParty) == 0x70);

    class CUpperHouse : public clausewitz::CPersistent
    {
    protected:
        CCountryTag _country_tag; // 8
        sstd::vector<clausewitz::fixed_point<int64_t,48,15>> _seats; // 10 indexed by ideology
    };

    static_assert(sizeof(CUpperHouse) == 0x20);

    class CGovernment
    {
    };

}