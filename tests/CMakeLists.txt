set(SRC_TESTS_ROOT ${PROJECT_SOURCE_DIR}/tests)

# ADD TESTS FILES HERE
set(SRC_TESTS
    ${SRC_TESTS_ROOT}/template/template_unit_test.c
    ${SRC_TESTS_ROOT}/start_protocol_tests.c
    ${SRC_TESTS_ROOT}/begin_protocol_tests.c
    ${SRC_TESTS_ROOT}/turn_protocol_tests.c
    ${SRC_TESTS_ROOT}/readfile_tests.c
    ${SRC_TESTS_ROOT}/board_tests.c
)

add_executable(${PROJECT_NAME}_tests ${SRC} ${SRC_TESTS})

target_include_directories(${PROJECT_NAME}_tests
    PUBLIC ${INC_ROOT}
)

add_test(${PROJECT_NAME}_tests ${PROJECT_NAME}_tests)
