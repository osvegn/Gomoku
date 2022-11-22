/*
** EPITECH PROJECT, 2022
** Gomoku
** File description:
** begin_protocol
*/

#include <string.h>
#include "gomoku.h"

int handle_begin_protocol(const char *message)
{
    coords_t coordinates = {0, 0};

    if (!message)
        return -1;
    // call the ia to know wich move to do
    my_printf("%u, %u\r\n", coordinates.x, coordinates.y);
    return 0;
}
