/*
** EPITECH PROJECT, 2022
** gomoku
** File description:
** game_rules
*/

#include "game_rules.h"
#include <string.h>

static game_rules_t RULES[] =
{
    {
        .key = "timeout_turn",
        .value = 0
    },
    {
        .key = "timeout_match",
        .value = 0
    },
    {
        .key = "max_memory",
        .value = 0
    },
    {
        .key = "time_left",
        .value = 0
    },
    {
        .key = "game_type",
        .value = 0
    },
    {
        .key = "rule",
        .value = 0
    },
    {
        .key = "evaluate",
        .value = 0
    },
    {
        .key = "folder",
        .value = 0
    },
    {
        .key = 0,
        .value = 0
    }
};

game_rules_t *get_rules(void)
{
    return RULES;
}

game_rules_t *get_rule(const char *key)
{
    int i = 0;

    if (!key)
        return NULL;
    while (RULES[i].key) {
        if (!strcmp(RULES[i].key, key))
            return &RULES[i];
        i++;
    }
    return NULL;
}

int set_rule(const char *key, const size_t value)
{
    int i = 0;

    if (!key)
        return -1;
    while (RULES[i].key) {
        if (!strcmp(RULES[i].key, key)) {
            RULES[i].value = value;
            return 0;
        }
        i++;
    }
    return -1;
}
