﻿#include "loader.hpp"
#include <windows.h>

BOOL __stdcall DllMain(HINSTANCE hInst, DWORD fdwReason, LPVOID lpvReserved)
{
    switch (fdwReason) {
    case DLL_PROCESS_ATTACH:
        smedley::PluginLoader::instance();
        break;
    case DLL_PROCESS_DETACH:
        break;
    }

    return TRUE;
}
