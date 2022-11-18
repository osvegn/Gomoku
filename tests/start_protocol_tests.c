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

Test(start_answer_protocol, test_success_value, .init = redirect_all_stdout)
{
    answer_start_protocol(true, "success");
    cr_assert_stdout_eq_str("OK - success\n");
}

Test(answer_start_protocol, test_failure_value, .init = redirect_all_stdout)
{
    answer_start_protocol(false, "failure");
    cr_assert_stdout_eq_str("ERROR - failure\n");
}

Test(answer_start_protocol, test_success_without_message, .init = redirect_all_stdout)
{
    answer_start_protocol(true, NULL);
    cr_assert_stdout_eq_str("OK\n");
}

Test(answer_start_protocol, test_failure_withou_message, .init = redirect_all_stdout)
{
    answer_start_protocol(false, NULL);
    cr_assert_stdout_eq_str("ERROR\n");
}
