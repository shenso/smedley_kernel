#include "kernel.hpp"
#include "plugin.hpp"
#include "handles/std.hpp"
#include <iostream>
#include <memory>
#include <string>

#include <windows.h>
#include <tlhelp32.h>

constexpr DWORD PIPE_BUF_SIZE = 512;
constexpr DWORD PIPE_NUM_INSTANCES = 2;
constexpr DWORD PIPE_ERR_CODE = 4215;

namespace smedley
{
namespace core
{

Kernel *Kernel::_instance = nullptr;

HANDLE OpenPipe()
{
	HANDLE hPipe;
	BOOL connFailed;
	const char *pipeName;

	while (true) {
		pipeName = "\\\\.\\pipe\\smedley_bootstrapper";
		hPipe = CreateFile(pipeName, GENERIC_WRITE, 0, NULL, OPEN_EXISTING, 0, NULL);

		if (hPipe != INVALID_HANDLE_VALUE) {
			return hPipe;
		}

		if (GetLastError() != ERROR_PIPE_BUSY) {
			throw std::runtime_error("failed to open pipe: " + GetLastError());
		}

		if (!WaitNamedPipe(pipeName, 20000)) {
			throw std::runtime_error("could not open pipe: 20 second timeout passed");
		}
	}
}

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

	_consoleCommandInjector = std::make_unique<injectors::ConsoleCommandInjector>((DWORD) _hBaseMod);
	_consoleCommandInjector->Inject(cmdInfo, KernelCommandHandler);
	std::cout << "command injector jobs done!" << std::endl;

	this->OnComplete();
}

void Kernel::Detach()
{
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

	/*
	HANDLE hPipe;
	char buf[PIPE_BUF_SIZE];

	hPipe = OpenPipe();
	std::strcpy(buf, "load_plugins\n");
	std::cout << "writing to pipe...\n";
	if (!WriteFile(hPipe, buf, PIPE_BUF_SIZE, NULL, NULL)) {
		MessageBoxA(NULL, "smedley: failed to write to pipe. cannot resume game thread - terminating process.", "failure", MB_ICONEXCLAMATION);
		ExitProcess(PIPE_ERR_CODE);
	}
	CloseHandle(hPipe);
	*/

}

} // core
} // smedley