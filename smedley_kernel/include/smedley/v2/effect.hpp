#pragma once

#include "eventscope.hpp"
#include "../clausewitz/persistent.hpp"
#include "../clausewitz/token.hpp"
#include "../clausewitz/types.hpp"
#include "../std/string.hpp"

namespace smedley::v2
{

    class CEffect;

    class CEffect : public clausewitz::CPersistent, public clausewitz::CList<CEffect *>
    {
    protected:
        int _token;
    public:
        virtual int GetToken();
        virtual void Assign(clausewitz::CToken tok);
        virtual sstd::string GetCompleteDescription(CEventScope &scope, int indent_level, sstd::string unk = "");
        virtual sstd::string GetDescription();
        virtual sstd::string GetScopeLabel(CEventScope &scope);
    };

    static_assert(sizeof(clausewitz::CList<CEffect *>) == 0x10);
    static_assert(sizeof(CEffect) == 0x1c);

}