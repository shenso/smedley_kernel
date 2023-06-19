cmake_minimum_required (VERSION 3.8)

include_directories("../../smedley_kernel/include")

add_library (v2up MODULE "plugin.cpp")

# link libraries
target_link_libraries(v2up smedley_kernel)

# install
if(EXISTS ${PLUGINS_DIR})
	install(TARGETS v2up DESTINATION ${PLUGINS_DIR})
	install(FILES v2up.toml DESTINATION ${PLUGINS_DIR})
endif()