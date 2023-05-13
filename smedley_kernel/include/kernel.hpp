#ifndef KERNEL_HPP_
#define KERNEL_HPP_

#include "plugin.hpp"
#include "injectors/console.hpp"

#include <memory>

#include <windows.h>
#include <processthreadsapi.h>

namespace smedley
{
namespace core
{

HANDLE OpenPipe();

class Kernel
{
	HANDLE _hProcess, _hBaseMod;
	DWORD _processId;

	std::unique_ptr<injectors::ConsoleCommandInjector> _consoleCommandInjector;

	static Kernel *_instance;
public:
	Kernel();

	void Attach();
	void Detach();

	static Kernel *GetInstance();
private:
	void GetProcessInformation();
	void OnComplete();
};

} // core
} // smedley

#endif // KERNEL_HPP