/*
** EPITECH PROJECT, 2022
** gomoku
** File description:
** about_protocol
*/

#include "gomoku.h"

int answer_about_protocol(const char *UNUSED(message))
{
    const char *name = "pbrain-gomoku-ai";
    const char *author = "osvegn and Nekomay";

    my_printf("name=\"%s\", version=\"1.0\", author=\"%s\", country=\"France\"\n", name, author);
    return 0;
}
