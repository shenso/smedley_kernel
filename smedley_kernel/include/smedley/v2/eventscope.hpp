#pragma once

#include "pop.hpp"
#include "tag.hpp"
#include "../clausewitz/persistent.hpp"
#include "../clausewitz/refobj.hpp"

namespace smedley::v2
{

    class CEventScope : public clausewitz::CPersistent
    {
        CCountryTag _this_tag; // 8
        int _province_id; // 10
        CPop *_pop; // 14
        int _state_province_id; // 18
        int _unk_0x1c;
        int _seed; // 20
        CEventScope *_parent; // 24
        int _unk_0x28;
        CCountryTag _from_tag; // 2c
        int _from_province_id; // 34
        clausewitz::CID _rebel_faction; // 38
        int _unk_0x40;
        int _unk_0x44;
    };

    static_assert(sizeof(CEventScope) == 0x48);

}