/**
 * @brief It defines the game management interface
 *
 * @file game_management.h
 * @author Guillermo Núñez Bravo, Iván Rodríguez Camacho, Jorge Torrijos de la Cruz
 * @version 7.0
 * @date 28-04-2026
 * @copyright GNU Public License
 */

#ifndef GAME_MANAGEMENT_H
#define GAME_MANAGEMENT_H

#include "command.h"
#include "game.h"
#include "space.h"
#include "types.h"

/**
 * @brief Saves in a file the game progress data
 * @author Iván Rodríguez Camacho
 *
 * @param game A pointer to the game data
 * @param filename A pointer to the name of the data file
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status game_management_save(Game *game, char *filename);

/**
 * @brief Loads the whole game read on file
 * @author Iván Rodríguez Camacho
 *
 * @param game A pointer to the game data
 * @param filename A pointer to the name of the data file
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status game_management_load(Game *game, char *filename);

/**
 * @brief Loads the spaces read on file
 * @author Jorge Torrijos de la Cruz
 *
 * @param game A pointer to the game data
 * @param filename A pointer to the name of the data file
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status game_management_load_spaces(Game *game, char *filename);

/**
 * @brief Loads the objects read on file
 * @author Jorge Torrijos de la Cruz
 *
 * @param game A pointer to the game data
 * @param filename A pointer to the name of the data file
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status game_management_load_objects(Game *game, char *filename);

/**
 * @brief Loads the characters read on file
 * @author Jorge Torrijos de la Cruz
 *
 * @param game A pointer to the game data
 * @param filename A pointer to the name of the data file
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status game_management_load_characters(Game *game, char *filename);

/**
 * @brief Loads the players read on file
 * @author Guillermo Núñez Bravo
 *
 * @param game A pointer to the game data
 * @param filename A pointer to the name of the data file
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status game_management_load_player(Game *game, char *filename);

/**
 * @brief Loads the links read on file
 * @author Guillermo Núñez Bravo
 *
 * @param game A pointer to the game data
 * @param filename A pointer to the name of the data file
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status game_management_load_link(Game *game, char *filename);

#endif
