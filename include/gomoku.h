/*
** EPITECH PROJECT, 2022
** gomoku
** File description:
** gomoku
*/

#ifndef GOMOKU_H_
#define GOMOKU_H_

#include <stdbool.h>

/**
 * @brief It prints the string passed to it,
 * and then flushes the output buffer.
 *
 * @param str The format string.
 */
void my_printf(const char *str, ...);

/**
 * @brief It reads from stdin until EOF, and returns the content as a string.
 *
 * @param content a pointer to a pointer to a char. This is the content of the
 * file.
 */
void readstdin(char **content);

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
 * @brief It prints the coordinates of the tile you want to play.
 *
 * @param x The x coordinate of the tile you want to place your piece on.
 * @param y the y coordinate of the tile you want to place your piece on.
 */
void answer_turn_protocol(unsigned int x, unsigned int y);

#endif /* !GOMOKU_H_ */
