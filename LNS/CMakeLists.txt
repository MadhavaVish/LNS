add_library(
    LNS SHARED
    include/LNS.h
    src/LNS.cpp
)

set_target_properties(
    LNS
    PROPERTIES
    POSITION_INDEPENDENT_CODE 1
)

target_include_directories(
    LNS
    PUBLIC    
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include> 
        $<INSTALL_INTERFACE:include>
        ${SPDLOG_INCLUDE_DIR}
)

target_link_libraries(
    LNS
    spdlog::spdlog
)