#include "injectors/console.hpp"
#include "memory.hpp"
#include "native/handles/CConsoleCommand.hpp"
#include "native/handles/ConsoleCommandOutput.hpp"

#include <algorithm>
#include <cstdint>
#include <stdexcept>

namespace smedley
{
namespace injectors
{

ConsoleCommandInjector *INJECTOR_BUF = nullptr;
DWORD RET_ADDR = NULL;

char *StringBuffer(std::string &str)
{
	char *buf = new char[str.size() + 1];
	std::strcpy(buf, str.c_str());
	return buf;
}

void InsertInjectedCommands(handles::vector<handles::CConsoleCommand *> *commands)
{
	DWORD growAddr;

	growAddr = INJECTOR_BUF->_baseAddr + 0x6513F0; // vector<?>::grow

	for (auto it = INJECTOR_BUF->injected().begin(); it != INJECTOR_BUF->injected().end(); it++) {
		if (commands->_last == commands->_end) {
			__asm {
				mov EAX, [commands]
				call[growAddr]
			}
		}

		*(commands->_last) = &(*it);
		commands->_last++;
	}
}

void __declspec(naked) InsertInjectedTrampoline()
{
	__asm {
		// save the current register context
		push eax
		push ecx
		push edx
		push esi

		push esi
		call InsertInjectedCommands
		pop esi

		// restore the context
		pop esi
		pop edx
		pop ecx
		pop eax

		// patched instructions
		pop edi
		pop esi
		pop ebx
		mov esp, ebp

		jmp RET_ADDR
	}
}

ConsoleCommandInjector::ConsoleCommandInjector(DWORD baseAddr) : _baseAddr(baseAddr)
{
	DWORD oldProtect;
	handles::CConsoleCommand *initCommands = (handles::CConsoleCommand *) (_baseAddr + INIT_CONSOLE_COMMANDS_ADDR);
	LPVOID patchAddr = (LPVOID) (_baseAddr + FUN_INIT_CONSOLE_COMMAND_VECTOR_INSTR);

	VirtualProtect(initCommands, sizeof(handles::CConsoleCommand) * 59, PAGE_EXECUTE_READWRITE, &oldProtect);
	for (int i = 0; i < 59; i++) {
		// keep paradox commands reserved 
		_registered.insert(initCommands[i].name);
	}
	VirtualProtect(initCommands, sizeof(handles::CConsoleCommand) * 59, oldProtect, &oldProtect);

	INJECTOR_BUF = this;
	RET_ADDR = (DWORD) patchAddr + 5;
	core::memory::Hook(patchAddr, InsertInjectedTrampoline, 5, nullptr);
}

void ConsoleCommandInjector::Inject(ConsoleCommandInfo &metadata, ConsoleCommandHandler handler)
{
	if (metadata.name.empty()) {
		throw std::runtime_error("the command requires a name");
	}

	if (_registered.find(metadata.name) != _registered.end()) {
		throw std::runtime_error("a command with name '" + metadata.name + "' already exists");
	}

	handles::CConsoleCommand cmd = {};
	std::memset(cmd.args, 0, sizeof(char *) * 9);

	cmd.isAllowed = true;
	cmd.name = StringBuffer(metadata.name);
	cmd.description = StringBuffer(metadata.description);
	cmd.alias = StringBuffer(metadata.alias);
	cmd.description = StringBuffer(metadata.description);
	cmd.handler = handler;
	cmd.param = StringBuffer(metadata.param);
	/*
	for (int i = 0; i < max(9, metadata.args.size()); i++) {
		cmd.args[i] = StringBuffer(metadata.args[i]);
	}
	*/

	_injected.push_back(cmd);
	_registered.insert(metadata.name);
}

std::vector<handles::CConsoleCommand> &ConsoleCommandInjector::injected()
{
	return _injected;
}

}
}