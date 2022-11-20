/*
** EPITECH PROJECT, 2022
** Gomoku
** File description:
** board
*/

#include <stdlib.h>
#include "board.h"

static board_t board = {NULL, 0};

void destroy_board(void)
{
    unsigned int i = 0;

    if (!board.board) {
        return;
    }
    while (i < board.size) {
        if (board.board[i]) {
            free(board.board[i]);
        }
        i++;
    }
    free(board.board);
}

int create_board(unsigned int size)
{
    unsigned int i = 0;

    destroy_board();
    board.board = malloc(sizeof(int *) * (size));
    if (!board.board)
        return -1;
    while (i < size) {
        board.board[i] = malloc(sizeof(int) * (size));
        if (!board.board[i])
            return -1;
        for (unsigned int j = 0; j < size; j++)
            board.board[i][j] = 0;
        i++;
    }
    board.size = size;
    return 0;
}

int add_piece_to_board(unsigned int x, unsigned int y, unsigned int player)
{
    if (!board.board || x >= board.size || y >= board.size || player == 0)
        return -1;
    board.board[y][x] = player;
    return 0;
}

int remove_piece_to_board(unsigned int x, unsigned int y)
{
    if (!board.board || x >= board.size || y >= board.size)
        return -1;
    board.board[y][x] = 0;
    return 0;
}

const board_t *get_board(void)
{
    return &board;
}
