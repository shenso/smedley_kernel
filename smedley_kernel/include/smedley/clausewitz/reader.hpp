#pragma once

#include "token.hpp"
#include "../std/string.hpp"
#include <cstdint>

namespace smedley::clausewitz
{

    /**
     * The base lexer class. Responsible for turning some input stream into
     * a stream of tokens. Also manages dynamic tokens.
     */
    class CLexer
    {
    };

    /**
     * The reader provides facilities for parsing data from a stream of
     * tokens provided by its lexer.
     */
    class CReader
    {
    protected:
        uint32_t _unk_0x4;
        uint32_t _unk_0x8;
        uint32_t _unk_0xc;
        uint32_t _unk_0x10;
        uint32_t _unk_0x14;
        uint32_t _unk_0x18;

        CLexer *_lexer;
        CToken _lhs;
        CToken _op;
        CToken _rhs;

        sstd::string _session_name;

        uint32_t _unk_0x348;
        uint32_t _unk_0x34c;
        uint32_t _unk_0x350;
        uint32_t _unk_0x354;
        uint32_t _unk_0x358;
        uint32_t _unk_0x35c;
    public:
        virtual ~CReader();
    };

    static_assert(sizeof(CReader) == 0x360);

}