# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# I hate c++ build systems
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

project ("smedley")

# Include sub-projects.
add_subdirectory ("smedley_kernel")
add_subdirectory ("plugins")
