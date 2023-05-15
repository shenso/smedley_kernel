#ifndef FUNCTIONS_GAMESTATE_HPP_
#define FUNCTIONS_GAMESTATE_HPP_

#include "handles.hpp"
#include "functions/base.hpp"

namespace smedley
{
namespace functions
{

namespace CCurrentGameState
{

using namespace smedley::core;

handles::CGameState *GetInstance()
{
	return *(handles::CGameState **) (Kernel::GetInstance()->baseAddress() + 0xe588e8);
}

}

}
}

#endif // FUNCTIONS_GAMESTATE_HPP_
