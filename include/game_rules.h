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

/**
 * @brief It returns a pointer to the game rules.
 *
 * @return The address of the RULES variable.
 */
game_rules_t *get_rules(void);

/**
 * @brief It returns a pointer to a game_rules_t struct if the key is found,
 * otherwise it returns NULL.
 *
 * @param key The key of the rule.
 *
 * @return A pointer to the game_rules_t struct, or NULL on failure.
 */
game_rules_t *get_rule(const char *key);

/**
 * @brief It sets the value of a rule.
 *
 * @param key The name of the rule.
 * @param value the value of the parameter
 *
 * @return 0 on success, -1 otherwise.
 */
int set_rule(const char *key, const size_t value);

#endif /* !GAME_RULES_H_ */
