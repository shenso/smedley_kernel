#pragma once

#include "tag.hpp"
#include "../clausewitz/persistent.hpp"
#include "../clausewitz/types.hpp"

namespace smedley
{

    namespace v2
    {

        class CCountryValue : public clausewitz::CPersistent
        {
        public:
            CCountryTag tag; // 8
            int value;       // 10
        };

        static_assert(sizeof(CCountryValue) == 0x14);
    }

    namespace clausewitz
    {
        template <>
        unsigned int ClassicHashKeyTraits<v2::CCountryTag, v2::CCountryValue>::GetHashValue(const v2::CCountryTag &key)
        {
            return static_cast<unsigned int>(key.ordinal());
        }

        template<>
        const v2::CCountryTag &ClassicHashKeyTraits<v2::CCountryTag, v2::CCountryValue>::GetKey(const v2::CCountryValue &val)
        {
            return val.tag;
        }
    }
}
