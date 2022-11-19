/*
** EPITECH PROJECT, 2022
** gomoku
** File description:
** start_protocol_tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "gomoku.h"

static void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

/// handle_begin_protocol tests

Test(handle_begin_protocol, test_good_message, .init = redirect_all_stdout)
{
    const char *test = "BEGIN";
    const coords_t coords_test = {10, 10};

    handle_begin_protocol(test, coords_test, 20);
    cr_assert_stdout_eq_str("10, 10\r\n");
}

Test(handle_begin_protocol, test_wrong_message, .init = redirect_all_stdout)
{
    const char *test = "FKJBE";
    const coords_t coords_test = {10, 10};
    int rvalue = 0;

    rvalue = handle_begin_protocol(test, coords_test, 20);
    cr_assert_eq(rvalue, -1);
    cr_assert_stdout_eq_str("");
}

Test(handle_begin_protocol, test_too_high_x, .init = redirect_all_stdout)
{
    const char *test = "BEGIN";
    const coords_t coords_test = {100, 10};
    int rvalue = 0;

    rvalue = handle_begin_protocol(test, coords_test, 20);
    cr_assert_eq(rvalue, -1);
    cr_assert_stdout_eq_str("");
}

Test(handle_begin_protocol, test_too_high_y, .init = redirect_all_stdout)
{
    const char *test = "BEGIN";
    const coords_t coords_test = {10, 100};
    int rvalue = 0;

    rvalue = handle_begin_protocol(test, coords_test, 20);
    cr_assert_eq(rvalue, -1);
    cr_assert_stdout_eq_str("");
}
