#pragma once

namespace smedley::v2
{

    class CSelectable
    {
    protected:
        bool _is_selected; // 4
    public:
        virtual ~CSelectable();
    };

    static_assert(sizeof(CSelectable) == 0x8);

}