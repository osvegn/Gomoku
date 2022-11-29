/*
** EPITECH PROJECT, 2022
** gomoku
** File description:
** IA
*/

#include "coordinates.h"
#include "board.h"
#include "gomoku.h"
#include <time.h>
#include <stdlib.h>

void get_dumb_ia(scoords_t *s_coordinates)
{
    const board_t *board = get_board();
    int i = 0;
    int count = 0;
    scoords_t offset = {0, 0};

    if (board->turn) {
        srand(time(NULL));
        i = (rand() % board->turn) + 1;
        for (unsigned int j = 0; j < board->size * board->size; j++) {
            if (board->board[j] == 1)
                count++;
            if (count >= i) {
                i = j;
                break;
            }
        }
        count = 0;
        s_coordinates->x = i % board->size;
        s_coordinates->y = i / board->size;
        do {
            srand(time(NULL) + count);
            offset.x = (rand() % 5) - 2;
            offset.y = (rand() % 5) - 2;
            if (count > 10000) {
                count = 0;
                break;
            }
            count++;
        } while (!is_on_board(s_coordinates, offset, board, 0));
        if (is_on_board(s_coordinates, offset, board, 0)) {
            s_coordinates->x += offset.x;
            s_coordinates->y += offset.y;
            return;
        }
    }
    do  {
        i = rand() % (board->size * board->size - 1);
    } while ((board->board[i] != 0));
    s_coordinates->x = i % board->size;
    s_coordinates->y = i / board->size;
}

void get_ia(scoords_t* s_coordinates)
{
    const board_t* board = get_board();
    int rvalue = 0;
    scoords_t offset = { 0, 0 };

    rvalue = is_victory_available(s_coordinates);
    if (rvalue == 0) {
        get_dumb_ia(s_coordinates);
        return;
    }
    offset = get_offset(rvalue);
    if (is_on_board(s_coordinates, (scoords_t){offset.x * 4, offset.y * 4}, board, 0)) {
        s_coordinates->x += (4 * offset.x);
        s_coordinates->y += (4 * offset.y);
    } else {
        s_coordinates->x -= offset.x;
        s_coordinates->y -= offset.y;
    }
    if (s_coordinates->x <= 0 || s_coordinates->y <= 0)
        get_dumb_ia(s_coordinates);
}