cmake_minimum_required(VERSION 3.14)

project(LearnNewShit)

if(MSVC)
	set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT Sandbox)
	add_definitions(-DLNS_PLATFORM_WINDOWS)
endif()

find_path(
	SPDLOG_INCLUDE_DIR
	NAMES spdlog/spdlog.h
	PATHS ${CMAKE_CURRENT_SOURCE_DIR}/vendor/spdlog/include
)

if((SPDLOG_INCLUDE_DIR-NOTFOUND) OR (NOT EXISTS ${SPDLOG_INCLUDE_DIR}))

	message("Unable to find spdlog")

	execute_process(COMMAND git submodule update --init -- vendor/spdlog
					WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
			
	find_path(
		SPDLOG_INCLUDE_DIR
		NAMES spdlog/spdlog.h
		PATHS ${CMAKE_CURRENT_SOURCE_DIR}/vendor/spdlog/include
	)		
	add_subdirectory(vendor/spdlog)
	
else()
	message("Found spdlog at ${SPDLOG_INCLUDE_DIR}")
	add_subdirectory(vendor/spdlog)
endif()

add_subdirectory(LNS)
add_subdirectory(Sandbox)

set_target_properties(
	LNS
    PROPERTIES
        LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/$<CONFIG>/lib
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/$<CONFIG>/bin
)
set_target_properties(
	Sandbox
	PROPERTIES
		RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/$<CONFIG>/bin
)