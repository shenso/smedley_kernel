#pragma once

#include "../clausewitz/idler.hpp"

namespace smedley::v2
{

    class CEU3Idler : public clausewitz::CIdler
    {
    };

    class CInGameIdler : public CEU3Idler
    {
    };

}