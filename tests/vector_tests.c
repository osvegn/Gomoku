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
    vector.clear(&vector);

    vector.destructor(&vector);
    cr_assert_eq(1, 1);
}
