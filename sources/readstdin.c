/*
** EPITECH PROJECT, 2022
** gomoku
** File description:
** readstdin
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void readstdin(char **content)
{
    char *line = NULL;
    char *tmp = NULL;
    size_t size = 0;
    size_t len = 0;

    while (1) {
        if (getline(&line, &size, stdin) <= 0)
            break;
        len += size;
        if ((*content)) {
            tmp = strdup((*content));
            free((*content));
            (*content) = malloc(sizeof(char) * len);
            strcpy((*content), tmp);
            free(tmp);
            strcat((*content), line);
        } else
            (*content) = strdup(line);
    }
    free(line);
}
