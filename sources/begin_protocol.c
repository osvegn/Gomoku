/*
** EPITECH PROJECT, 2022
** Gomoku
** File description:
** begin_protocol
*/

#include <string.h>
#include "gomoku.h"

int handle_begin_protocol(const char *message, const coords_t *coordinates,
const uint32_t size)
{
    const char expected[] = "BEGIN";

    if (!message || strcmp(message, expected) != 0)
        return -1;
    if (coordinates->x > size || coordinates->y > size)
        return -1;
    my_printf("%u, %u\r\n", coordinates->x, coordinates->y);
    return 0;
}
