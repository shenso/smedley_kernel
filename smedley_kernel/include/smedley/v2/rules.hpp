#pragma once

#include "../clausewitz/persistent.hpp"
#include "../clausewitz/types.hpp"
#include "../std/string.hpp"
#include "../std/vector.hpp"

namespace smedley::v2
{

    class CRuleDefinition
    {
    protected:
        sstd::string _tag;
        int _token;
        int _ordinal;
        bool _allowed;
    public:
        virtual bool Unk0(); // always returns true. IsValid?
    };

    static_assert(sizeof(CRuleDefinition) == 0x2c);

    class CRule : public clausewitz::CPersistent
    {
    protected:
        clausewitz::CList<void *> _unk_0x8;
        sstd::vector<int> _rule_set;
        uint8_t _unk_0x28[0xf8];
        int _icon;
    public:
        virtual sstd::string GetRuleLabel(int ordinal);
        virtual sstd::string GetFullDescription();
        virtual sstd::string GetRuleDescription(int ordinal);
        virtual sstd::string Unk9(int ordinal);
    };

    static_assert(sizeof(CRule) == 0x124);

}