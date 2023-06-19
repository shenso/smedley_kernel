#pragma once

#include "eu3date.hpp"
#include "goods.hpp"
#include "selectable.hpp"
#include "tag.hpp"
#include "../clausewitz/refobj.hpp"
#include "../clausewitz/types.hpp"

namespace smedley::v2
{

    class CProvince;

    class CConstruction : public clausewitz::CReferenceObject, CSelectable
    {
        CEU3Date _start_date; // 38
        CEU3Date _end_date; // 3c
        int _total_days; // 40
        clausewitz::CFixedPoint _progress; // 44
        CProvince *_location; // 48
        CCountryTag _tag; // 4c
        CGoodsProject *_input_goods; // 54
        uint32_t _uk_0x58;
        uint32_t _uk_0x5c;
    };

    static_assert(sizeof(CConstruction) == 0x60);

}