#pragma once

#include "../../macros.hpp"
#include "../../clausewitz/types.hpp"
#include "../../std/vector.hpp"
#include "../culture.hpp"

namespace smedley::v2
{

    class CCultureDataBase
    {
        clausewitz::CHashTable<sstd::string, CCulture> _table; // 0
        sstd::vector<CCulture *> _cultures; // c
        sstd::vector<CCultureGroup *> _groups; // 1c
    public:
        clausewitz::CHashTable<sstd::string, CCulture> table() { return _table; }
        const clausewitz::CHashTable<sstd::string, CCulture> table() const { return _table; }
        sstd::vector<CCulture *> cultures() { return _cultures; }
        const sstd::vector<CCulture *> cultures() const { return _cultures; }
        sstd::vector<CCultureGroup *> groups() { return _groups; }
        const sstd::vector<CCultureGroup *> groups() const { return _groups; }

        DEFINE_STATIC_GETTER(instance, CCultureDataBase *, 0x00e587e8);
    };

    static_assert(sizeof(CCultureDataBase) == 0x2c);

}