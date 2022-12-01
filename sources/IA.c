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

void get_ia2(scoords_t* s_coordinates)
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

#include "vector.h"
#include "patterns.h"

typedef struct pattern_info_s {
    unsigned int id;
    char *representation;
    unsigned int position;
    unsigned int direction;
} pattern_info_t;

void find_pattern_on_direction(unsigned int direction, unsigned int i, unsigned int j, vector_t *vector)
{
    const board_t *board = get_board();
    scoords_t offset = get_offset(direction);
    pattern_info_t info;

    for (unsigned int a = 1; a <= 2; a++) {
        for (unsigned int k = 0; PATTERNS[j].pattern[k]; k++) {
            unsigned int tmp = i + (offset.y * board->size + offset.x) * k;
            if (tmp < 0 || tmp >= board->size * board->size)
                break;
            if (PATTERNS[j].pattern[k] == '.' && board->board[tmp] != 0)
                break;
            if (PATTERNS[j].pattern[k] == 'X' && board->board[tmp] != a)
                break;
            if (!PATTERNS[j].pattern[k + 1]) {
                info.direction = direction;
                info.id = j;
                info.position = i;
                info.representation = PATTERNS[j].pattern;
                vector->emplace_back(vector, &info);
                return;
            }
        }
    }
}

void find_pattern(unsigned int i, vector_t *vector)
{
    for (unsigned int j = 0; PATTERNS[j].pattern; j++) {
        for (unsigned int direction = 1; direction < 5; direction++) {
            find_pattern_on_direction(direction, i, j, vector);
        }
    }
}

vector_t fill_vector(const board_t *board)
{
    vector_t vector;

    vector_constructor(&vector, sizeof(pattern_info_t), 100);
    for (unsigned int i = 0; i < board->size * board->size; i++) {
        find_pattern(i, &vector);
    }
    return vector;
}

int print_pattern(void *data)
{
    pattern_info_t *pattern = (pattern_info_t *)data;

    my_printf("[%i, %i, %i, \"%s\"]", pattern->id, pattern->direction, pattern->position, pattern->representation);
    return 0;
}

void sort_by_id(vector_t *vector)
{
    pattern_info_t *elem1 = NULL;
    pattern_info_t *elem2 = NULL;

    for (unsigned int i = 0; i < vector->get_size(vector) - 1; i++) {
        elem1 = (pattern_info_t *)vector->at(vector, i);
        elem2 = (pattern_info_t *)vector->at(vector, i + 1);
        if (elem1->id > elem2->id) {
            vector->swap(vector, i, i + 1);
            i = -1;
        }
    }
}

void get_ia(scoords_t *s_coordinates)
{
    const board_t *board = get_board();
    vector_t vector = fill_vector(board);
    pattern_info_t *info = NULL;
    scoords_t offset;

    if (vector.size) {
        sort_by_id(&vector);
        info = vector.at(&vector, 0);
        offset = get_offset(info->direction);
        s_coordinates->x = (info->position + (offset.y * board->size + offset.x) * PATTERNS[info->id].position) % board->size;
        s_coordinates->y = (info->position + (offset.y * board->size + offset.x) * PATTERNS[info->id].position) / board->size;
    } else {
        get_ia2(s_coordinates);
    }
    vector.destructor(&vector);
}
