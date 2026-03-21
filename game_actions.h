/**
 * @brief It defines the game update interface
 *
 * @file game.h
 * @author Profesores PPROG
 * @version 0
 * @date 27-01-2025
 * @copyright GNU Public License
 */

#ifndef GAME_ACTIONS_H
#define GAME_ACTIONS_H

#include "command.h"
#include "game.h"
#include "types.h"

/**
 * @brief Transfers the actual command state to the game functions.
 * @author Profesores PPROG
 *
 * @param game A pointer to the game data
 * @param cmd A pointer to the command input string
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status game_actions_update(Game *game, Command *cmd);

#endif