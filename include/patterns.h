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
     * @brief Threat score from 0 to 4.
    */
    unsigned int threat_score;

    /**
     * @brief The position to play.
    */
    unsigned int position;
} pattern_t;

typedef struct pattern_info_s {
    unsigned int id;
    char *representation;
    unsigned int position;
    unsigned int direction;
    unsigned int player;
} pattern_info_t;

const pattern_t PATTERNS[] =
{
    /// one turn before end
    {
        ".XXXX.",
        4,
        0
    },
    {
        ".XXXX",
        4,
        0
    },
    {
        "X.XXX",
        4,
        1
    },
    {
        "XX.XX",
        4,
        2
    },
    {
        "XXX.X",
        4,
        3
    },
    {
        "XXXX.",
        4,
        4
    },
    /// two turn before end
    {
        "..XXX..",
        3,
        1
    },
    {
        ".XXX..",
        3,
        4
    },
    {
        ".X.XX.",
        3,
        2
    },
    {
        ".XX.X.",
        3,
        3
    },
    {
        "..XXX.",
        3,
        1
    },
    {
        "XX.X..XX",
        3,
        4
    },
    {
        "XX..X.XX",
        3,
        3
    },
    {
        "XXX...XXX",
        3,
        4
    },
    /// may two turn before end
    {
        "XXX..",
        3,
        3
    },
    {
        "XX.X.",
        3,
        2
    },
    {
        "XX..X",
        3,
        2
    },
    {
        "X.XX.",
        3,
        1
    },
    {
        "X..XX",
        3,
        1
    },
    {
        ".XXX.",
        3,
        0
    },
    {
        ".XX.X",
        3,
        3
    },
    {
        ".X.XX",
        3,
        2
    },
    {
        "..XXX",
        3,
        1
    },
    /// more turns before winning
    {
        "..XX...",
        2,
        4
    },
    {
        "..X.X..",
        2,
        3
    },
    {
        "...XX..",
        2,
        2
    },
    {
        ".X.X..X.",
        2,
        4
    },
    {
        ".X..X.X.",
        2,
        3
    },
    {
        "X.X...X.X",
        2,
        4
    },
    {
        "X...X.X.X",
        2,
        2
    },
    {
        "X.X.X...X",
        2,
        6
    },
    {
        ".X..X.",
        2,
        2
    },
    {
        "..X.X.",
        2,
        1
    },
    {
        ".X.X..",
        2,
        4
    },
    {
        ".XX...",
        2,
        3
    },
    {
        "..XX..",
        2,
        1
    },
    {
        "...XX.",
        2,
        2
    },
    {
        "XX...",
        2,
        2
    },
    {
        "...XX",
        2,
        2
    },
    {
        0,
        0,
        0
    }
};

#endif /* !PATTERNS_H_ */
