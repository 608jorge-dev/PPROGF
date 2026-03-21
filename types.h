/**
 * @brief It defines common types for the whole project
 *
 * @file types.h
 * @author Profesores PPROG
 * @version 0
 * @date 27-01-2025
 * @copyright GNU Public License
 */

#ifndef TYPES_H
#define TYPES_H

#define WORD_SIZE 1000
#define NO_ID -1
#define NO_SPACE -2

/* Command fields macros */
#define CMD_LENGHT 30
#define MAX_ARGS 5
#define N_CMDT 2
#define N_CMD 11

/* Game fields macros */
#define MAX_SPACES 100
#define MAX_CHARACTERS 50
#define MAX_OBJECTS 4

/* Graphic engine fields macros */
#define WIDTH_MAP 65
#define WIDTH_DES 53
#define WIDTH_BAN 29
#define HEIGHT_MAP 26
#define HEIGHT_BAN 2
#define HEIGHT_HLP 3
#define HEIGHT_FDB 4

/* Space fields macros */
#define MAX_S 5
#define MAX_C 50

/* Set fields macros */
#define MAX_IDS 100

typedef long Id;

/**
 * @brief Bolean values enumeration.
 */
typedef enum
{
    FALSE,
    TRUE
} Bool;

/**
 * @brief Success and failure status enumeration.
 */
typedef enum
{
    ERROR,
    OK
} Status;

/**
 * @brief All 4 cardinal directions enumeration.
 */
typedef enum
{
    N,
    S,
    E,
    W
} Direction;

#endif