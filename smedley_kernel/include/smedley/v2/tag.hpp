#pragma once

namespace smedley::v2
{

    class CCountryTag
    {
    protected:
        char _str[4];
        int _ordinal;
    };

    static_assert(sizeof(CCountryTag) == 0x8);

}