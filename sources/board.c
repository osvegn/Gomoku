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
    unsigned int i = 0;

    if (!board.board) {
        return;
    }
    while (i < board.size_y) {
        if (board.board[i]) {
            free(board.board[i]);
        }
        i++;
    }
    free(board.board);
}

int create_board(unsigned int x, unsigned int y)
{
    unsigned int i = 0;

    destroy_board();
    board.board = malloc(sizeof(int *) * (y));
    if (!board.board)
        return -1;
    while (i < y) {
        board.board[i] = malloc(sizeof(int) * (x));
        if (!board.board[i]);
            return -1;
        i++;
    }
    board.size_x = x;
    board.size_y = y;
    return 0;
}

int add_piece_to_board(unsigned int x, unsigned int y, unsigned int player)
{
    if (!board.board || x >= board.size_x || y >= board.size_y || player == 0)
        return -1;
    board.board[y][x] = player;
    return 0;
}

int remove_piece_to_board(unsigned int x, unsigned int y)
{
    if (!board.board || x >= board.size_x || y >= board.size_y)
        return -1;
    board.board[y][x] = 0;
    return 0;
}

const board_t *get_board(void)
{
    return &board;
}
