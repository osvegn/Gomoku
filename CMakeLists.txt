cmake_minimum_required(VERSION 3.17)

project(pbrain-gomoku-ai C)

set(INC_ROOT ${PROJECT_SOURCE_DIR}/include)
set(SRC_ROOT ${PROJECT_SOURCE_DIR}/sources)

set(MAIN
    ${PROJECT_SOURCE_DIR}/main.c
)

set(SRC
    ${SRC_ROOT}/my_printf.c
    ${SRC_ROOT}/readfile.c
    ${SRC_ROOT}/start_protocol.c
    ${SRC_ROOT}/turn_protocol.c
    CACHE INTERNAL "sources"
)

add_executable(${PROJECT_NAME} ${MAIN} ${SRC})

set_target_properties(${PROJECT_NAME}
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/
)

target_include_directories(${PROJECT_NAME}
    PUBLIC ${INC_ROOT}
)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
list(APPEND CMAKE_PREFIX_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

include(DetectCompiler)
