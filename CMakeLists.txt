cmake_minimum_required(VERSION 3.14)
project(LearnNewShit)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")

if(MSVC)
	set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT Sandbox)
endif()

find_path(
	SPDLOG_INCLUDE_DIR
	NAMES spdlog/spdlog.h
	PATHS ${CMAKE_CURRENT_SOURCE_DIR}/vendor/spdlog/
	PATH_SUFFIXES include
	)
if((SPDLOG_INCLUDE_DIR-NOTFOUND))
	message("Unable to find spdlog")

	execute_process(COMMAND git submodule update --init -- vendor/spdlog
					WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
	add_subdirectory(vendor/spdlog)
	
else()
	message("find spdlog ${SPDLOG_INCLUDE_DIR}")
	add_subdirectory(vendor/spdlog)
endif()


add_subdirectory(Sandbox)
add_subdirectory(LNS)