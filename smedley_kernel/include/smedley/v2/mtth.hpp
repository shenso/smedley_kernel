#pragma once

#include "trigger.hpp"
#include "../clausewitz/persistent.hpp"
#include "../clausewitz/types.hpp"
#include "../std/vector.hpp"

namespace smedley::v2
{

    class CMTTHModifier : public CAndTrigger
    {
    protected:
        uint32_t _unk_0x1c;
        clausewitz::CFixedPoint _factor; // 20
    };

    static_assert(sizeof(CMTTHModifier) == 0x24);

    class CMeanTimeToHappen : public clausewitz::CPersistent
    {
    protected:
        clausewitz::CFixedPoint _base_days; // 8
        sstd::vector<CMTTHModifier *> _modifiers; // c
    };

    static_assert(sizeof(CMeanTimeToHappen) == 0x1c);

    class CAdditiveMTTH : public clausewitz::CPersistent
    {
    protected:
        sstd::vector<sstd::vector<CMTTHModifier *>> _group; // 8
        clausewitz::CFixedPoint _factor; // 18
        clausewitz::CFixedPoint _base; // 1c
        sstd::vector<CMTTHModifier *> _modifiers; // 20
    };

    static_assert(sizeof(CAdditiveMTTH) == 0x30);

}