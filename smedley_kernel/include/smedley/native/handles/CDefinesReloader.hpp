#ifndef HANDLES_CDEFINESRELOADER_HPP_
#define HANDLES_CDEFINESRELOADER_HPP_

#include <cstdint>

#pragma pack(push, 1)

namespace smedley
{
namespace native
{
namespace handles
{

struct CDefinesReloader
{
	void **vftable;
};

}
}
}

#pragma pack(pop)

#endif // HANDLES_CDEFINESRELOADER_HPP_
