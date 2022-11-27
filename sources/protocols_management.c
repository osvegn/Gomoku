/*
** EPITECH PROJECT, 2022
** Gomoku
** File description:
** protocols_management
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "protocols.h"
#include "gomoku.h"

const prots_t LIST_PROTOCOLS[] = {
    {"START", &get_start_protocol}, // done
    {"TURN", &get_turn_protocol}, // done
    {"BEGIN", &handle_begin_protocol}, //done
    {"BOARD", &handle_board_protocol}, //done
    {"INFO", &handle_info_protocol}, // to do
    {"END", &handle_end_protocol}, // to do
    {"ABOUT", &answer_about_protocol} // to do
};

/**
 * @brief It search for the protocol to call in  the LIST_PROTOCOLS.
 *
 * @param message a pointer to a char. This is the address of the
 * buffer that holds the message given by the manager
 *
 * @return the return value of the function if it finds it (0 or 1),
 * 0 otherwise.
 */
static int search_protocol(const char *message)
{
    size_t size = 0;
    int rvalue = 0;
    bool found = false;

    while (message && message[size] != '\0' && message[size] != ' '
        && message[size] != '\n')
        size++;
    if (size == 0)
        return 0;
    for (int i = 0; size > 0 && i < NB_PROTOCOLS; i++) {
        if (strncmp(LIST_PROTOCOLS[i].key, message, size) == 0) {
            rvalue = LIST_PROTOCOLS[i].function(message);
            found = true;
            break;
        }
    }
    if (!found)
        print_unknown_message("Couldn't handle this protocol");
    return rvalue;
}

int loop_in_protocols(void)
{
    char *buffer = NULL;
    size_t size = 0;
    int rvalue = 0;
    int end = 0;

    do {
        rvalue = readfile(&buffer, &size, stdin);
        if (rvalue == -1)
            return -1;
        end = search_protocol(buffer);
    } while (!end && rvalue);
    free(buffer);
    return 0;
}