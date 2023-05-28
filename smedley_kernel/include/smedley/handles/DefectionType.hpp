#ifndef HANDLES_DEFECTIONTYPE_HPP_
#define HANDLES_DEFECTIONTYPE_HPP_

#include <cstdint>

namespace smedley
{
namespace handles
{

enum class DefectionType : uint32_t
{
	DEFECTION_CULTURE = 0,
	DEFECTION_CULTURE_GROUP = 1,
	DEFECTION_PAN_NATIONALIST = 2,
	DEFECTION_RELIGION = 3,
	DEFECTION_COLONIAL = 4,
	DEFECTION_IDEOLOGY = 5,
	DEFECTION_NONE = 6,
	DEFECTION_DEFAULT = 7
};

}
}

#endif //  HANDLES_DEFECTIONTYPE_HPP_