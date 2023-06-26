#pragma once

#include <istream>
#include <memory>
#include <string>
#include <stdexcept>
#include <vector>
#include <gtest/gtest_prod.h>

enum class Token
{
    L_PAREN,
    R_PAREN,
    NS_DELIM,
    ASTERISK,
    AMBERSAND,
    L_ANGLE_BRACKET,
    R_ANGLE_BRACKET,
    EQ_SIGN,
    SEMICOLON,
    COMMA,
    STRING_LITERAL,
    INTEGER,
    FLOAT,
    IDENTIFIER,
};

struct Location
{
    int pos;
    int lineno, col;

    Location() : Location(-1, -1, -1) {}
    Location(int pos, int lineno, int col) : pos(pos), lineno(lineno), col(col) {}

    inline std::string coords() const
    {
        return std::to_string(lineno) + ":" + std::to_string(col);
    }
};

struct Lexeme
{
    Token tok;
    std::string str;

    Location loc;
    int block_id;

    Lexeme() {}
    Lexeme(Token tok, const std::string &str, const Location &loc, int block_id)
        : tok(tok), str(str), loc(loc), block_id(block_id) {}
};

/// represents the text enclosure opened by {% and
/// closed by %}
struct Block
{
    int id;
    Location open_loc, close_loc;
};

class ScannerException : public std::runtime_error
{
    Location _loc;
public:
    ScannerException(const std::string &msg, const Location &loc);

    const Location &loc() const noexcept { return _loc; }
};

class Scanner
{
    std::unique_ptr<std::istream> _stream;
    Location _loc;
    int _prev_col;

    Block _cur_block;
    std::vector<Block> _blocks;
    int _block_id_counter;
    bool _in_block;

    Scanner();
public:
    /// @param stream the stream the scanner will read from. the scanner takes ownership of this resource
    Scanner(std::istream *stream);
    Scanner(std::unique_ptr<std::istream> &&stream);

    bool Next(Lexeme &);

    inline bool eof() const { return _stream->eof(); }
    const Location &loc() const noexcept { return _loc; }
private:
    bool Get();
    bool Get(char &);
    /// should never be called more than once until calling Get again (or you may
    /// mess up the location's column)
    void Unget();
    bool ScanTokenAtPos(Lexeme &);

    FRIEND_TEST(ScannerTests, ScanTokenAtPosTest);
};
