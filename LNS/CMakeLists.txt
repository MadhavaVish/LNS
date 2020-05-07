add_library(
    LNS SHARED
        LNS.h
        src/core.h
        src/Entrypoint.h
        src/Application.h
        src/Application.cpp
        src/Log.h
        src/Log.cpp
)

set_target_properties(
    LNS
    PROPERTIES
        POSITION_INDEPENDENT_CODE 1
)
target_compile_definitions(
    LNS
    PRIVATE
        -DLNS_BUILD_DLL
)
target_include_directories(
    LNS
    PUBLIC    
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}> 
        $<INSTALL_INTERFACE:include>
        ${SPDLOG_INCLUDE_DIR}
)
target_link_libraries(
    LNS
        ${SPDLOG_LIB}
)