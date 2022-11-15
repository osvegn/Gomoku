cmake_minimum_required(VERSION 3.17)

project(pbrain-gomoku-ai C)

set(SRC
    main.c
)

add_executable(${PROJECT_NAME} ${SRC})

set_target_properties(${PROJECT_NAME}
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/
)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
list(APPEND CMAKE_PREFIX_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

include(DetectCompiler)
