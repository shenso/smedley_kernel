#ifndef INJECTORS_CONSOLE_HPP_
#define INJECTORS_CONSOLE_HPP_

#include "native/handles/basic_string.hpp"
#include "native/handles/vector.hpp"
#include "native/handles/CConsoleCommand.hpp"
#include "native/handles/ConsoleCommandOutput.hpp"

#include <memory>
#include <string>
#include <unordered_set>
#include <vector>

#include <windows.h>

using namespace smedley::native;

namespace smedley
{
namespace injectors
{

typedef handles::ConsoleCommandOutput *(_cdecl *ConsoleCommandHandler)(handles::ConsoleCommandOutput *out, handles::vector<handles::basic_string<char>> *argv);

constexpr DWORD INIT_CONSOLE_COMMANDS_ADDR = 0x00b09740;
constexpr DWORD FUN_INIT_CONSOLE_COMMAND_VECTOR_INSTR = 0x00023a43;

struct ConsoleCommandInfo
{
	std::string name;
	std::string alias;
	std::string description;
	std::string param;
	std::vector<std::string> args;
};


class ConsoleCommandInjector
{
	std::vector<handles::CConsoleCommand> _injected;
	std::unordered_set<std::string> _registered;
	DWORD _baseAddr;

public:
	ConsoleCommandInjector(DWORD baseAddr);

	std::vector<handles::CConsoleCommand> &injected();

	void Inject(ConsoleCommandInfo &metadata, ConsoleCommandHandler handler);
	friend void InsertInjectedCommands(handles::vector<handles::CConsoleCommand *> *commands);
};

}
}

#endif // INJECTORS_CONSOLE_HPP_
