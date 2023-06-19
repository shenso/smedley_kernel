#pragma once

#include "../clausewitz/persistent.hpp"

namespace smedley::v2
{

    class CGamePlaySettings : public clausewitz::CPersistent
    {
        int _uk_0x8;
    };

    static_assert(sizeof(CGamePlaySettings) == 0xc);

}