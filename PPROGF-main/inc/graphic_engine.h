/**
 * @brief It defines the textual graphic engine interface
 *
 * @file graphic_engine.h
 * @author Profesores PPROG
 * @version 0
 * @date 27-01-2025
 * @copyright GNU Public License
 */

#ifndef GRAPHIC_ENGINE_H
#define GRAPHIC_ENGINE_H

#include "game.h"
#include "command.h"
#include "libscreen.h"
#include "space.h"
#include "playerinf.h"
#include "types.h"

/**Graphic structure type definition
 */
typedef struct _Graphic_engine Graphic_engine;

/**
 * @brief It creates a graphic engine, allocating memory and initializing its members
 * @author Profesores PPROG
 *
 * @return
 */
Graphic_engine *graphic_engine_create();

/**
 * @brief It destroys the graphic engine, freeing the allocated memory
 * @author Profesores PPROG
 *
 * @param ge Pointer to graphic engine
 */
void graphic_engine_destroy(Graphic_engine *ge);

/**
 * @brief Changes the game GUI (paints in the differente graphic sections)
 * @author Profesores PPROG
 *
 * @param ge Pointer to graphic engine
 * @param game A pointer to the game data
 */
void graphic_engine_paint_game(Graphic_engine *ge, Game *game);

#endif