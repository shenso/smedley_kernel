#pragma once

#include "persistent.hpp"
#include "../std/string.hpp"

namespace smedley::clausewitz
{

    /**
     * The ID of a CReferenceObject object.
     */
    class CID
    {
    protected:
        unsigned int _type; 
        unsigned int _id;
    public:
        /// @return the type id of the CReferenceObject subclass
        int type() const { return _type; }
        /// @return the id of the instance
        int id() const { return _id; }
    };

    static_assert(sizeof(CID) == 0x8);

    /**
     * The base class for all game objects indexable by a
     * CID.
     */
    class CReferenceObject : public CPersistent
    {
    protected:
        CID _id;
        bool _is_created;
        sstd::string _session_name;
    public:
        virtual void Create(CID &, bool);
        virtual void Create();
    };

    static_assert(sizeof(CReferenceObject) == 0x30);

}