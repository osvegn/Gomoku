/*
** EPITECH PROJECT, 2022
** Gomoku
** File description:
** protocols
*/


#ifndef PROTOCOLS_H_
    #define PROTOCOLS_H_

    #define NB_PROTOCOLS 7

/**
 * A structure to represent the name of the protocols and its linked function
 */
typedef struct protocols {
    /*@{*/
    const char *key; /**< the key to find which function to call */
    int (*function)(const char *message); /**< function to call */
    /*@}*/
} prots_t;

#endif /* !PROTOCOLS_H_ */

