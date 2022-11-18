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

/// answer_start_protocol tests

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

Test(answer_start_protocol, test_failure_without_message, .init = redirect_all_stdout)
{
    answer_start_protocol(false, NULL);
    cr_assert_stdout_eq_str("ERROR\n");
}


/// get_start_protocol tests

Test(get_start_protocol, test_basic_valide_start_protocol)
{
    char message[] = "START 7";
    unsigned int size = 0;
    int rvalue = get_start_protocol(message, &size);

    cr_assert_eq(rvalue, 0);
    cr_assert_eq(size, 7);
}

Test(get_start_protocol, test_negative_start_value)
{
    char message[] = "START -2";
    unsigned int size = 0;
    int rvalue = get_start_protocol(message, &size);

    cr_assert_eq(rvalue, -1);
    cr_assert_eq(size, 0);
}

Test(get_start_protocol, test_invalide_protocol_name)
{
    char message[] = "AERFT 20";
    unsigned int size = 0;
    int rvalue = get_start_protocol(message, &size);

    cr_assert_eq(rvalue, -1);
    cr_assert_eq(size, 0);
}

Test(get_start_protocol, test_get_start_protocol_without_message)
{
    char *message = NULL;
    unsigned int size = 0;
    int rvalue = get_start_protocol(message, &size);

    cr_assert_eq(rvalue, -1);
    cr_assert_eq(size, 0);
}

Test(get_start_protocol, test_get_start_protocol_without_size_pointer)
{
    char message[] = "START 23";
    int rvalue = get_start_protocol(message, NULL);

    cr_assert_eq(rvalue, -1);
}

Test(get_start_protocol, test_get_start_protocol_with_high_value)
{
    char message[] = "START 123456789";
    unsigned int size = 0;
    int rvalue = get_start_protocol(message, &size);

    cr_assert_eq(rvalue, 0);
    cr_assert_eq(size, 123456789);
}
