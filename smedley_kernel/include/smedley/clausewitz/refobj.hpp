#pragma once

#include "persistent.hpp"
#include "../std/string.hpp"

namespace smedley::clausewitz
{

    class CID
    {
    protected:
        unsigned int _type;
        unsigned int _id;
    };

    static_assert(sizeof(CID) == 0x8);

    class CReferenceObject : public CPersistent
    {
    protected:
        CID _id;
        bool _is_created;
        sstd::string _session_name;
    public:
        virtual Create(CID &, bool);
        virtual Create();
    };

    static_assert(sizeof(CReferenceObject) == 0x30);

}