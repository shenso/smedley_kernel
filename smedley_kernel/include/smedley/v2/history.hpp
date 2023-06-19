#pragma once

#include "../clausewitz/persistent.hpp"
#include "eu3date.hpp"

namespace smedley::v2
{

    class CProvince;

    class CHistoryContainer : public clausewitz::CPersistent
    {
    protected:
        CEU3Date _date;
        uint8_t _uk[0x14];
    };

    static_assert(sizeof(CHistoryContainer) == 0x20);

    class CDiplomaticHistory : public CHistoryContainer
    {
    };

    static_assert(sizeof(CDiplomaticHistory) == 0x20);

    class CProvinceHistory : public CHistoryContainer
    {
    protected:
        CProvince *_province; // 20
    };

    static_assert(sizeof(CProvinceHistory) == 0x24);

}