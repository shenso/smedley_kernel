#pragma once

#include "../clausewitz/types.hpp"

namespace smedley::v2
{

    class CEU3Date : public clausewitz::CGregorianDate
    {
    };

    static_assert(sizeof(CEU3Date) == 0x4);

}