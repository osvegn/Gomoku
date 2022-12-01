/*
** EPITECH PROJECT, 2022
** Gomoku
** File description:
** unknown_message
*/

#include "gomoku.h"

void print_unknown_message(const char *message)
{
    if (!message)
        my_printf("UNKNOWN\n");
    else
        my_printf("UNKNOWN - %s\n", message);
}