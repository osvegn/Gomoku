/*
** EPITECH PROJECT, 2022
** gomoku
** File description:
** find_victory
*/

#include "board.h"

int get_offset(int direction, unsigned int size)
{
    switch (direction) {
        case 1:
            return -(size - 1);
        case 2:
            return 1;
        case 3:
            return size + 1;
        case 4:
            return size;
        default:
            return -1;
    }
    return -1;
}

int find_directions(const board_t *board, unsigned int i, int direction, int player)
{
    int offset = get_offset(direction, board->size);
    unsigned int len = 1;
    unsigned int tmp = i;

    while (i + offset > 0 && i + offset < board->size * board->size && board->board[i + offset] == player) {
        i += offset;
        len++;
        if (len == 4 &&
        (i + offset > 0 && i + offset < board->size * board->size && board->board[i + offset] == 0) ||
        (i - (offset * 4) > 0 && i - (offset * 4) < board->size * board->size && board->board[i - (offset * 4)] == 0))
            return direction;
    }
    if (direction < 4)
        return find_directions(board, tmp, direction + 1, player);
    return 0;
}

int is_victory_available(void)
{
    const board_t *board = get_board();
    unsigned int i = 0;
    int rvalue = 0;

    while (i < board->size) {
        if (board->board[i]) {
            rvalue = find_directions(board, i, 1, board->board[i]);
            my_printf("Find piece\n");
        }
        if (rvalue)
            return rvalue;
        i++;
    }
    return 0;
}
