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
 * @brief Increments the offset to pass the comma character.
 *
 * @param message The message to parse.
 * @param offset The offset to increment.
 */
static void move_offset(const char *message, size_t *offset)
{
    while (message[*offset] && message[*offset] != ',')
        (*offset)++;
    *offset++;
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

int get_turn_protocol(const char *message)
{
    size_t offset = 5;
    coords_t coordinates = {0, 0};

    if (!message)
        return -1;
    if (get_value_from_message(&(message[offset]), &(coordinates.x)) < 0)
        return -1;
    move_offset(message, &offset);
    if (get_value_from_message(&(message[offset]), &(coordinates.y)) < 0)
        return -1;
    if (add_piece_to_board(coordinates.x, coordinates.y, 2) == -1)
        return -1;
    // call the ia to put a piece
    get_dumb_ia(&coordinates);
    if (add_piece_to_board(coordinates.x, coordinates.y, 1) == -1)
        return -1;
    answer_turn_protocol(coordinates.x, coordinates.y);
    return 0;
}
