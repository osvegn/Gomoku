/*
** EPITECH PROJECT, 2022
** gomoku
** File description:
** gomoku
*/

#ifndef GOMOKU_H_
#define GOMOKU_H_

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

#endif /* !GOMOKU_H_ */
