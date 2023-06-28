# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

if(NOT V2_GAME_DIR)
	set(V2_GAME_DIR "C:\\Program Files (x86)\\Steam\\steamapps\\common\\Victoria 2")
endif()

set(CMAKE_SKIP_INSTALL_ALL_DEPENDENCY TRUE)

project ("smedley")

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Include sub-projects.
add_subdirectory ("smedley_kernel")
add_subdirectory ("plugins")
