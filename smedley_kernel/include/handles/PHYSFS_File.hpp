#ifndef HANDLES_PHYSFS_FILE_HPP_
#define HANDLES_PHYSFS_FILE_HPP_

#include <cstdint>

#pragma pack(push, 1)

namespace smedley
{
namespace handles
{

struct PHYSFS_File
{
	void * opaque;
};

}
}

#pragma pack(pop)

#endif // HANDLES_PHYSFS_FILE_HPP_
