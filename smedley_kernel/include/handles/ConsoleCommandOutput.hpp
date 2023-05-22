#ifndef HANDLES_CONSOLECOMMANDOUTPUT_HPP_
#define HANDLES_CONSOLECOMMANDOUTPUT_HPP_

#include <cstdint>
#include <handles/basic_string.hpp>

#pragma pack(push, 1)

namespace smedley
{
namespace handles
{

struct ConsoleCommandOutput
{
	bool success;
	uint8_t field1_0x1;
	uint8_t field2_0x2;
	uint8_t field3_0x3;
	basic_string<char> message;
};

}
}

#pragma pack(pop)

#endif // HANDLES_CONSOLECOMMANDOUTPUT_HPP_
