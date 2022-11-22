/*
** EPITECH PROJECT, 2022
** gomoku
** File description:
** gomoku
*/

#ifndef GOMOKU_H_
    #define GOMOKU_H_

    #include <stdbool.h>
    #include <stdio.h>
    #include "coordinates.h"

/**
 * @brief It prints the string passed to it,
 * and then flushes the output buffer.
 *
 * @param str The format string.
 */
void my_printf(const char *str, ...);

/**
 * @brief It reads a file and returns a pointer to a buffer containing
 * the file's contents.
 *
 * @param lineptr This is a pointer to a pointer to a character.
 * @param n The size of the buffer.
 * @param stream The file stream to read from.
 *
 * @return The number of characters read, or -1 on failure.
 */
int readfile(char **lineptr, size_t *n, FILE *stream);

/**
 * @brief It prints the coordinates of the tile you want to play.
 *
 * @param x The x coordinate of the tile you want to place your piece on.
 * @param y the y coordinate of the tile you want to place your piece on.
 */
void answer_turn_protocol(unsigned int x, unsigned int y);

/**
 * @brief It takes a string and two unsigned integers as arguments, and if
 * the string starts with "TURN ", it will parse the string and store the
 * two numbers in the unsigned integers.
 *
 * @param message The message to parse.
 * @param x the x coordinate of the player's turn
 * @param y The y coordinate of the player's turn
 *
 * @return 0 on success, -1 otherwise.
 */
int get_turn_protocol(const char *message, unsigned int *x, unsigned int *y);

/**
 * @brief It prints a message to the standard output.
 *
 * @param success a boolean that indicates whether the protocol was
 * successfully started or not.
 * @param message The message to send to the client.
 */
void answer_start_protocol(bool success, const char *message);

/**
 * @brief It takes a string and a pointer to an unsigned int, and if the
 * string is a valid start protocol message, it sets the unsigned int to the
 * size of the file and returns 0. Otherwise, it returns -1.
 *
 * @param message The message to parse.
 * @param size The size of the map to be set.
 *
 * @return 0 on success, -1 otherwise.
 */
int get_start_protocol(const char *message, unsigned int *size);

/**
 * @brief It takes a string, a pointer to a struct coordinates and an unsigned
 * int. If the string is a valid begin protocol message and the given
 * coordinates aren't superior to the size, it prints the coordinates on the
 * standard output and returns 0. Otherwise, it returns -1.
 *
 * @param message The message to check.
 * @param coordinates The coordinates of the next move.
 * @param size The size of the board.
 *
 * @return 0 on success, -1 otherwise.
 */
int handle_begin_protocol(const char *message, const coords_t *coordinates,
const uint32_t size);

#endif /* !GOMOKU_H_ */
