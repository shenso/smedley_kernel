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


# generate docs if doxygen is installed
option(BUILD_DOC "Build documentation" OFF)
find_package(Doxygen)
if (DOXYGEN_FOUND)
  if (BUILD_DOC)
    # set input and output files
    set(DOXYGEN_IN ${CMAKE_CURRENT_SOURCE_DIR}/docs/Doxyfile.in)
    set(DOXYGEN_OUT ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)

    # request to configure the file
    configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)
    message("Doxygen build started")

    # note the option ALL which allows to build the docs together with the application
    add_custom_target( doc_doxygen ALL
        COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        COMMENT "Generating API documentation with Doxygen"
        VERBATIM )
  endif(BUILD_DOC)
else (DOXYGEN_FOUND)
  message("Doxygen need to be installed to generate the doxygen documentation")
endif (DOXYGEN_FOUND)