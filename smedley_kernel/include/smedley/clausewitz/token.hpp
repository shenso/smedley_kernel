#pragma once

namespace smedley::clausewitz
{

    /**
     * Represents lexemes read by the Lexer.
     */
    class CToken
    {
    protected:
        int _type;
        char _str[256];
    };

    static_assert(sizeof(CToken) == 0x104);

}