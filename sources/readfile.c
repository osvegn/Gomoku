/*
** EPITECH PROJECT, 2022
** gomoku
** File description:
** readstdin
*/

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief It allocates new space to the buffer.
 *
 * @param buffer a pointer to a pointer to a char. This is the address of the
 * buffer that holds the string and need to get more space.
 * @param size The size of the buffer.
 *
 * @return 0 on success, -1 otherwise.
 */
static int allocate_memory(char **buffer, size_t *size)
{
    (*size) += 128;
    (*buffer) = realloc((*buffer), *size);
    if (!(*buffer))
        return -1;
    return 0;
}

int readfile(char **lineptr, size_t *n, FILE *stream)
{
    char *buffer = NULL;
    size_t size = 0;
    int c = 0;
    size_t i = 0;

    if (!lineptr || !stream || !n)
        return -1;
    c = fgetc(stream);
    while (c != EOF) {
        if (size == 0 || size - 1 <= i) {
            allocate_memory(&buffer, &size);
        }
        buffer[i] = c;
        i++;
        buffer[i] = '\0';
        c = fgetc(stream);
    }
    *n = size;
    *lineptr = buffer;
    return i;
}
