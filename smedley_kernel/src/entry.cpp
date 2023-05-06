// smedley_kernel.cpp : Defines the entry point for the application.
//

#include "kernel.hpp"

#include <iostream>
#include <windows.h>


smedley::core::Kernel *KERNEL;


BOOL __stdcall DllMain(HINSTANCE hInst, DWORD fdwReason, LPVOID lpvReserved)
{
	switch (fdwReason) {
	case DLL_PROCESS_ATTACH:
		if (KERNEL == nullptr) {
			KERNEL = new smedley::core::Kernel();
		}

		KERNEL->Attach();
		break;
	case DLL_PROCESS_DETACH:
		if (KERNEL != nullptr) {
			KERNEL->Detach();
			delete KERNEL;
		}
	}

	return TRUE;
}
