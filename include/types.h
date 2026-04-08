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

#define WORD_SIZE 1000 /*!< Max amount of characters a word can have */
#define NO_ID -1       /*!< Id is non existent*/
#define NUL 0         /*!< Id is blank*/
#define NO_SPACE -2    /*!< space is non existent*/

/* Command fields macros */
#define CMD_LENGHT 30 /*!< Max amount of characters a command string input can have */
#define MAX_ARGS 5    /*!< Max amount of arguments a command can have */
#define N_CMDT 2      /*!< Max amount of characters an abreviation of a command can have */
#define N_CMD 30      /*!< Max amount of characters a command can have */

/* Game fields macros */
#define MAX_SPACES 100    /*!< Max amount of spaces possible in the game structure*/
#define MAX_CHARACTERS 50 /*!< Max amount of character possible in the game structure*/
#define MAX_OBJECTS 4     /*!< Max amount of objects possible in the game structure*/
#define MAX_LINKS 100     /*!< Max amount of links possible in the game structure*/
#define MAX_PLAYERS 4     /*!< Max amount of players possible in the game structure*/

/* Graphic engine fields macros */
#define WIDTH_MAP 65  /*!< Width of the map area in the textual graphic engine*/
#define WIDTH_DES 53  /*!< Width of the description area in the textual graphic engine*/
#define WIDTH_BAN 29  /*!< Width of the banner area in the textual graphic engine*/
#define HEIGHT_MAP 26 /*!< Height of the map area in the textual graphic engine*/
#define HEIGHT_BAN 2  /*!< Height of the description area in the textual graphic engine*/
#define HEIGHT_HLP 3  /*!< Height of the help area in the textual graphic engine*/
#define HEIGHT_FDB 4  /*!< Height of the feedback area in the textual graphic engine*/
#define HEIGHT_BLANK 9 /*!< Height of the blank spaces when and space doesnt exist*/

/* Inventory fields macros */
#define MAX_INV 10 /*!< Max amount of objects possible in the inventory structure*/

/* Space fields macros */
#define MAX_S 5  /*!< Max amount of description strings possible in the space structure*/
#define MAX_C 50 /*!< Max amount of characters possible of the description in tthe space structure*/

/* Set fields macros */
#define MAX_IDS 100 /*!< Max amount of ids possible in the set structure*/

typedef long Id; /*!<Id type definition*/

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