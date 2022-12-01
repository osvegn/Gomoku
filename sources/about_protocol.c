/*
** EPITECH PROJECT, 2022
** gomoku
** File description:
** about_protocol
*/

#include "gomoku.h"

int answer_about_protocol(const char *UNUSED(message))
{
    const char *name = "NOUS";
    const char *author = "NOUS";

    my_printf("name=\"%s\", version=\"1.0\", author=\"%s\", country=\"USA\"\n", name, author);
    return 0;
}
