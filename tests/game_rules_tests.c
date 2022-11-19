/*
** EPITECH PROJECT, 2022
** gomoku
** File description:
** game_rules_tests
*/

#include <criterion/criterion.h>
#include "game_rules.h"

Test(get_rules, unique_test_get_rules)
{
    game_rules_t *rules = get_rules();

    cr_assert_neq(rules, 0);
    cr_assert_str_eq(rules[0].key, "timeout_turn");
    cr_assert_eq(rules[0].value, 0);
    cr_assert_str_eq(rules[7].key, "folder");
    cr_assert_eq(rules[7].value, 0);
    rules[0].value = 10;
    rules = get_rules();
    cr_assert_eq(rules[0].value, 10);
}

Test(get_rule, get_evaluate_key_get_rule)
{
    game_rules_t *rule = get_rule("evaluate");

    cr_assert_neq(rule, 0);
    cr_assert_eq(rule->value, 0);
    cr_assert_str_eq(rule->key, "evaluate");
    rule->value = 185;
    rule = get_rule("evaluate");
    cr_assert_neq(rule, 0);
    cr_assert_eq(rule->value, 185);
}

Test(get_rule, get_null_key_get_rule)
{
    game_rules_t *rule = get_rule(NULL);

    cr_assert_eq(rule, 0);
}

Test(get_rule, get_invalide_key_get_rule)
{
    game_rules_t *rule = get_rule("salut");

    cr_assert_eq(rule, 0);
}

Test(set_rule, set_rule_key_set_rule)
{
    int rvalue = set_rule("rule", 486);

    cr_assert_eq(rvalue, 0);
    cr_assert_eq(get_rule("rule")->value, 486);
}

Test(set_rule, set_null_key_set_rule)
{
    int rvalue = set_rule(NULL, 456);

    cr_assert_eq(rvalue, -1);
}

Test(set_rule, set_invalide_key_set_rule)
{
    int rvalue = set_rule("zebi", 1865);

    cr_assert_eq(rvalue, -1);
}
