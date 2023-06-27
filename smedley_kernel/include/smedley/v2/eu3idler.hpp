#pragma once

#include "../clausewitz/idler.hpp"

namespace smedley::v2
{

    class CEU3Idler : public clausewitz::CIdler
    {
    };

    /// @brief main in game ui handler
    class CInGameIdler : public CEU3Idler
    {
    };

    class CNudgeIdler : public CEU3Idler
    {
    };

}