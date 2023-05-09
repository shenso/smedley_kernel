// smedley_kernel.cpp : Defines the entry point for the application.
//

#include "kernel.hpp"
#include <windows.h>

using namespace smedley::core;

BOOL __stdcall DllMain(HINSTANCE hInst, DWORD fdwReason, LPVOID lpvReserved)
{
	switch (fdwReason) {
	case DLL_PROCESS_ATTACH:
		Kernel::GetInstance()->Attach();
		break;
	case DLL_PROCESS_DETACH:
		Kernel::GetInstance()->Detach();
	}

	return TRUE;
}
