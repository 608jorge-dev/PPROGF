/**
 * @brief It defines the game reader interface
 *
 * @file game_reader.h
 * @author Álvaro Bravo González
 * @version 0
 * @date 03-02-26
 * @copyright GNU Public License
 */

#ifndef GAME_READER_H
#define GAME_READER_H

#include "command.h"
#include "game.h"
#include "space.h"
#include "types.h"

/**
 * @brief Loads spaces read on file
 * @author Profesores PPROG
 *
 * @param game A pointer to the game data
 * @param filename A pointer to the name of the data file
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status game_reader_load_spaces(Game *game, char *filename);

/**
 * @brief Loads the objects read on file
 * @author Jorge Torrijos de la Cruz
 *
 * @param game A pointer to the game data
 * @param filename A pointer to the name of the data file
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status game_reader_load_objects(Game *game, char *filename);


/**
 * @brief Loads the player read on file
 * @author Jorge Torrijos de la Cruz
 *
 * @param game A pointer to the game data
 * @param filename A pointer to the name of the data file
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status game_reader_load_characters(Game *game, char *filename);

/**
 * @brief Loads the player read on file
 * @author Guillermo Nuñez Bravo
 *
 * @param game A pointer to the game data
 * @param filename A pointer to the name of the data file
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status game_reader_load_player(Game *game, char *filename);

/**
 * @brief Loads the link read on file
 * @author Guillermo Nuñez Bravo
 *
 * @param game A pointer to the game data
 * @param filename A pointer to the name of the data file
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status game_reader_load_link(Game *game, char *filename);


/**
 * @brief Initializes the game structure members starting from the file
 * @author Profesores PPROG
 *
 * @param game A pointer to the game data
 * @param filename A  pointer to the name of the data file
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status game_reader_create_from_file(Game *game, char *filename);

#endif
