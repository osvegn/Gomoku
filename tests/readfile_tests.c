/*
** EPITECH PROJECT, 2022
** gomoku
** File description:
** readfile_tests
*/

#include <criterion/criterion.h>
#include "gomoku.h"

Test(readfile, valide_test_file_to_read_readfile)
{
    FILE *file = fopen("tests/tests_files/basic_file_to_read.txt", "r+");
    char *buffer = NULL;
    size_t size = 0;
    int rvalue = 0;

    if (!file)
        return;
    rvalue = readfile(&buffer, &size, file);
    cr_assert_eq(rvalue, 18);
    cr_assert_str_eq(buffer, "basic file to read");
    cr_assert_eq(size, 128);
    free(buffer);
}

Test(reafile, first_argument_is_null_readfile)
{
    FILE *file = fopen("tests/tests_files/basic_file_to_read.txt", "r+");
    size_t size = 0;
    int rvalue = 0;

    if (!file)
        return;
    rvalue = readfile(NULL, &size, file);
    cr_assert_eq(rvalue, -1);
    cr_assert_eq(size, 0);
}

Test(readfile, second_argument_is_null_readfile)
{
    FILE *file = fopen("tests/tests_files/basic_file_to_read.txt", "r+");
    char *buffer = NULL;
    int rvalue = 0;

    if (!file)
        return;
    rvalue = readfile(&buffer, NULL, file);
    cr_assert_eq(rvalue, -1);
    cr_assert_eq(buffer, 0);
}

Test(readfile, third_argument_is_null_readfile)
{
    char *buffer = NULL;
    size_t size = 0;
    int rvalue = 0;

    rvalue = readfile(&buffer, &size, NULL);
    cr_assert_eq(rvalue, -1);
    cr_assert_eq(size, 0);
    cr_assert_eq(buffer, 0);
}
