cmake_minimum_required(VERSION 3.17)

project(gomoku C)

set(SRC
    main.c
)

add_executable(${PROJECT_NAME} ${SRC})

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
list(APPEND CMAKE_PREFIX_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

include(DetectCompiler)
