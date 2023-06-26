#include "scanner.hpp"
#include <sstream>

Scanner::Scanner()
    : _loc(1, 1, 0), _in_block(false), _block_id_counter(0)
{
}

Scanner::Scanner(std::istream *stream) : Scanner()
{
    _stream = std::unique_ptr<std::istream>(stream);
}

Scanner::Scanner(std::unique_ptr<std::istream> &&stream) : Scanner()
{
    _stream = std::move(stream);
}

bool Scanner::Next(Lexeme &out)
{
    char ch;
    int peephole;
    bool in_line_comment, in_block_comment;

    if (_stream->eof() || _stream->fail())
        return false;

    in_line_comment = false;
    in_block_comment = false;
    for (;;) {
        if (!Get(ch)) {
            if (!_in_block) {
                return false;
            }
            throw ScannerException("unexpected end of file", _loc);
        }

        // ignore content in comments, including preprocessor directives
        if (in_line_comment) {
            if (ch == '\n') {
                in_line_comment = false;
            }
            continue;
        }
        if (in_block_comment) {
            if (ch == '*') {
                peephole = _stream->peek();
                if (peephole == static_cast<int>('/')) {
                    Get();
                    in_block_comment = false;
                }
            }
            continue;
        }

        if (ch == '{') {
            auto tmp = _loc;
            peephole = _stream->peek();
            if (peephole == static_cast<int>('%')) {
                if (_in_block) {
                    throw ScannerException("cannot open nested block", _loc);
                }
                Get();
                _cur_block.id = _block_id_counter++;
                _cur_block.open_loc = tmp;
                _cur_block.close_loc = Location();
                _in_block = true;
                continue;
            }
        }

        if (_in_block) {
            if (ch == '%') {
                peephole = _stream->peek();
                if (peephole == static_cast<int>('}')) {
                    Get();
                    _in_block = false;
                    continue;
                }
            }

            Unget();
            return ScanTokenAtPos(out);
        }
    }
}

bool Scanner::Get(char &ch)
{
    _stream->get(ch);
    if (_stream->eof() || _stream->fail()) {
        return false;
    }

    ++_loc.pos;
    ++_loc.col;
    if (ch == '\n') {
        ++_loc.lineno;
        _prev_col = _loc.col;
        _loc.col = 1;        
    }
    return true;
}

bool Scanner::Get()
{
    char ch;
    return Scanner::Get(ch);
}

void Scanner::Unget()
{
    _stream->unget();
    if (_stream->bad()) {
        throw ScannerException("failed to unget character at cursor", _loc);
    }
    --_loc.pos;
    if (_stream->peek() == static_cast<int>('\n')) {
        --_loc.lineno;
        _loc.col = _prev_col;
    }
}

bool Scanner::ScanTokenAtPos(Lexeme &out)
{
    char ch;
    int peephole;
    Location start;

    Get(ch);
    if (_stream->eof() || _stream->fail()) {
        return false;
    }

    switch (ch) {
    case '(':
        out = Lexeme(Token::L_PAREN, "(", _loc, _cur_block.id);
        break;
    case ')':
        out = Lexeme(Token::R_PAREN, ")", _loc, _cur_block.id);
        break;
    case ':':
        start = _loc;
        peephole = _stream->peek();
        if (peephole == static_cast<int>(':')) {
            out = Lexeme(Token::NS_DELIM, "::", start, _cur_block.id);
        } else {
            throw ScannerException("unrecognized token", _loc);
        }
        break;
    case '*':
        out = Lexeme(Token::ASTERISK, "*", _loc, _cur_block.id);
        break;
    case '&':
        out = Lexeme(Token::AMBERSAND, "&", _loc, _cur_block.id);
        break;
    case '<':
        out = Lexeme(Token::L_ANGLE_BRACKET, "<", _loc, _cur_block.id);
        break;
    case '>':
        out = Lexeme(Token::R_ANGLE_BRACKET, ">", _loc, _cur_block.id);
        break;
    case '=':
        out = Lexeme(Token::EQ_SIGN, "=", _loc, _cur_block.id);
        break;
    case ';':
        out = Lexeme(Token::SEMICOLON, ";", _loc, _cur_block.id);
        break;
    case ',':
        out = Lexeme(Token::COMMA, ",", _loc, _cur_block.id);
        break;
    case '"':
        return false;
    default:
        if (ch >= '0' && ch <= '9') {
            // scan number
        }
        if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) {
            // scan identifier or reserved word
        }

        throw ScannerException("unrecognized token", _loc);
    }

    return true;
}

std::string ScannerExceptionMessage(const std::string &msg, const Location &loc)
{
    return "error at " + loc.coords() + ": " + msg;
}

ScannerException::ScannerException(const std::string &msg, const Location &loc)
    : std::runtime_error(ScannerExceptionMessage(msg, loc)), _loc(loc)
{
}