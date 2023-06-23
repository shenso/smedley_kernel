#pragma once

#include "../clausewitz/persistent.hpp"
#include "../clausewitz/types.hpp"
#include "eu3date.hpp"

namespace smedley::v2
{

    class CCountry;
    class CProvince;

    class CHistoryEntry : public clausewitz::CPersistent
    {
        CEU3Date _date;
    public:
        virtual int GetToken();
        virtual void Unk1C();
    };

    class CHistoryContainer : public clausewitz::CPersistent
    {
    protected:
        CEU3Date _date; // 8
        clausewitz::CList<CHistoryEntry *> _entries; /// sorted by date 
        uint32_t _unk_0x1c;
    };

    static_assert(sizeof(CHistoryContainer) == 0x20);

    class CCountryHistory : public CHistoryContainer
    {
    protected:
        CCountry *_country;
    };

    static_assert(sizeof(CCountryHistory) == 0x24);

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