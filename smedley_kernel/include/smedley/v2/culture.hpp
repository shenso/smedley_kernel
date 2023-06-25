#pragma once

#include "../clausewitz/color.hpp"
#include "../clausewitz/persistent.hpp"
#include "../std/string.hpp"
#include "../std/vector.hpp"
#include "tag.hpp"
#include <cstdint>

namespace smedley::v2
{

    class CCultureGroup;

    class CCulture : public clausewitz::CPersistent
    {
    protected:
        uint32_t _unk_0x8;
        uint32_t _unk_0xc;
        CCountryTag _primary_country_tag;
        sstd::string _tag;
        sstd::string _name;
        CCultureGroup *_group;
        clausewitz::CColor _color;
        sstd::vector<sstd::string> _first_names;
        sstd::vector<sstd::string> _last_names;
        clausewitz::fixed_point<int64_t,48,15> _radicalism;

        friend class clausewitz::ClassicHashKeyTraits<sstd::string, CCulture>;
    public:
        inline sstd::string tag() const noexcept { return _tag; }
    };

    static_assert(sizeof(CCulture) == 0x98);

    class CCultureGroup : public clausewitz::CList<CCulture *>, public clausewitz::CPersistent
    {
    protected:
        bool _is_overseas; // 18
        CCountryTag _union_leader_tag; // 1c
        sstd::string _tag; // 24
        sstd::string _name; // 40
        uint8_t _unk_0x5c[0x20];
        sstd::string _unit; // 7c
        sstd::string _unit_tag; // 98
        sstd::vector<sstd::string> _first_names; // b4
        sstd::vector<sstd::string> _last_names; // c4
        sstd::string _leader; // d4
        uint32_t _unk_0xf0;
        uint32_t _unk_0xf4;
    };

    static_assert(sizeof(CCultureGroup) == 0xf8);

}

namespace smedley::clausewitz
{
    template<>
    const sstd::string &ClassicHashKeyTraits<sstd::string, v2::CCulture>::GetKey(const v2::CCulture &culture)
    {
        return culture._tag;
    }

    template<>
    unsigned int ClassicHashKeyTraits<sstd::string, v2::CCulture>::GetHashValue(const sstd::string &key)
    {
        unsigned int hash = 0;
        size_t n = key.size();

        for (size_t i = 0; i < n; i++) {
            hash = (hash + static_cast<unsigned int>(key[i])) * 0x3d;
        }

        return hash;
    }
}