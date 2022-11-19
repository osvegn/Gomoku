set(SRC_TESTS_ROOT ${PROJECT_SOURCE_DIR}/tests)

# ADD TESTS FILES HERE
set(SRC_TESTS
    ${SRC_TESTS_ROOT}/template/template_unit_test.c
    ${SRC_TESTS_ROOT}/start_protocol_tests.c
)

add_executable(${PROJECT_NAME}_tests ${SRC} ${SRC_TESTS})

set_target_properties(${PROJECT_NAME}_tests
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/
)

target_include_directories(${PROJECT_NAME}_tests
    PUBLIC ${INC_ROOT}
)
