/*
** EPITECH PROJECT, 2022
** Gomoku
** File description:
** end_protocol
*/

#include "gomoku.h"
#include "board.h"

int handle_end_protocol(const char *message)
{
    const board_t *board = get_board();

    for (int i = 0; i < board->size * board->size; i++) {
        my_printf("%d", board->board[i]);
        if ((i + 1) % board->size == 0)
            my_printf("\n");
    }
    destroy_board();
    my_printf("end protocol\n");
    return 1;
}