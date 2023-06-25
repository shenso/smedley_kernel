#pragma once

#include "../../std/string.hpp"
#include "../../std/vector.hpp"
#include "../country.hpp"
#include <cstring>
#include <string>

namespace smedley::v2
{

    class CCountryDataBase
    {
        size_t _size; // 0
        sstd::vector<CCountry *> _countries; // 4
        sstd::vector<CCountryTag> _buckets[64]; // 14
        sstd::vector<CCountryTag> _dynamic_tags; // 414
    public:
        DEFINE_STATIC_GETTER(instance, CCountryDataBase *, 0x00e587e4);

        /// @returns the tag matching str if found. the NULL tag (---) otherwise
        CCountryTag FindTag(const char *str) const
        {
            unsigned int hash = str[2] + str[1] + str[0] & 0x3f;
            auto bucket = _buckets[hash];
            for (int i = 0; i < bucket.size(); i++) {
                if (std::strncmp(str, bucket[i].str(), 3) == 0) {
                    return bucket[i];
                }
            }

            return CCountryTag();
        }

        /// @returns the tag matching str if found. the NULL tag (---) otherwise
        inline CCountryTag FindTag(const std::string &str) const { return FindTag(str.c_str()); }
        /// @returns the tag matching str if found. the NULL tag (---) otherwise
        inline CCountryTag FindTag(const sstd::string &str) const { return FindTag(str.c_str()); }

        /// @returns the country with a tag matching str if found. the NULL country otherwise
        inline CCountry *Find(const std::string &str) const { return Get(FindTag(str)); }
        /// @returns the country with a tag matching str if found. the NULL country otherwise
        inline CCountry *Find(const sstd::string &str) const { return Get(FindTag(str)); }

        inline CCountry *Get(int ordinal) const { return _countries[ordinal]; }
        inline CCountry *Get(const CCountryTag &tag) const { return _countries[tag.ordinal()]; }
        inline CCountry *operator[](int ordinal) const { return _countries[ordinal]; }
        inline CCountry *operator[](const CCountryTag &tag) const { return _countries[tag.ordinal()]; }

        inline size_t size() const noexcept { return _size; }
        inline sstd::vector<CCountry *> countries() noexcept { return _countries; }
        inline const sstd::vector<CCountry *> countries() const noexcept { return _countries; }
        inline sstd::vector<CCountryTag> dynamic_tags() noexcept { return _dynamic_tags; }
        inline const sstd::vector<CCountryTag> dynamic_tags() const noexcept { return _dynamic_tags; }
    };

    static_assert(sizeof(CCountryDataBase) == 0x424);

}