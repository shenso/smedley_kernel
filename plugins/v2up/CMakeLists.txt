cmake_minimum_required (VERSION 3.8)

include_directories("../../smedley_kernel/include")

add_library (v2up MODULE plugin.cpp)
target_link_libraries(v2up smedley_kernel)
