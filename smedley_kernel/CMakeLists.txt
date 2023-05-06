# CMakeList.txt : CMake project for smedley_kernel, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

include_directories("include")

FILE(GLOB kernel_sources src/*.cpp)

# Add source to this project's executable.
add_library (smedley_kernel MODULE ${kernel_sources})

# TODO: Add tests and install targets if needed.
