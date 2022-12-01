/*
** EPITECH PROJECT, 2022
** Gomoku
** File description:
** protocols
*/


#ifndef PROTOCOLS_H_
    #define PROTOCOLS_H_

    #define NB_PROTOCOLS 7

/**
 * A structure to represent the name of the protocols and its linked function
 */
typedef struct protocols {
    /*@{*/
    const char *key; /**< the key to find which function to call */
    int (*function)(const char *message); /**< function to call */
    /*@}*/
} prots_t;

/**
 * @brief It takes a string as parameter and parse it to add the opponent move
 * on the board and then prints the brain's next move on the standard output
 * and put it on the board.
 *
 * @param message The message to parse.
 *
 * @return 0 on success, -1 otherwise.
 */
int get_turn_protocol(const char *message);

/**
 * @brief It takes a string as parameter and parse it to get the size of the
 * board, if it can read it successfully it prints OK, otherwise it prints
 * ERROR followed by a message on the standard output.
 *
 * @param message The message to parse.
 *
 * @return 0 on success, -1 otherwise.
 */
int get_start_protocol(const char *message);

/**
 * @brief It takes a string as parameter and prints the move of the brain on
 * the standard output.
 *
 * @param message The message to parse.
 *
 * @return 0 on success, -1 otherwise.
 */
int handle_begin_protocol(const char *message);

/**
 * @brief It reads the next lines of the stdin until it finds 'DONE'.
 * Each line read it parses the coordinates and add to the board, then it
 * prints the next move of the brain's on the standard output.
 *
 * @param message The message to parse.
 *
 * @return 0 on success, -1 otherwise.
 */
int handle_board_protocol(const char *message);

/**
 * @brief It destroys the board and returns 1 to end the game.
 *
 * @param message The message to parse.
 *
 * @return 1
 */
int handle_end_protocol(const char *message);

/**
 * @brief It takes a string as parameter ...
 *
 * @param message The message to parse.
 *
 * @return 0 on success, -1 otherwise.
 */
int handle_info_protocol(const char *message);

/**
 * @brief It takes a string as parameter ...
 *
 * @param message The message to parse.
 *
 * @return 0 on success, -1 otherwise.
 */
int answer_about_protocol(const char *message);

/**
 * @brief It prints UNKOWN followed by the message on the standard output
 *
 * @param message The message to parse.
 */
void print_unknown_message(const char *message);

#endif /* !PROTOCOLS_H_ */

