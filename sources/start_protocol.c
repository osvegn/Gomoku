/*
** EPITECH PROJECT, 2022
** gomoku
** File description:
** start_protocol
*/

#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include "gomoku.h"

static const char START_SUCCESS[] = "OK";
static const char START_FAILURE[] = "ERROR";

void answer_start_protocol(bool success, const char *message)
{
    const char *code = NULL;

    if (success) {
        code = START_SUCCESS;
    } else {
        code = START_FAILURE;
    }
    if (message) {
        my_printf("%s - %s\n", code, message);
    } else {
        my_printf("%s\n", code);
    }
}

int get_start_protocol(const char *message, unsigned int *size)
{
    int value = 0;

    if (!message || !size || strncmp(message, "START ", 6))
        return -1;
    value = atoi(message + 6);
    if (value <= 0)
        return -1;
    (*size) = value;
    return 0;
}
