#pragma once

#include <cstdint>
#include "eu3date.hpp"
#include "../clausewitz/persistent.hpp"

namespace smedley::v2
{

    /**
     * CCountryTag stores the identifier of a CCountry object, as
     * well as its position within the CCountryDataBase instance.
     */
    class CCountryTag
    {
    protected:
        union {
            char str[4];
            uint32_t n;
        } _key;
        int _ordinal;
    public:
        CCountryTag(const char *str, int ordinal) : _ordinal(ordinal)
        {
            _key.str[0] = str[0];
            _key.str[1] = str[1];
            _key.str[2] = str[2];
            _key.str[3] = '\0';
        }

        CCountryTag() : CCountryTag("---", 0) {}

        uint32_t key() const { return _key.n; }
        int ordinal() const { return _ordinal; }
        const char *str() const { return _key.str; }
    };

    static_assert(sizeof(CCountryTag) == 0x8);

    class CCountryDate : public clausewitz::CPersistent
    {
    protected:
        CCountryTag _tag; // 8
        CEU3Date _date; // 10
    };

    static_assert(sizeof(CCountryDate) == 0x14);

}