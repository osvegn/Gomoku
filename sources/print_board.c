/*
** EPITECH PROJECT, 2022
** gomoku
** File description:
** print_board
*/

#include "board.h"
#include "gomoku.h"

void print_board(void)
{
    const board_t *board = get_board();

    for (unsigned int j = 0; j < board->size; j++) {
        my_printf("----");
    }
    my_printf("-\n");
    for (unsigned int i = 0; i < board->size; i++) {
        for (unsigned int j = 0; j < board->size; j++) {
            my_printf("| %i ", board->board[i * board->size + j]);
        }
        my_printf("|\n");
        for (unsigned int j = 0; j < board->size; j++) {
            my_printf("----");
        }
        my_printf("-\n");
    }
}
