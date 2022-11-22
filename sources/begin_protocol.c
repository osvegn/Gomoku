/*
** EPITECH PROJECT, 2022
** Gomoku
** File description:
** begin_protocol
*/

#include "board.h"
#include "gomoku.h"

static void get_dumb_ia(coords_t *coordinates)
{
    const board_t *board = get_board();

    for (int i = 0; i < board->size * board->size; i++) {
        if (board->board[i] == 0) {
            coordinates->x = i % board->size;
            coordinates->y = i / board->size;
            break;
        }
    }
}

int handle_begin_protocol(const char *message)
{
    coords_t coordinates = {0, 0};

    if (!message)
        return -1;
    get_dumb_ia(&coordinates);
    if (add_piece_to_board(coordinates.x, coordinates.y, 1) == -1)
        return -1;
    // call the ia to know wich move to do
    my_printf("%u, %u\r\n", coordinates.x, coordinates.y);
    return 0;
}
