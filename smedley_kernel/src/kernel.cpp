#include "kernel.hpp"
#include "plugin.hpp"
#include "handles.hpp"
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
	char buf[1024];
	std::string testPlugin;

	injectors::ConsoleCommandInfo cmdInfo = {};
	cmdInfo.name = "smedley";
	cmdInfo.description = "smedley butler";
	cmdInfo.param = "if you're seeing this... it worked! we can inject into vic2! command just prints smedley butler";

	this->GetProcessInformation();

	_consoleCommandInjector = std::make_shared<injectors::ConsoleCommandInjector>((DWORD) _hBaseMod);
	_consoleCommandInjector->Inject(cmdInfo, KernelCommandHandler);
	std::cout << "command injector jobs done!" << std::endl;

	this->OnComplete();
}

void Kernel::Detach()
{
}

std::shared_ptr<PluginLoader> Kernel::pluginLoader()
{
	return _pluginLoader;
}

std::shared_ptr<injectors::ConsoleCommandInjector> Kernel::consoleInjector()
{
	return _consoleCommandInjector;
}

DWORD Kernel::baseAddress()
{
	return (DWORD) _hBaseMod;
}

Kernel *Kernel::GetInstance()
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