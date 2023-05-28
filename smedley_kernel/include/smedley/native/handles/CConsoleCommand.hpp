#ifndef HANDLES_CCONSOLECOMMAND_HPP_
#define HANDLES_CCONSOLECOMMAND_HPP_

#include <cstdint>
#include "basic_string.hpp"
#include "vector.hpp"

#pragma pack(push, 1)

namespace smedley
{
namespace native
{
namespace handles
{

struct ConsoleCommandOutput;

struct CConsoleCommand
{
	bool isAllowed;
	uint8_t field1_0x1;
	uint8_t field2_0x2;
	uint8_t field3_0x3;
	char *name;
	uint32_t field5_0x8;
	char *alias;
	uint32_t field7_0x10;
	uint32_t field8_0x14;
	char *description;
	ConsoleCommandOutput *(*handler)(ConsoleCommandOutput *out, vector<basic_string<char>> *argv);
	uint32_t field11_0x20;
	char *param;
	char *args[9];
};

}
}
}

#pragma pack(pop)

#endif // HANDLES_CCONSOLECOMMAND_HPP_
