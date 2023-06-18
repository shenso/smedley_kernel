#include "kernel.hpp"
#include "plugin.hpp"
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


Kernel::Kernel() : _hProcess(INVALID_HANDLE_VALUE), _hBaseMod(INVALID_HANDLE_VALUE), _processId(0)
{
}

void Kernel::Attach()
{
	this->OnComplete();
}

void Kernel::Detach()
{
}

std::shared_ptr<PluginLoader> Kernel::pluginLoader()
{
	return _pluginLoader;
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