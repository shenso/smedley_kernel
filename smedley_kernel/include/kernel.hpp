#ifndef KERNEL_HPP_
#define KERNEL_HPP_

#include "plugin.hpp"
#include "hook/container.hpp"
#include "injectors/console.hpp"

#include <memory>

#include <windows.h>
#include <processthreadsapi.h>

namespace smedley
{
namespace core
{

class Kernel
{
	HANDLE _hProcess, _hBaseMod;
	DWORD _processId;

	std::shared_ptr<injectors::ConsoleCommandInjector> _consoleCommandInjector;
	std::shared_ptr<PluginLoader> _pluginLoader;
	std::shared_ptr<hook::HookContainer> _hooks;

	static Kernel *_instance;
public:
	Kernel();

	void Attach();
	void Detach();

	std::shared_ptr<PluginLoader> pluginLoader();
	std::shared_ptr<injectors::ConsoleCommandInjector> consoleInjector();
	std::shared_ptr<hook::HookContainer> hooks();

	DWORD baseAddress();

	static Kernel *instance();
private:
	void GetProcessInformation();
	void OnComplete();
};

} // core
} // smedley

#endif // KERNEL_HPP