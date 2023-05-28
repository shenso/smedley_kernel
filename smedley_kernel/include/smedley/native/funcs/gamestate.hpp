#ifndef FUNCTIONS_GAMESTATE_HPP_
#define FUNCTIONS_GAMESTATE_HPP_

#include "../handles/CGameState.hpp"

namespace smedley
{
namespace native
{
namespace funcs
{

namespace CCurrentGameState
{

using namespace smedley::core;

handles::CGameState *instance()
{
	return *(handles::CGameState **) (Kernel::instance()->baseAddress() + 0xe588e8);
}

}

}
}
}

#endif // FUNCTIONS_GAMESTATE_HPP_
