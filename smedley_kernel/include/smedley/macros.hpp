#pragma once 

#ifdef SMEDLEY_KERNEL
#define SMEDLEY_API __declspec(dllexport)
#else
#define SMEDLEY_API __declspec(dllimport)
#endif