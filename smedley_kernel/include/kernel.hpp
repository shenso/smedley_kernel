#ifndef KERNEL_HPP_
#define KERNEL_HPP_

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

	std::unique_ptr<injectors::ConsoleCommandInjector> _consoleCommandInjector;
public:
	Kernel();

	void Attach();
	void Detach();
private:
	void GetProcessInformation();
	void OnComplete();
};

} // core
} // smedley

#endif // KERNEL_HPP