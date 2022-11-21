/*
** EPITECH PROJECT, 2022
** gomoku
** File description:
** board_tests
*/

#include <criterion/criterion.h>
#include "board.h"

Test(create_board, create_a_20_20_board)
{
    int rvalue = create_board(20);

    cr_assert_eq(rvalue, 0);
    destroy_board();
}

Test(get_board, empty_board_get_board)
{
    const board_t *board = get_board();

    cr_assert_eq(board->board, 0);
    cr_assert_eq(board->size, 0);
    destroy_board();
}

Test(get_board, get_20_20_board_get_board)
{
    int rvalue = create_board(20);
    const board_t *board = get_board();

    cr_assert_eq(rvalue, 0);
    cr_assert_neq(board->board, 0);
    cr_assert_eq(board->size, 20);
    destroy_board();
}

Test(add_piece_to_board, add_piece_at_2_5_on_20_20_board)
{
    int rvalue = create_board(20);
    const board_t *board = NULL;

    cr_assert_eq(rvalue, 0);
    rvalue = add_piece_to_board(2, 5, 1);
    cr_assert_eq(rvalue, 0);
    board = get_board();
    cr_assert_eq(board->board[5 * board->size + 2], 1);
    destroy_board();
}

Test(add_piece_to_board, add_piece_at_10_19_on_20_20_board)
{
    int rvalue = create_board(20);
    const board_t *board = NULL;

    cr_assert_eq(rvalue, 0);
    rvalue = add_piece_to_board(10, 19, 1);
    cr_assert_eq(rvalue, 0);
    board = get_board();
    cr_assert_eq(board->board[19 * board->size + 10], 1);
    destroy_board();
}

Test(add_piece_to_board, add_piece_out_of_the_board_x)
{
    int rvalue = create_board(20);

    cr_assert_eq(rvalue, 0);
    rvalue = add_piece_to_board(25, 2, 1);
    cr_assert_eq(rvalue, -1);
    destroy_board();
}

Test(add_piece_to_board, add_piece_out_of_the_board_y)
{
    int rvalue = create_board(20);

    cr_assert_eq(rvalue, 0);
    rvalue = add_piece_to_board(2, 25, 1);
    cr_assert_eq(rvalue, -1);
    destroy_board();
}

Test(add_piece_to_board, add_piece_on_empty_board)
{
    int rvalue = add_piece_to_board(2, 2, 1);

    cr_assert_eq(rvalue, -1);
    destroy_board();
}

Test(add_piece_to_board, add_piece_on_board_as_0_player)
{
    int rvalue = create_board(20);

    cr_assert_eq(rvalue, 0);
    rvalue = add_piece_to_board(5, 5, 0);
    cr_assert_eq(rvalue, -1);
    destroy_board();
}

Test(remove_piece_to_board, remove_piece_on_board_at_5_5)
{
    int rvalue = create_board(20);
    const board_t *board = NULL;

    cr_assert_eq(rvalue, 0);
    rvalue = add_piece_to_board(5, 5, 1);
    cr_assert_eq(rvalue, 0);
    rvalue = remove_piece_to_board(5, 5);
    cr_assert_eq(rvalue, 0);
    board = get_board();
    cr_assert_eq(board->board[5 * board->size + 5], 0);
    destroy_board();
}

Test(remove_piece_to_board, remove_piece_to_board_out_of_range_x)
{
    int rvalue = create_board(20);

    cr_assert_eq(rvalue, 0);
    rvalue = remove_piece_to_board(25, 2);
    cr_assert_eq(rvalue, -1);
    destroy_board();
}

Test(remove_piece_to_board, remove_piece_to_board_out_of_range_y)
{
    int rvalue = create_board(20);

    cr_assert_eq(rvalue, 0);
    rvalue = remove_piece_to_board(2, 25);
    cr_assert_eq(rvalue, -1);
    destroy_board();
}

Test(remove_piece_to_board, remove_piece_to_board_empty_board)
{
    int rvalue = remove_piece_to_board(2, 2);

    cr_assert_eq(rvalue, -1);
    destroy_board();
}
