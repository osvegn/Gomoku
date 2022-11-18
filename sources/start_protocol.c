/*
** EPITECH PROJECT, 2022
** gomoku
** File description:
** start_protocol
*/

#include <stddef.h>
#include <stdbool.h>
#include "gomoku.h"

static const char START_SUCCESS[] = "OK";
static const char START_FAILURE[] = "ERROR";

void answer_start_protocol(bool success, const char *message)
{
    char *code = NULL;

    if (success) {
        code = START_SUCCESS;
    } else {
        code = START_FAILURE;
    }
    my_printf("%s - %s\n", code, message);
}
