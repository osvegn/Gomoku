set(SRC_TESTS_ROOT ${PROJECT_SOURCE_DIR}/tests)

# ADD TESTS FILES HERE
set(SRC_TESTS
    ${SRC_TESTS_ROOT}/template/template_unit_test.c
)

# ADD SOURCES FILES TO TEST HERE
set(SRC

)

add_executable(${PROJECT_NAME}_tests ${SRC} ${SRC_TESTS})

set_target_properties(${PROJECT_NAME}_tests
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/
)
