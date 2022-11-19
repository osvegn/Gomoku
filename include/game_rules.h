/*
** EPITECH PROJECT, 2022
** gomoku
** File description:
** game_rules
*/

#ifndef GAME_RULES_H_
#define GAME_RULES_H_

#include <stddef.h>

typedef struct game_rules_s {
    const char *key;
    size_t value;
} game_rules_t;

game_rules_t *get_rules(void);
game_rules_t *get_rule(const char *key);
int set_rule(const char *key, const size_t value);

#endif /* !GAME_RULES_H_ */
