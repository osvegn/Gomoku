/*
** EPITECH PROJECT, 2022
** Gomoku
** File description:
** protocols_management
*/

#include <string.h>
#include "protocols.h"
#include "gomoku.h"

const prots_t LIST_PROTOCOLS[] = {
    {"START", &get_start_protocol}, // done
    {"TURN", &get_turn_protocol}, // done
    {"BEGIN", &handle_begin_protocol}, //done
    {"BOARD", &handle_begin_protocol}, //doing
    {"INFO", &handle_begin_protocol}, // to do
    {"END", &handle_begin_protocol}, // to do
    {"ABOUT", &handle_begin_protocol} // to do
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
static int search_protocol(char *message)
{
    size_t size = 0;

    for (size; message[size] != " " && message[size] != "\0"; size++);
    for (int i = 0; i < NB_PROTOCOLS; i++) {
        if (strncmp(LIST_PROTOCOLS[i].key, message, size) == 0) {
            return LIST_PROTOCOLS[i].function(message);
        }
    }
    return 0;
}

int loop_in_protocols()
{
    char *buffer = NULL;
    size_t size = 0;
    FILE *stream = 0;
    int rvalue = 0;
    bool end = 0;

    stream = fopen(stdin, "r+");
    if (!stream)
        return -1;
    rvalue = readfile(&buffer, &size, stream);
    if (rvalue == -1)
        return -1;
    while (!end)
        end = compare_first_word(buffer);
    return 0;
}