/*
** EPITECH PROJECT, 2022
** gomoku
** File description:
** gomoku
*/

#ifndef GOMOKU_H_
    #define GOMOKU_H_

    #ifdef __GNUC__
    #  define UNUSED(x) UNUSED_ ## x __attribute__((__unused__))
    #else
    #  define UNUSED(x) UNUSED_ ## x
    #endif


    #include <stdio.h>
    #include <stdbool.h>
    #include "coordinates.h"
    #include "board.h"

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
 * @brief It gets the lines given by the manager and call the function to
 * handle each protocols.
 */
int loop_in_protocols(void);

int is_victory_available(scoords_t *coords);
int is_on_board(scoords_t coord, scoords_t offset, const board_t *board, unsigned int player);

#endif /* !GOMOKU_H_ */
