# CMakeList.txt : CMake project for smedley_kernel, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

FILE(GLOB_RECURSE kernel_sources src/*.cpp)

# include directories
include_directories("include" "include/smedley")

# add sources
add_library (smedley_kernel SHARED ${kernel_sources})
target_compile_definitions(smedley_kernel PRIVATE SMEDLEY_KERNEL)

# setup testing
enable_testing()
add_executable(run_tests tests/plugin_test.cpp tests/util_test.cpp)
target_link_libraries(run_tests GTest::gtest_main smedley_kernel)

include(GoogleTest)
gtest_discover_tests(run_tests)

if(EXISTS ${V2_GAME_DIR})
	install(TARGETS smedley_kernel DESTINATION ${V2_GAME_DIR})
endif()
