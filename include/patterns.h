/*
** EPITECH PROJECT, 2022
** gomoku
** File description:
** patterns
*/

#ifndef PATTERNS_H_
#define PATTERNS_H_

typedef struct pattern_s {
    /**
     * @brief The pattern representation.
    */
    char *pattern;

    /**
     * @brief The position to play.
    */
    unsigned int position;
} pattern_t;

const pattern_t PATTERNS[] =
{
    /// one turn before end
    {
        ".XXXX.",
        0
    },
    {
        ".XXXX",
        0
    },
    {
        "X.XXX",
        1
    },
    {
        "XX.XX",
        2
    },
    {
        "XXX.X",
        3
    },
    {
        "XXXX.",
        4
    },
    /// two turn before end
    {
        "..XXX..",
        1
    },
    {
        ".XXX..",
        4
    },
    {
        ".X.XX.",
        2
    },
    {
        ".XX.X.",
        3
    },
    {
        "..XXX.",
        1
    },
    /// may two turn before end
    {
        "XXX..",
        3
    },
    {
        "XX.X.",
        2
    },
    {
        "XX..X",
        2
    },
    {
        "X.XX.",
        1
    },
    {
        "X..XX",
        1
    },
    {
        ".XXX.",
        0
    },
    {
        ".XX.X",
        3
    },
    {
        ".X.XX",
        2
    },
    {
        "..XXX",
        1
    },
    {
        0,
        0
    }
};

#endif /* !PATTERNS_H_ */
