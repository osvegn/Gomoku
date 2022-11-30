/*
** EPITECH PROJECT, 2022
** gomoku
** File description:
** vector_tests
*/

#include <criterion/criterion.h>
#include "vector.h"

Test(vector, global_test)
{
    vector_t vector;
    int data = 10;

    vector_constructor(&vector, sizeof(int), 0);
    vector.emplace_back(&vector, &data);
    data += 5;
    vector.emplace(&vector, &data, 0);
    cr_assert_eq((int) *(int *)vector.at(&vector, 1), 10);
    cr_assert_eq((int) *(int *)vector.front(&vector), 5);
    cr_assert_eq((int) *(int *)vector.back(&vector), 10);
    // cr_assert_eq(vector.empty(&vector), false);
    cr_assert_eq(vector.get_size(&vector), 2);
    cr_assert_eq(vector.get_capacity(&vector), 2);
    vector.clear(&vector);
    // cr_assert_eq(vector.empty(&vector), true);
    cr_assert_eq(vector.get_size(&vector), 0);
    cr_assert_eq(vector.get_capacity(&vector), 2);

    vector.destructor(&vector);
    cr_assert_eq(1, 1);
}
