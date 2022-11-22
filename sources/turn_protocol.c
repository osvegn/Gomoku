/*
** EPITECH PROJECT, 2022
** gomoku
** File description:
** turn_protocol
*/

#include <string.h>
#include <stdlib.h>
#include "gomoku.h"
#include "board.h"

/**
 * @brief It prints the coordinates of the tile you want to play.
 *
 * @param x The x coordinate of the tile you want to place your piece on.
 * @param y the y coordinate of the tile you want to place your piece on.
 */
static void answer_turn_protocol(unsigned int x, unsigned int y)
{
    my_printf("%i,%i\n", x, y);
}

/**
 * @brief It takes a string and an unsigned int pointer, and it sets the
 * unsigned int to the value of the string.
 *
 * @param message The message to parse.
 * @param coord The coordinate to be updated.
 *
 * @return 0 on success, -1 otherwise.
 */
static int get_value_from_message(const char *message, uint32_t *coord)
{
    int value = 0;

    value = atoi(message);
    if (value < 0)
        return -1;
    (*coord) = value;
    return 0;
}

int get_turn_protocol(const char *message)
{
    const int protocol_len = 5;
    unsigned int offset = 0;
    coords_t coordinates = {0, 0};

    if (!message)
        return -1;
    offset += protocol_len;
    if (get_value_from_message(message + offset, &coordinates.x) < 0)
        return -1;
    while (message[offset] && message[offset] != ',')
        offset++;
    if (get_value_from_message(message + offset + 1, &coordinates.y))
        return -1;
    if (add_piece_to_board(coordinates.x, coordinates.y, 2) == -1)
        return -1;
    // call the ia to put a piece
    answer_turn_protocol(0, 0);
    return 0;
}
