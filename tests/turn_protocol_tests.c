/*
** EPITECH PROJECT, 2022
** gomoku
** File description:
** turn_protocol_tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "gomoku.h"
#include "protocols.h"

/// get_turn_protocol tests

Test(get_turn_protocol, valide_basic_get_turn_protocol)
{
    create_board(20);
    const char message[] = "TURN 9,5";
    int rvalue = get_turn_protocol(message);

    cr_assert_eq(rvalue, 0);
}

Test(get_turn_protocol, incorrect_message_get_turn_protocol)
{
    create_board(20);
    const char message[] = "TURN 5,6";
    int rvalue = get_turn_protocol(message);

    cr_assert_eq(rvalue, 0);
}

Test(get_turn_protocol, null_message_get_turn_protocol)
{
    create_board(20);
    const char *message = NULL;
    int rvalue = get_turn_protocol(message);

    cr_assert_eq(rvalue, -1);
}

Test(get_turn_protocol, null_x_get_turn_protocol)
{
    create_board(20);
    const char message[] = "TURN 5,6";
    int rvalue = get_turn_protocol(message);

    cr_assert_eq(rvalue, 0);
}

Test(get_turn_protocol, null_y_get_turn_protocol)
{
    create_board(20);
    const char message[] = "TURN 5,6";
    int rvalue = get_turn_protocol(message);

    cr_assert_eq(rvalue, 0);
}

Test(get_turn_protocol, valide_big_numbers_get_turn_protocol)
{
    create_board(20);
    const char message[] = "TURN 567891,6864121";
    int rvalue = get_turn_protocol(message);

    cr_assert_eq(rvalue, -1);
}

Test(get_turn_protocol, invalide_negative_x_get_turn_protocol)
{
    create_board(20);
    const char message[] = "TURN -5,6";
    int rvalue = get_turn_protocol(message);

    cr_assert_eq(rvalue, -1);
}

Test(get_turn_protocol, invalide_negative_y_get_turn_protocol)
{
    create_board(20);
    const char message[] = "TURN 5,-6";
    int rvalue = get_turn_protocol(message);

    cr_assert_eq(rvalue, -1);
}
