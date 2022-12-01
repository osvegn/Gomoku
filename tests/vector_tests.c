/*
** EPITECH PROJECT, 2022
** gomoku
** File description:
** vector_tests
*/

#include <criterion/criterion.h>
#include "vector.h"

Test(vector_creation, constructor)
{
    vector_t vector;

    vector_constructor(&vector, sizeof(int), 0);
    vector.destructor(&vector);
    cr_assert_eq(1, 1);
}

Test(vector_emplace, emplace)
{
    vector_t vector;
    int data = 10;

    vector_constructor(&vector, sizeof(int), 0);
    vector.emplace(&vector, &data, 0);
    vector.destructor(&vector);
    cr_assert_eq(1, 1);
}

Test(vector_emplace_back, emplace_back)
{
    vector_t vector;
    int data = 10;

    vector_constructor(&vector, sizeof(int), 0);
    vector.emplace_back(&vector, &data);
    vector.destructor(&vector);
    cr_assert_eq(1, 1);
}

Test(vector_size, size)
{
    vector_t vector;
    int data = 10;

    vector_constructor(&vector, sizeof(int), 0);
    vector.emplace_back(&vector, &data);
    cr_assert_eq(vector.get_size(&vector), 1);
    vector.destructor(&vector);
    cr_assert_eq(1, 1);
}

Test(vector_capacity, capacity)
{
    vector_t vector;

    vector_constructor(&vector, sizeof(int), 10);
    cr_assert_eq(vector.get_capacity(&vector), 10);
    vector.destructor(&vector);
    cr_assert_eq(1, 1);
}

Test(vector_at, vector_at)
{
    vector_t vector;

    vector_constructor(&vector, sizeof(int), 10);
    for (int i = 0; i < 10; i++) {
        vector.emplace_back(&vector, &i);
    }
    cr_assert_eq((int) *(int *)vector.at(&vector, 3), 3);
    vector.destructor(&vector);
    cr_assert_eq(1, 1);
}

Test(vector_front, vector_front)
{
    vector_t vector;

    vector_constructor(&vector, sizeof(int), 10);
    for (int i = 0; i < 10; i++) {
        vector.emplace_back(&vector, &i);
    }
    cr_assert_eq((int) *(int *)vector.front(&vector), 0);
    vector.destructor(&vector);
    cr_assert_eq(1, 1);
}

Test(vector_back, vector_back)
{
    vector_t vector;

    vector_constructor(&vector, sizeof(int), 10);
    for (int i = 0; i < 10; i++) {
        vector.emplace_back(&vector, &i);
    }
    cr_assert_eq((int) *(int *)vector.back(&vector), 9);
    vector.destructor(&vector);
    cr_assert_eq(1, 1);
}

Test(vector_erase, vector_erase)
{
    vector_t vector;

    vector_constructor(&vector, sizeof(int), 10);
    for (int i = 0; i < 10; i++) {
        vector.emplace_back(&vector, &i);
    }
    vector.erase(&vector, 5);
    cr_assert_eq((int) *(int *)vector.at(&vector, 5), 6);
    vector.destructor(&vector);
    cr_assert_eq(1, 1);
}