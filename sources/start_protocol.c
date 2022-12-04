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
#include "board.h"

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

int get_start_protocol(const char *message)
{
    const unsigned int protocol_len = 6;
    int value = 0;

    if (!message)
        return -1;
    value = atoi(message + protocol_len);
    if (value <= 0) {
        answer_start_protocol(false, "invalid size given");
        return 0;
    }
    if (create_board(value) == -1) {
        answer_start_protocol(false, "creation of the board failed");
        return 0;
    }
    answer_start_protocol(true, NULL);
    return 0;
}
