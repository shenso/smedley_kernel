cmake_minimum_required (VERSION 3.8)

FILE(GLOB_RECURSE preprocessor_sources src/*.cpp)
FILE(GLOB_RECURSE preprocessor_tests src/*.cpp tests/*.cpp)
list(FILTER preprocessor_tests EXCLUDE REGEX ".*main\\.cpp$") # give the entrypoint to gtest

include_directories(src)

enable_testing()
include(GoogleTest)

add_executable(preprocessor ${preprocessor_sources})
add_executable(preprocessor_run_tests ${preprocessor_tests})
target_link_libraries(preprocessor GTest::gtest)
target_link_libraries(preprocessor_run_tests GTest::gtest_main)
