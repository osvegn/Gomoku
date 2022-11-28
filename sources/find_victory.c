/*
** EPITECH PROJECT, 2022
** gomoku
** File description:
** find_victory
*/

#include "board.h"
#include "coordinates.h"

scoords_t get_offset(int direction)
{
    switch (direction) {
        case 1:
            return (scoords_t){1, -1};
        case 2:
            return (scoords_t){1, 0};
        case 3:
            return (scoords_t){1, 1};
        case 4:
            return (scoords_t){0, 1};
        default:
            return (scoords_t){0, 0};
    }
    return (scoords_t){0, 0};
}

int is_on_board(scoords_t coord, scoords_t offset, const board_t *board, unsigned int player)
{
    scoords_t value = {coord.x + offset.x, coord.y + offset.y};
    int size = (int)board->size;

    if (value.x > 0 && value.x < size && value.y > 0 && value.y < size) {
        if (board->board[value.y * size + value.x] == player) {
            return 1;
        }
    }
    return 0;
}

static int find_directions(const board_t *board, scoords_t i, int direction,
unsigned int player)
{
    scoords_t offset = get_offset(direction);
    unsigned int len = 1;
    scoords_t tmp = i;

    while (is_on_board(i, offset, board, player)) {
        i = (scoords_t){i.x + offset.x, i.y + offset.y};
        len++;
        if (len == 4) {
            if (is_on_board(i, offset, board, 0)) {
                return direction;
            }
            if (is_on_board(i, (scoords_t){-(offset.x * 4), -(offset.y * 4)},
                board, 0)) {
                return direction;
            }
        }
    }
    if (direction < 4)
        return find_directions(board, tmp, direction + 1, player);
    return 0;
}

int is_victory_available(scoords_t *coords)
{
    const board_t *board = get_board();
    int rvalue = 0;
    int size = (int)board->size;
    scoords_t position = {0, 0};
    int enemy_direction = 0;

    while (coords->y * board->size + coords->x < board->size * board->size) {
        if (board->board[coords->y * size + coords->x]) {
            rvalue = find_directions(board, *coords, 1,
            board->board[coords->y * size + coords->x]);
        }
        if (rvalue && board->board[coords->y * size + coords->x] == 1)
            return rvalue;
        else if (rvalue && board->board[coords->y * size + coords->x] == 2) {
            position = (scoords_t){coords->x, coords->y};
            enemy_direction = rvalue;
        }
        coords->x++;
        if (coords->x >= size && coords->y + 1 < size) {
            coords->x = 0;
            coords->y++;
        }
    }
    (*coords) = position;
    return enemy_direction;
}
