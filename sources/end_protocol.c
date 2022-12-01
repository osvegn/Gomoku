/*
** EPITECH PROJECT, 2022
** Gomoku
** File description:
** end_protocol
*/

#include "gomoku.h"
#include "board.h"

int handle_end_protocol(const char *UNUSED(message))
{
    destroy_board();
    return 1;
}