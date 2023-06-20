#pragma once

namespace smedley::sstd
{

    template <typename Left, typename Right>
    class pair
    {
    protected:
        Left _left;
        Right _right;
    };

}