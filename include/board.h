/*
** EPITECH PROJECT, 2022
** Gomoku [Codespaces]
** File description:
** board
*/

#ifndef BOARD_H_
#define BOARD_H_

/**
 * @brief Structure to store board information, such as the board with piece
 * players have played, the x size and y size of the board.
 */
typedef struct board_s {
    /**
     * @brief The board with piece players have played.
     */
    unsigned int **board;
    /**
     * @brief The size of the board.
     */
    unsigned int size;
} board_t;

/**
 * @brief It frees the memory allocated for the board
 */
void destroy_board(void);

/**
 * @brief It creates a board of size x by y.
 *
 * @param size The size of the board.
 *
 * @return 0 on success, -1 otherwise.
 */
int create_board(unsigned int size);

/**
 * @brief Adds a piece to the board at the specified location for the
 * specified player.
 *
 * The first thing we do is check if the board exists, if the coordinates are
 * valid, and if the player is valid. If any of these are false, we return -1.
 *
 * @param x The x coordinate of the piece to add.
 * @param y The y coordinate of the piece to add.
 * @param player 1 or 2
 *
 * @return 0 on success, -1 otherwise.
 */
int add_piece_to_board(unsigned int x, unsigned int y, unsigned int player);

/**
 * @brief It removes a piece from the board
 *
 * @param x The x coordinate of the piece to remove.
 * @param y The y coordinate of the piece to remove.
 *
 * @return 0 on success, -1 otherwise.
 */
int remove_piece_to_board(unsigned int x, unsigned int y);

/**
 * @brief It returns the address of the board_t struct.
 *
 * @return A pointer to the board_t struct.
 */
const board_t *get_board(void);

#endif /* !BOARD_H_ */
