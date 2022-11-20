/*
** EPITECH PROJECT, 2022
** Gomoku [Codespaces]
** File description:
** board
*/

#ifndef BOARD_H_
#define BOARD_H_

typedef struct board_s {
    unsigned int **board;
    unsigned int size_x;
    unsigned int size_y;
} board_t;

#endif /* !BOARD_H_ */
