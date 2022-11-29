/*
** EPITECH PROJECT, 2022
** gomoku
** File description:
** start_protocol_tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "gomoku.h"
#include "protocols.h"

/// handle_begin_protocol tests

Test(handle_begin_protocol, test_good_message)
{
    const char *test = "BEGIN";

    handle_begin_protocol(test);
}

Test(handle_begin_protocol, test_wrong_message)
{
    const char *test = "FKJBE";
    int rvalue = 0;

    rvalue = handle_begin_protocol(test);
    cr_assert_eq(rvalue, -1);
}

Test(handle_begin_protocol, test_too_high_x)
{
    const char *test = "BEGIN";
    int rvalue = 0;

    rvalue = handle_begin_protocol(test);
    cr_assert_eq(rvalue, -1);
}

Test(handle_begin_protocol, test_too_high_y)
{
    const char *test = "BEGIN";
    int rvalue = 0;

    rvalue = handle_begin_protocol(test);
    cr_assert_eq(rvalue, -1);
}
