#include <cstring>
#include <iostream>
#include <numeric>
#include <memory>
#include <string>
#include <sstream>
#include <vector>

#include <windows.h>
#include <memoryapi.h>
#include <processthreadsapi.h>

constexpr DWORD PIPE_BUF_SIZE = 512;
constexpr DWORD PIPE_NUM_INSTANCES = 2;

struct SmedleyRequest
{
	std::string path;
	std::string argv;
	std::string kernel;
};

struct ProcessPipes
{
	HANDLE hCommPipe;
	HANDLE hStdoutReader, hStdoutWriter;
};

struct SignalListener
{
	HANDLE hPipe;
	HANDLE hProcess, hThread;
};

// TODO: first look at PWD, then game directory, then try build path layout
std::string FindKernel()
{
	char buf[512];
	const char *localPath = "..\\smedley_kernel\\smedley_kernel.dll";

	ZeroMemory(buf, 512);
	if (GetFullPathNameA(localPath, 512, buf, NULL) == 0) {
		throw std::runtime_error("failed to find kernel file: " + GetLastError());
	}

	return std::string(buf);
}

// TODO: first look at PWD, then lookup steam path and fine game path from vdf file
std::string GetGameDirectory()
{
	return "C:\\Program Files (x86)\\Steam\\steamapps\\common\\Victoria 2";
}

std::unique_ptr<SmedleyRequest> ParseArgs(int argc, char **argv)
{
	auto req = std::unique_ptr<SmedleyRequest>(new SmedleyRequest);
	std::stringstream outputStream;
	char pathBuf[512];

	if (argc > 1) {
		if (argc == 2 && std::strcmp(argv[1], "--help") == 0) {
			return nullptr;
		}

		for (int i = 1; i < argc; i += 2) {
			if (std::strcmp(argv[i], "--argv") == 0) {
				if (i+1 >= argc) {
					throw std::runtime_error("expected argument got none");
				}
				req->argv = std::string(argv[i + 1]);
			} else if (std::strcmp(argv[i], "--path") == 0) {
				if (i + 1 >= argc) {
					throw std::runtime_error("expected argument got none");
				}
				req->path = std::string(argv[i + 1]);
			} else if (std::strcmp(argv[i], "--kernel") == 0) {
				if (i + 1 >= argc) {
					throw std::runtime_error("expected argument got none");
				}
				auto relativePath = std::string(argv[i + 1]);
				if (!GetFullPathNameA(argv[i + 1], 512 * sizeof(char), pathBuf, NULL)) {
					outputStream << "invalid path '" << pathBuf << "'";
					throw std::runtime_error(outputStream.str());
				}

				req->kernel = std::string(pathBuf);
			} else {
				outputStream << "unrecognized flag [" << argv[i] << "]";
				throw std::runtime_error(outputStream.str());
			}
		}
	}

	if (req->path.empty()) {
		req->path = GetGameDirectory() + "\\v2game.exe";
	}

	if (req->kernel.empty()) {
		req->kernel = FindKernel();
	}
	
	auto buf = outputStream.str();
	if (!buf.empty()) {
		std::cout << buf << std::endl;
	}

	return req;
}

std::unique_ptr<PROCESS_INFORMATION> OpenVic2(SmedleyRequest &req, HANDLE out)
{
	BOOL success; 
	char buf[512];
	STARTUPINFO startupInfo = {sizeof(STARTUPINFO)};
	std::unique_ptr<PROCESS_INFORMATION> procInfo(new PROCESS_INFORMATION);

	startupInfo.hStdOutput = out;
	startupInfo.hStdError = out;
	startupInfo.dwFlags |= STARTF_USESTDHANDLES;

	std::string dirname = req.path.substr(0, req.path.find_last_of("/\\"));
	std::strncpy(buf, (req.path + " " + req.argv).c_str(), 512);

	std::cout << "pwd: " << dirname << "..." << std::endl;
	std::cout << "launching " << req.path << "..." << std::endl;
	std::cout << "command line: " << buf << std::endl;
	std::cout << "kernel path: " << req.kernel << std::endl;

	SetCurrentDirectory(dirname.c_str());
	success = CreateProcessA(req.path.c_str(), buf, NULL, NULL, TRUE, CREATE_SUSPENDED, NULL, NULL, &startupInfo, procInfo.get());
	if (!success) {
		throw std::runtime_error("failed to create the remote process");
	}

	return procInfo;
}

HANDLE CreateKernelThread(HANDLE hProcess, std::string modPath)
{
	auto modNameSize = (modPath.size() + 1) * sizeof(char);
	// allocate space for dll path in process
	LPVOID modNameBuf = VirtualAllocEx(hProcess, NULL, modNameSize, MEM_COMMIT, PAGE_READWRITE);
	// write dll path to process
	WriteProcessMemory(hProcess, modNameBuf, modPath.c_str(), modNameSize, NULL);
	PTHREAD_START_ROUTINE subroutine = (PTHREAD_START_ROUTINE) GetProcAddress(GetModuleHandleA("Kernel32"), "LoadLibraryA");
	// once the thread has been created the kernel assumes control of the process and the launcher has done its job
	return CreateRemoteThread(hProcess, NULL, 0, subroutine, modNameBuf, 0, NULL);
}

ProcessPipes OpenPipes()
{
	BOOL connFailed;
	SECURITY_ATTRIBUTES saAttr;
	ProcessPipes pipes = {};

	saAttr.nLength = sizeof(SECURITY_ATTRIBUTES);
	saAttr.bInheritHandle = TRUE;
	saAttr.lpSecurityDescriptor = NULL;

	pipes.hCommPipe = CreateNamedPipe(
		"\\\\.\\pipe\\smedley_launcher",
		PIPE_ACCESS_DUPLEX,
		PIPE_TYPE_MESSAGE | PIPE_READMODE_MESSAGE | PIPE_WAIT,
		PIPE_NUM_INSTANCES,
		PIPE_BUF_SIZE,
		PIPE_BUF_SIZE,
		1000,
		NULL);
	if (pipes.hCommPipe == INVALID_HANDLE_VALUE) {
		throw std::runtime_error("failed to open communication pipe: " + GetLastError());
	}

	if (!CreatePipe(&pipes.hStdoutReader, &pipes.hStdoutWriter, &saAttr, 0)) {
		CloseHandle(pipes.hCommPipe);
		throw std::runtime_error("failed to open stdout pipe");
	}

	return pipes;
}

DWORD WINAPI SignalListenerWorker(LPVOID lpParam)
{
	BOOL success;
	char buf[PIPE_BUF_SIZE];
	DWORD bytesRead;

	SignalListener listener = *((SignalListener *) lpParam);

	ZeroMemory(buf, sizeof(char) * PIPE_BUF_SIZE);

	std::cout << "connecting to pipe..." << std::endl;
	if (!ConnectNamedPipe(listener.hPipe, NULL)) {
		std::cerr << "failed to establish pipe connection with client: " << GetLastError() << std::endl;
		return 2;
	}

	std::cout << "reading pipe..." << std::endl;
	success = ReadFile(listener.hPipe, buf, PIPE_BUF_SIZE * sizeof(char), &bytesRead, NULL);
	if (!success) {
		std::cerr << "failed to read pipe: " << GetLastError() << std::endl;
		return 2;
	}

	if (std::strcmp(buf, "ready") == 0) {
		ResumeThread(listener.hThread);
		std::cout << "main game thread resumed!\n";
	} else {
		std::cerr << "unexpected message from pipe: " << buf << std::endl;
	}
}

HANDLE ListenForResumeSignalAsync(HANDLE hProcess, HANDLE hThread, HANDLE hPipe)
{
	HANDLE hListenerThread;
	DWORD threadId;
	SignalListener *listener = new SignalListener;

	listener->hProcess = hProcess;
	listener->hThread = hThread;
	listener->hPipe = hPipe;

	hListenerThread = CreateThread(NULL, 0, SignalListenerWorker, (LPVOID) listener, 0, &threadId);
	if (hListenerThread == NULL || hListenerThread == INVALID_HANDLE_VALUE) {
		throw std::runtime_error("failed to create listener thread");
	}

	return hListenerThread;
}

int main(int argc, char **argv)
{
	std::unique_ptr<SmedleyRequest> req;
	std::unique_ptr<PROCESS_INFORMATION> procInfo;
	ProcessPipes pipes;
	HANDLE hModThread, hListenerThread;
	HANDLE hStdout;
	BOOL success;
	DWORD bytesRead, bytesWritten;
	char outBuf[2048];

	try {
		req = ParseArgs(argc, argv);
	} catch (std::runtime_error &exc) {
		std::cerr << exc.what() << std::endl;
		return 1;
	}

	if (req == nullptr) {
		return 0;
	}

	try {
		pipes = OpenPipes();
		std::cout << "pipe opened: " << pipes.hCommPipe << std::endl;
	} catch (std::runtime_error &exc) {
		std::cerr << exc.what() << std::endl;
		TerminateProcess(procInfo->hProcess, 1);
		CloseHandle(procInfo->hThread);
		CloseHandle(procInfo->hProcess);
		return 2;
	}

	procInfo = OpenVic2(*req, pipes.hStdoutWriter);

	hListenerThread = ListenForResumeSignalAsync(procInfo->hProcess, procInfo->hThread, pipes.hCommPipe);

	// create the thread now that the pipe is available for connection
	hModThread = CreateKernelThread(procInfo->hProcess, req->kernel);
	std::cout << "kernel thread opened: " << hModThread << std::endl;

	hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	while (true) {
		success = ReadFile(pipes.hStdoutReader, outBuf, 2048, &bytesRead, NULL);
		if (success == FALSE || bytesRead == 0) {
			break;
		}

		if (!WriteFile(hStdout, outBuf, bytesRead, &bytesWritten, NULL)) {
			break;
		}
	}

	CloseHandle(hListenerThread);
	CloseHandle(hModThread);
	CloseHandle(procInfo->hThread);
	CloseHandle(procInfo->hProcess);
	return 0;
}