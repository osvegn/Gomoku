/*
** EPITECH PROJECT, 2022
** Gomoku
** File description:
** coordinates
*/

#ifndef COORDINATES_H_
    #define COORDINATES_H_

    #include <stdint.h>

/**
 * A structure to represent the coordinates on the board
 */
typedef struct coordinates {
    /*@{*/
    uint32_t x; /**< the x coordinate */
    uint32_t y; /**< the y coordinate */
    /*@}*/
} coords_t;

#endif /* !COORDINATES_H_ */
