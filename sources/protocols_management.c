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

static void pass_lines(char *message, size_t *offset)
{
    if (strncmp("BOARD", &(message[*offset]), 5) == 0) {
        while (message[*offset] && strncmp(&(message[*offset]), "DONE", 4))
            (*offset)++;
        if (message[*offset])
            *offset += 4;
    }
    else
        while (message[*offset] &&
            (message[*offset] != '\n' && message[*offset] != '\r'))
            (*offset)++;
    if (message[*offset] == '\n' || message[*offset] == '\r')
        (*offset)++;
}

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
    static size_t offset = 0;
    size_t size = 0;
    int rvalue = 0;

    for (size; message[offset + size] != '\0' && message[offset + size]
        != ' ' && message[offset + size] != '\n'; size++);
    if (size == 0)
        return 2;
    for (int i = 0; i < NB_PROTOCOLS; i++) {
        if (strncmp(LIST_PROTOCOLS[i].key, &(message[offset]), size) == 0) {
            rvalue = LIST_PROTOCOLS[i].function(&(message[offset]));
            break;
        }
    }
    pass_lines(message, &offset);
    return rvalue;
}

int loop_in_protocols(void)
{
    char buffer[128];
    size_t size = 0;
    int rvalue = 0;
    int end = 0;

    if (rvalue == -1)
        return -1;
    while (!end) {
        gets(buffer);
        my_printf("%s\n", buffer);
        // rvalue = readfile(&buffer, &size, stdin);
        end = search_protocol(buffer);
        // free(buffer);
    }
    return 0;
}