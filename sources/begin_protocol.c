/*
** EPITECH PROJECT, 2022
** Gomoku
** File description:
** begin_protocol
*/

#include "board.h"
#include "gomoku.h"

int handle_begin_protocol(const char *UNUSED(message))
{
    coords_t coordinates = {0, 0};

    get_dumb_ia(&coordinates);
    if (add_piece_to_board(coordinates.x, coordinates.y, 1) == -1)
        return -1;
    // call the ia to know wich move to do
    my_printf("%u,%u\r\n", coordinates.x, coordinates.y);
    return 0;
}
