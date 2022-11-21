/*
** EPITECH PROJECT, 2022
** gomoku
** File description:
** find_victory
*/

#include "board.h"

void find_piece(unsigned int *i, unsigned int *j, const board_t *board)
{
    for (; (*i) < board->size && board->board[(*i)][(*j)]; (*i)++) {
        for (; (*j) < board->size && board->board[(*i)][(*j)]; (*j)++);
    }
}

int is_victory_available(void)
{
    const board_t *board = get_board();
    unsigned int i = 0;
    unsigned int j = 0;

    while (i < board->size) {
        while (j < board->size) {
            find_piece(&i, &j, board);
        }
    }
    return 0;
}
