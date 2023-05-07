#ifndef HANDLES_CONSOLE_HPP_
#define HANDLES_CONSOLE_HPP_

#pragma pack(push, 1)

#include "std.hpp"

#include <cstdint>

namespace smedley
{
namespace handles
{

struct ConsoleCommandOutput
{
	bool success;
	uint8_t field1_0x1[3];
	basic_string<char> message;
};

typedef ConsoleCommandOutput *(*ConsoleCommandHandler)(ConsoleCommandOutput *, vector<basic_string<char>> *);

struct CConsoleCommand
{
	bool isAllowed;
	uint8_t field1_0x1[3];
	const char *name;
	uint32_t field3_0x8;
	const char *alias;
	uint32_t field5_0x10;
	uint32_t field6_0x14;
	const char *description;
	ConsoleCommandOutput *(*handler)(ConsoleCommandOutput *, vector<basic_string<char>> *);
	uint32_t field9_0x20;
	const char *param;
	const char *args[9];
};

}
}

#pragma pack(pop)

#endif // HANDLES_CONSOLE_HPP_