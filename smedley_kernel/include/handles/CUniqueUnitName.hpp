#ifndef HANDLES_CUNIQUEUNITNAME_HPP_
#define HANDLES_CUNIQUEUNITNAME_HPP_

#include <cstdint>
#include <handles/CUniqueUnitNameInternal.hpp>
#include <handles/vector.hpp>

#pragma pack(push, 1)

namespace smedley
{
namespace handles
{

struct CUniqueUnitName
{
	void **vftable;
	uint32_t field1_0x4;
	vector<CUniqueUnitNameInternal> names__;
};

}
}

#pragma pack(pop)

#endif // HANDLES_CUNIQUEUNITNAME_HPP_
