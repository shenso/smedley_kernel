#pragma once

namespace smedley::v2
{

    class CSelectable
    {
        bool _is_selected; // 4
    public:
        virtual ~CSelectable();
    };

    static_assert(sizeof(CSelectable) == 0x8);

}