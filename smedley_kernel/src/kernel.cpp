#include "kernel.hpp"
#include <iostream>
#include <sstream>

#include <windows.h>
#include <tlhelp32.h>

constexpr DWORD PIPE_BUF_SIZE = 512;
constexpr DWORD PIPE_NUM_INSTANCES = 2;

namespace smedley
{
namespace core
{

HANDLE OpenPipe()
{
	HANDLE hPipe;
	BOOL connFailed;
	const char *pipeName;

	while (true) {
		pipeName = "\\\\.\\pipe\\smedley_launcher";
		hPipe = CreateFile(pipeName, GENERIC_WRITE, 0, NULL, OPEN_EXISTING, 0, NULL);

		if (hPipe != INVALID_HANDLE_VALUE) {
			return hPipe;
		}

		if (GetLastError() != ERROR_PIPE_BUSY) {
			throw std::runtime_error("failed to open pipe: " + GetLastError());
		}

		/*
		connFailed = ConnectNamedPipe(hPipe, NULL);
		if (connFailed) {
			throw std::runtime_error("failed to connect to pipe:");
		}
		*/

		if (!WaitNamedPipe(pipeName, 20000)) {
			throw std::runtime_error("could not open pipe: 20 second timeout passed");
		}
	}
}

Kernel::Kernel() : hProcess(INVALID_HANDLE_VALUE), processId(0)
{
}

void Kernel::Attach()
{
	std::stringstream ss;
	HANDLE hPipe;
	char buf[PIPE_BUF_SIZE];

	this->GetProcessInformation();

	MessageBoxA(NULL, "we are the champions", "HUZZAH", MB_ICONEXCLAMATION);

	hPipe = OpenPipe();
	std::strcpy(buf, "ready");
	std::cout << "writing to pipe...\n";
	if (!WriteFile(hPipe, buf, PIPE_BUF_SIZE, NULL, NULL)) {
		MessageBoxA(NULL, "smedley: failed to write to pipe. cannot resume game thread - terminating process.", "failure", MB_ICONEXCLAMATION);
	}
}

void Kernel::Detach()
{
}

void Kernel::GetProcessInformation()
{
	this->hProcess = GetCurrentProcess();
	this->processId = GetProcessId(this->hProcess);
}

} // core
} // smedley