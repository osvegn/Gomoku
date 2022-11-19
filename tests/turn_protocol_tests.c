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

/// answer_turn_protocol tests

Test(answer_turn_protocol, valide_test_using_position_0_0, .init = redirect_all_stdout)
{
    answer_turn_protocol(0, 0);
    cr_assert_stdout_eq_str("0,0\n");
}

Test(answer_turn_protocol, valide_test_using_position_8_4, .init = redirect_all_stdout)
{
    answer_turn_protocol(8, 4);
    cr_assert_stdout_eq_str("8,4\n");
}

Test(answer_turn_protocol, valide_test_using_position_158645_1, .init = redirect_all_stdout)
{
    answer_turn_protocol(158645, 1);
    cr_assert_stdout_eq_str("158645,1\n");
}


/// get_turn_protocol tests

Test(get_turn_protocol, valide_basic_get_turn_protocol)
{
    const char message[] = "TURN 9,5";
    unsigned int x = 0;
    unsigned int y = 0;
    int rvalue = get_turn_protocol(message, &x, &y);

    cr_assert_eq(rvalue, 0);
    cr_assert_eq(x, 9);
    cr_assert_eq(y, 5);
}

Test(get_turn_protocol, incorrect_message_get_turn_protocol)
{
    const char message[] = "TUR 5,6";
    unsigned int x = 0;
    unsigned int y = 0;
    int rvalue = get_turn_protocol(message, &x, &y);

    cr_assert_eq(rvalue, -1);
    cr_assert_eq(x, 0);
    cr_assert_eq(y, 0);
}

Test(get_turn_protocol, null_message_get_turn_protocol)
{
    const char *message = NULL;
    unsigned int x = 0;
    unsigned int y = 0;
    int rvalue = get_turn_protocol(message, &x, &y);

    cr_assert_eq(rvalue, -1);
    cr_assert_eq(x, 0);
    cr_assert_eq(y, 0);
}

Test(get_turn_protocol, null_x_get_turn_protocol)
{
    const char message[] = "TURN 5,6";
    unsigned int x = 0;
    unsigned int y = 0;
    int rvalue = get_turn_protocol(message, NULL, &y);

    cr_assert_eq(rvalue, -1);
    cr_assert_eq(x, 0);
    cr_assert_eq(y, 0);
}

Test(get_turn_protocol, null_y_get_turn_protocol)
{
    const char message[] = "TURN 5,6";
    unsigned int x = 0;
    unsigned int y = 0;
    int rvalue = get_turn_protocol(message, &x, NULL);

    cr_assert_eq(rvalue, -1);
    cr_assert_eq(x, 0);
    cr_assert_eq(y, 0);
}

Test(get_turn_protocol, valide_big_numbers_get_turn_protocol)
{
    const char message[] = "TURN 567891,6864121";
    unsigned int x = 0;
    unsigned int y = 0;
    int rvalue = get_turn_protocol(message, &x, &y);

    cr_assert_eq(rvalue, 0);
    cr_assert_eq(x, 567891);
    cr_assert_eq(y, 6864121);
}

Test(get_turn_protocol, invalide_negative_x_get_turn_protocol)
{
    const char message[] = "TURN -5,6";
    unsigned int x = 0;
    unsigned int y = 0;
    int rvalue = get_turn_protocol(message, &x, &y);

    cr_assert_eq(rvalue, -1);
    cr_assert_eq(x, 0);
    cr_assert_eq(y, 0);
}

Test(get_turn_protocol, invalide_negative_y_get_turn_protocol)
{
    const char message[] = "TURN 5,-6";
    unsigned int x = 0;
    unsigned int y = 0;
    int rvalue = get_turn_protocol(message, &x, &y);

    cr_assert_eq(rvalue, -1);
    cr_assert_eq(x, 5);
    cr_assert_eq(y, 0);
}
