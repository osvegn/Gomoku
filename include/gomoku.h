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

/**
 * @brief It checks if there's a victory available for the player, and if there is, it
 * returns the direction of the victory
 * @param coords the coordinates of the last played piece
 * @return The function is_victory_available returns the direction of the enemy
 * if it is in a winning position.
 */
int is_victory_available(scoords_t *coords);

/**
 * @brief It checks if a given coordinate is on the board and if it is, it checks if the
 * player has a piece there
 * @param coord The coordinates of the piece we're checking.
 * @param offset the offset to check
 * @param board The board to check
 * @param player the player who is playing
 * @return The function is_on_board() is returning an integer.
 */
int is_on_board(scoords_t *coord, scoords_t offset, const board_t *board, unsigned int player);

scoords_t get_offset(int direction);
void get_dumb_ia(scoords_t *s_coordinates);
void get_ia(scoords_t* s_coordinates);

#endif /* !GOMOKU_H_ */
