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
    va_list list;

    va_start(list, str);
    vprintf(str, list);
    fflush(stdout);
    va_end(list);
}
