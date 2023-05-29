# CMakeList.txt : CMake project for smedley_kernel, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

FILE(GLOB_RECURSE kernel_sources src/*.cpp)

include_directories("include/smedley")

# Add source to this project's executable.
add_library (smedley_kernel SHARED ${kernel_sources})
target_compile_definitions(smedley_kernel PRIVATE SMEDLEY_KERNEL)

# TODO: Add tests and install targets if needed.
