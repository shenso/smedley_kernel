#pragma once

#include "../clausewitz/persistent.hpp"
#include "../clausewitz/refobj.hpp"
#include "../clausewitz/types.hpp"

namespace smedley::v2
{

    class CCountry;
    class CPop;

    class CMobilizationSchedule : public clausewitz::CPersistent
    {
    protected:
        int _location; // 8
        int _from_province; // c
        int _subunit; // 10
        CPop *_pop; // 14
        clausewitz::CID _pop_id; // 18
        uint8_t _unk_0x20[0x1c];
        clausewitz::CFixedPoint _progress; // 3c
        CCountry *_country; // 40
        bool _unk_0x44;
        bool _is_active; // 45
        clausewitz::CList<int> _path; // 48
        uint32_t _unk_0x58;
        int _rally_point; // 5c
    };

    static_assert(sizeof(CMobilizationSchedule) == 0x60);

}