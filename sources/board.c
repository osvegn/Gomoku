/*
** EPITECH PROJECT, 2022
** Gomoku
** File description:
** board
*/

#include <stdlib.h>
#include "board.h"

static board_t board = {NULL, 0, 0};

void destroy_board(void)
{
    if (board.board)
        free(board.board);
}

int create_board(unsigned int size)
{
    destroy_board();
    board.board = malloc(sizeof(int) * (size * size));
    if (!board.board)
        return -1;
    for (unsigned int i = 0; i < size * size; i++) {
        board.board[i] = 0;
    }
    board.size = size;
    board.turn = 0;
    return 0;
}

int add_piece_to_board(unsigned int x, unsigned int y, unsigned int player)
{
    if (!board.board || x >= board.size || y >= board.size || player == 0)
        return -1;
    if (board.board[y * board.size + x])
        return -1;
    board.board[y * board.size + x] = player;
    if (player == 1)
        board.turn++;
    else
        board.opposant_turn++;
    return 0;
}

int remove_piece_to_board(unsigned int x, unsigned int y)
{
    if (!board.board || x >= board.size || y >= board.size)
        return -1;
    board.board[y * board.size + x] = 0;
    return 0;
}

const board_t *get_board(void)
{
    return &board;
}
