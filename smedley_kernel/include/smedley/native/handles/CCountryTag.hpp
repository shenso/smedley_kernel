#ifndef HANDLES_CCOUNTRYTAG_HPP_
#define HANDLES_CCOUNTRYTAG_HPP_

#include <cstdint>

#pragma pack(push, 1)

namespace smedley
{
namespace native
{
namespace handles
{

struct CCountryTag
{
	char str[4];
	int n;
};

}
}
}

#pragma pack(pop)

#endif // HANDLES_CCOUNTRYTAG_HPP_
