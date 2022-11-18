/*
** EPITECH PROJECT, 2022
** gomoku
** File description:
** turn_protocol
*/

#include "gomoku.h"

void answer_turn_protocol(unsigned int x, unsigned int y)
{
    my_printf("%i,%i\n", x, y);
}

/**
 * @brief It takes a string and an unsigned int pointer, and it sets the
 * unsigned int to the value of the string.
 *
 * @param message The message to parse.
 * @param coord The coordinate to be updated.
 */
static void get_value_from_message(const char *message, unsigned int *coord)
{
    int value = 0;

    value = atoi(message);
    if (value < 0)
        return -1;
    (*coord) = value;
}

int get_turn_protocol(const char *message, unsigned int *x, unsigned int *y)
{
    const char protocol[] = "TURN ";
    const int protocol_len = 5;
    unsigned int offset = 0;

    if (!message || !x || !y || strncmp(message, protocol, protocol_len))
        return -1;
    offset += protocol_len;
    get_value_from_message(message + offset, x);
    while (message[offset] && message[offset] != ',')
        offset++;
    get_value_from_message(message + offset, y);
    return 0;
}
