#ifndef KERNEL_HPP_
#define KERNEL_HPP_

#include <windows.h>
#include <processthreadsapi.h>

namespace smedley
{
namespace core
{

class Kernel
{
	HANDLE hProcess;
	DWORD processId;

public:
	Kernel();

	void Attach();
	void Detach();
private:
	void GetProcessInformation();
};

} // core
} // smedley

#endif // KERNEL_HPP