#ifndef HANDLES_LEXEME_HPP_
#define HANDLES_LEXEME_HPP_

#include <cstdint>

#pragma pack(push, 1)

namespace smedley
{
namespace native
{
namespace handles
{

struct Lexeme
{
	LexerToken type;
	char str[256];
};

}
}
}

#pragma pack(pop)

#endif // HANDLES_LEXEME_HPP_
