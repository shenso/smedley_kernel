#ifndef HANDLES_AREA_HPP_
#define HANDLES_AREA_HPP_

namespace smedley
{
namespace handles
{

enum class Area : int
{
	AREA_NATION = 0,
	AREA_CULTURE = 1,
	AREA_CULTURE_GROUP = 2,
	AREA_NATION_CULTURE = 3,
	AREA_NATION_RELIGION = 4,
	AREA_RELIGION = 5,
	AREA_DEFAULT = 6
};

}
}

#endif // HANDLES_AREA_HPP_