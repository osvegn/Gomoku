/*
** EPITECH PROJECT, 2022
** gomoku
** File description:
** load_board_from_file
*/

#include "gomoku.h"
#include "board.h"
#include "coordinates.h"

int load_board_from_file(const char *file)
{
    FILE *stream = fopen(file, "r+");
    char *buffer = NULL;
    size_t size = 0;
    unsigned int i = 0;
    coords_t coords = {0, 0};

    if (!file)
        return -1;
    readfile(&buffer, &size, stream);
    for (; buffer && buffer[i] != '\n'; i++);
    create_board(i);
    for (i = 0; buffer && buffer[i]; i++) {
        if (buffer[i] != '\n') {
            add_piece_to_board(coords.x, coords.y, buffer[i] - '0');
            coords.x++;
        } else {
            coords.x = 0;
            coords.y++;
        }
    }
}
