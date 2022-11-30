/*
** EPITECH PROJECT, 2022
** our_rpg
** File description:
** vector
*/

#include "vector.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

static void *at(vector_t *this, unsigned int index)
{
    if (index >= this->size)
        return NULL;
    return (char *)this->pointer + index * this->element_size;
}

static void *front(vector_t *this)
{
    if (this->size)
        return NULL;
    return this->pointer;
}

static void *back(vector_t *this)
{
    if (this->size)
        return NULL;
    return (char *)this->pointer + (this->size - 1) * this->element_size;
}

static bool empty(vector_t *this)
{
    return this->size ? false : true;
}

static unsigned int size(vector_t *this)
{
    return this->size;
}

static unsigned int capacity(vector_t *this)
{
    return this->total_size;
}

static int swap(vector_t *this, unsigned int i_first_element, unsigned int i_second_element)
{
    void *tmp = malloc(this->element_size);
    void *first_element = (char *)this->pointer + i_first_element * this->element_size;
    void *second_element = (char *)this->pointer + i_second_element * this->element_size;

    if (!tmp)
        return -1;
    memcpy(tmp, first_element, this->element_size);
    memcpy(first_element, second_element, this->element_size);
    memcpy(second_element, tmp, this->element_size);
    free(tmp);
    return 0;
}

/// @brief It clears the vector, by setting the size to 0.
/// @param this The vector to be clear.
/// @return 0.
static int clear(vector_t *this)
{
    this->size = 0;
    this->available_size = this->total_size;
    return 0;
}

/// @brief It erases an element of a vector at a given index.
/// It also moves all following elements in the vector.
/// @param this The vector on which the element will be removed.
/// @param index The element position on the vector to be removed.
/// @return 0, or -1 if an error occurs.
static int erase(vector_t *this, unsigned int index)
{
    if (index > this->size)
        return -1;
    memcpy((char *)this->pointer + index * this->element_size, (char *)this->pointer + (index + 1) * this->element_size, (this->size - (index + 1)) * this->element_size);
    this->size--;
    this->available_size++;
    return 0;
}

/// @brief It removes the last element of a vector.
/// @param this The vector on which the element will be removed.
/// @return 0.
static int pop_back(vector_t *this)
{
    this->size--;
    this->available_size++;
    return 0;
}

/// @brief The print_at function prints an element at the given index
/// using print_fct function pointer.
/// The format dependant on how print_fct function pointer print the data.
/// @param this The vector on which print an element.
/// @param index The position of the element to print.
/// @param print_fct The function pointer used to know how to print an
/// element.
/// @return It returns the value of print_fct, or -1 if an error occurs.
static int print_at(vector_t *this, unsigned int index, int (*print_fct)(void *data))
{
    if (index > this->size)
        return -1;
    return print_fct((char *)this->pointer + index * this->element_size);
}

/// @brief The print function prints all elements of the vector.
/// The format dependant on how print_fct function pointer print the data.
/// @param this The vector on which print all elements.
/// @param print_fct The function pointer used to know how to print an
/// element.
/// @return 0, or -1 if print_fct return -1.
static int print(vector_t *this, int (*print_fct)(void *data))
{
    printf("[");
    fflush(stdout);
    for (unsigned int i = 0; i < this->size; i++) {
        if (print_fct((char *)this->pointer + i * this->element_size) < 0)
            return -1;
        if (i + 1 < this->size) {
            printf(", ");
            fflush(stdout);
        }
    }
    printf("]\n");
    fflush(stdout);
    return 0;
}

/// @brief The emplace function adds an element at the given index.
/// It increases the capacity of the vector if needed.
/// @param this The vector on which adds an element.
/// @param data The data to be added.
/// @param index The index where the data must be added.
/// @return 0, or -1 if an error occurs.
static int emplace(vector_t *this, void *data, unsigned int index)
{
    void *ptr = NULL;

    if (index > this->total_size)
        return -1;
    if (!this->available_size) {
        this->pointer = realloc(this->pointer, (this->total_size + 1) * this->element_size);
        if (!this->pointer)
            return -1;
        this->total_size++;
        this->available_size++;
    }
    ptr = (char *)this->pointer + index * this->element_size;
    for (unsigned int i = this->size; i > index; i--) {
        memcpy((char *)this->pointer + i * this->element_size, (char *)this->pointer + (i - 1) * this->element_size, this->element_size);
    }
    memcpy(ptr, data, this->element_size);
    this->available_size--;
    this->size++;
    return 0;
}

/// @brief The emplace_back function adds an element at the end.
/// It increases the capacity of the vector if needed.
/// @param this The vector on which adds an element.
/// @param data The data to be added.
/// @return 0, or -1 if an error occurs.
static int emplace_back(vector_t *this, void *data)
{
    if (!this->available_size) {
        this->pointer = realloc(this->pointer, (this->total_size + 1) * this->element_size);
        if (!this->pointer)
            return -1;
        this->total_size++;
        this->available_size++;
    }
    memcpy((char *)this->pointer + this->size * this->element_size), data, this->element_size;
    this->available_size--;
    this->size++;
    return 0;
}

/// @brief This is the destructor of a vector. It free the pointer.
/// @param this The vector to be free.
static void destructor(vector_t *this)
{
    if (this->pointer)
        free(this->pointer);
}

int vector_constructor(vector_t *this, unsigned int element_size, unsigned int element_number)
{
    this->element_size = element_size;
    this->pointer = malloc(this->element_size * element_number);
    if (!this->pointer)
        return - 1;
    this->available_size = element_number;
    this->size = 0;
    this->total_size = element_number;
    this->destructor = &destructor;
    this->emplace = &emplace;
    this->emplace_back = &emplace_back;
    this->print_at = &print_at;
    this->print = &print;
    this->clear = &clear;
    this->erase = &erase;
    this->pop_back = &pop_back;
    this->at = &at;
    this->front = &front;
    this->back = &back;
    this->empty = &empty;
    this->get_size = &size;
    this->get_capacity = &capacity;
    this->swap = &swap;
    return 0;
}
