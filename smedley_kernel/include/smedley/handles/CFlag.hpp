#ifndef HANDLES_CFLAG_HPP_
#define HANDLES_CFLAG_HPP_

#include <cstdint>
#include "basic_string.hpp"

#pragma pack(push, 1)

namespace smedley
{
namespace handles
{

struct CFlag
{
	basic_string<char> key;
	bool val;
	uint8_t field2_0x1d[3];
};

}
}

#pragma pack(pop)

#endif // HANDLES_CFLAG_HPP_
