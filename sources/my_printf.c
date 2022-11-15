/*
** EPITECH PROJECT, 2022
** gomoku
** File description:
** my_printf
*/

#include <stdio.h>
#include <stdarg.h>

void my_printf(const char *str, ...)
{
    printf(str);
    fflush(stdout);
}
