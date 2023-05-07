#include "injectors/console.hpp"
#include "handles/std.hpp"

#include <algorithm>
#include <cstdint>
#include <iostream>
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

	std::cout << "hook called!\n";

	growAddr = INJECTOR_BUF->_baseAddr + 0x6513F0; // vector<?>::grow

	for (auto it = INJECTOR_BUF->injected().begin(); it != INJECTOR_BUF->injected().end(); it++) {
		if (commands->last == commands->end) {
			__asm {
				mov EAX, [commands]
				call[growAddr]
			}
		}

		std::cout << "command injected: " << it->name << std::endl;

		*(commands->last) = &(*it);
		commands->last++;
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

	uint8_t patch[] = {
		// jmp [InsertInjectedTrampoline]
		0xe9, 0x90, 0x90, 0x90, 0x90,
	};
	*((DWORD *) (patch + 1)) = ((DWORD) InsertInjectedTrampoline - (DWORD) patchAddr) - 5;

	std::cout << "patching InitConsoleCommandVector function @ " << patchAddr << std::endl;
	for (int i = 0; i < sizeof(patch); i++) {
		std::cout << std::hex << (int) patch[i] << " ";
	}
	std::cout << std::dec << std::endl;


	INJECTOR_BUF = this;
	RET_ADDR = (DWORD) patchAddr + sizeof(patch);

	VirtualProtect(patchAddr, sizeof(patch), PAGE_EXECUTE_READWRITE, &oldProtect);
	std::memcpy(patchAddr, patch, sizeof(patch));
	VirtualProtect(patchAddr, sizeof(patch), oldProtect, &oldProtect);
}

void ConsoleCommandInjector::Inject(ConsoleCommandInfo &metadata, handles::ConsoleCommandHandler handler)
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