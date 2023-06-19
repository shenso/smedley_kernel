cmake_minimum_required (VERSION 3.8)

if(NOT PLUGINS_DIR)
	set(PLUGINS_DIR "${V2_GAME_DIR}\\plugins")
endif()

add_subdirectory("v2up")
