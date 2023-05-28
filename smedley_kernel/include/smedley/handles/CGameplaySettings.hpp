#ifndef HANDLES_CGAMEPLAYSETTINGS_HPP_
#define HANDLES_CGAMEPLAYSETTINGS_HPP_

#include <cstdint>

#pragma pack(push, 1)

namespace smedley
{
namespace handles
{

struct CGameplaySettings
{
	void **vtable;
	uint8_t field1_0x4;
	uint8_t field2_0x5;
	uint8_t field3_0x6;
	uint8_t field4_0x7;
	uint8_t **field5_0x8;
};

}
}

#pragma pack(pop)

#endif // HANDLES_CGAMEPLAYSETTINGS_HPP_
