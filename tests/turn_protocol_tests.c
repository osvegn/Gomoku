/*
** EPITECH PROJECT, 2022
** gomoku
** File description:
** turn_protocol_tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "gomoku.h"

static void redirect_all_stdout()
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(answer_start_protocol, valide_test_using_position_0_0, .init = redirect_all_stdout)
{
    answer_turn_protocol(0, 0);
    cr_assert_stdout_eq_str("0,0\n");
}

Test(answer_start_protocol, valide_test_using_position_8_4, .init = redirect_all_stdout)
{
    answer_turn_protocol(8, 4);
    cr_assert_stdout_eq_str("8,4\n");
}

Test(answer_turn_protocol, valide_test_using_position_158645_1, .init = redirect_all_stdout)
{
    answer_turn_protocol(158645, 1);
    cr_assert_stdout_eq_str("158645,1\n");
}
