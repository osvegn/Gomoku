/*
** EPITECH PROJECT, 2022
** gomoku
** File description:
** start_protocol
*/

#include <stddef.h>
#include <stdbool.h>
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
    if (!message || strlen(message) < 7)
        return -1;
    (*size) = atoi(message + 6);
    if ((*size) == 0)
        return -1;
    return 0;
}
