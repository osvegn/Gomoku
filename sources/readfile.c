/*
** EPITECH PROJECT, 2022
** gomoku
** File description:
** readstdin
*/

#include <stdlib.h>
#include <stdio.h>

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
    for (size_t i = 0; i < *size; i++)
        (*buffer)[i] = 0;
    return 0;
}

int readfile(char **buffer, size_t *size, FILE *stream)
{
    int c = 0;
    size_t i = 0;

    if (!buffer || !stream || !size)
        return -1;
    for (size_t j = 0; *buffer && j < *size; j++)
        (*buffer)[j] = 0;
    c = fgetc(stream);
    while (c != EOF && c != '\n') {
        if ((*size == 0 || *size - 1 <= i) &&
            allocate_memory(buffer, size) < 0) {
            return -1;
        }
        (*buffer)[i] = c;
        i++;
        c = fgetc(stream);
    }
    return i;
}
