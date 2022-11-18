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
 * @brief It prints a message to the standard output.
 *
 * @param success a boolean that indicates whether the protocol was
 * successfully started or not.
 * @param message The message to send to the client.
 */
void answer_start_protocol(bool success, const char *message);

#endif /* !GOMOKU_H_ */
