/*
** EPITECH PROJECT, 2022
** gomoku
** File description:
** gomoku
*/

#ifndef GOMOKU_H_
    #define GOMOKU_H_

    #include <stdio.h>
    #include <stdbool.h>
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
 * @brief It takes a string and two unsigned integers as arguments, and if
 * the string starts with "TURN ", it will parse the string and store the
 * two numbers in the unsigned integers.
 *
 * @param message The message to parse.
 *
 * @return 0 on success, -1 otherwise.
 */
int get_turn_protocol(const char *message);

/**
 * @brief It takes a string, if the string is a valid start protocol message,
 * it creates the board with the given size returns 0.
 * Otherwise, it returns -1.
 *
 * @param message The message to parse.
 *
 * @return 0 on success, -1 otherwise.
 */
int get_start_protocol(const char *message);

int handle_begin_protocol(const char *message);

int handle_board_protocol(const char *message);

int loop_in_protocols(void);

int handle_end_protocol(const char *message);

int handle_info_protocol(const char *message);

int answer_about_protocol(const char *message);

#endif /* !GOMOKU_H_ */
