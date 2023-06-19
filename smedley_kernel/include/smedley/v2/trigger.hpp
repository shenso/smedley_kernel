#pragma once

#include "eventscope.hpp"
#include "../clausewitz/persistent.hpp"
#include "../clausewitz/token.hpp"
#include "../std/string.hpp"
#include "../std/vector.hpp"

namespace smedley::v2
{

    class CTrigger : public clausewitz::CPersistent
    {
    protected:
        sstd::vector<CTrigger *> _children;
    public:
        virtual ~CTrigger(); // 0
        virtual bool Evaluate(CEventScope &scope); // 18
        virtual void Unk7(); // 1c
        virtual void Unk8(); // 1c
        virtual void Assign(clausewitz::CToken tok); // 1c
        virtual sstd::string GetDescription(CEventScope &, bool); // 20
        virtual sstd::string GetTooltip(CEventScope &scope, bool invert, int level, bool checkbox); // 24
        virtual void Unk12(); // 28
    };

    static_assert(sizeof(CTrigger) == 0x18);

    class CAndTrigger : public CTrigger
    {
        uint32_t _unk_0x18;
    };

    static_assert(sizeof(CAndTrigger) == 0x1c);

}