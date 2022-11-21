/*
** EPITECH PROJECT, 2022
** gomoku
** File description:
** main
*/

#include "board.h"

int is_victory_available(void);

int main(void)
{
    const board_t *board = get_board();

    create_board(10);
    add_piece_to_board(0, 0, 1);
    add_piece_to_board(1, 0, 1);
    add_piece_to_board(2, 0, 1);
    add_piece_to_board(3, 0, 1);
    print_board();
    my_printf("%i\n", is_victory_available());
    return 0;
}
