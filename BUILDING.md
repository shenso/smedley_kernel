# Building Smedley

## Prerequisites

Smedley requires the following to be built:

    * [CMake >= 3.8](https://cmake.org/download/)
    * [Microsoft C++ Compiler (MSVC)](https://visualstudio.microsoft.com/vs/community/)

Smedley currently only supports building with MSVC (the compiler used to build v2game).

## Building

First one must configure CMake to use the Visual Studio generator and target the x86 architecture. In command prompt or your preferred shell environment, run the following command in the project directory:

```
cmake -DCMAKE_GENERATOR_PLATFORM=WIN32 -G "Visual Studio 17 2022" -B build
```

Next, build the binaries:

```
cmake --build build
```

(Optional) Install Smedley & V2UP in the game directory

```
cmake --install build
```

Keep in mind, while the kernel may be installed it is unusable without the bootstrapper.