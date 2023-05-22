#include "kernel.hpp"
#include "plugin.hpp"
#include "handles/CConsoleCommand.hpp"
#include "handles/ConsoleCommandOutput.hpp"
#include "functions/base.hpp"
#include <iostream>
#include <memory>
#include <string>

#include <windows.h>
#include <tlhelp32.h>

namespace smedley
{

namespace core
{

Kernel *Kernel::_instance = nullptr;

handles::ConsoleCommandOutput *KernelCommandHandler(handles::ConsoleCommandOutput *out, handles::vector<handles::basic_string<char>> *argv)
{
	out->message = handles::basic_string<char>();
	out->message.capacity = 0xf;
	out->message.size = 15;
	std::strcpy(out->message._impl, "smedley butler!");

	out->success = true;

	return out;
}

Kernel::Kernel() : _hProcess(INVALID_HANDLE_VALUE), _hBaseMod(INVALID_HANDLE_VALUE), _processId(0)
{
}

void Kernel::Attach()
{
	injectors::ConsoleCommandInfo cmdInfo = {};
	cmdInfo.name = "smedley";
	cmdInfo.description = "smedley butler";

	this->GetProcessInformation();

	_hooks = std::make_shared<hook::HookContainer>((DWORD) _hBaseMod);

	_consoleCommandInjector = std::make_shared<injectors::ConsoleCommandInjector>((DWORD) _hBaseMod);
	_consoleCommandInjector->Inject(cmdInfo, KernelCommandHandler);

	this->OnComplete();
}

void Kernel::Detach()
{
}

std::shared_ptr<PluginLoader> Kernel::pluginLoader()
{
	return _pluginLoader;
}

std::shared_ptr<hook::HookContainer> Kernel::hooks()
{
	return _hooks;
}

std::shared_ptr<injectors::ConsoleCommandInjector> Kernel::consoleInjector()
{
	return _consoleCommandInjector;
}

DWORD Kernel::baseAddress()
{
	return (DWORD) _hBaseMod;
}

Kernel *Kernel::instance()
{
	if (Kernel::_instance == nullptr) {
		Kernel::_instance = new Kernel();
	}

	return Kernel::_instance;
}

void Kernel::GetProcessInformation()
{
	_hProcess = GetCurrentProcess();
	_processId = GetProcessId(_hProcess);
	_hBaseMod =  GetModuleHandleA("v2game.exe");
}

void Kernel::OnComplete()
{
	_pluginLoader = std::make_shared<PluginLoader>();
}

} // core
} // smedley