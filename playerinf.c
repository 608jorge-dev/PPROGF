/**
 * @brief It implements the player info module
 *
 * @file playerinf.c
 * @author Jorge Torrijos de la Cruz
 * @version 0
 * @date 03-02-2026
 * @copyright GNU Public License
 */

#include "playerinf.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Player
 *
 * This struct stores all the information of a player.
 */
struct _Playerinf
{
  Id id;                            /*!< Id number of the player*/
  char lastcommand[WORD_SIZE + 1];  /*!< Last command the player sent */
  Bool laststatus                   /*!< Status of last command */
  char lastchat[WORD_SIZE + 1];     /*!< Last chat from the player*/
  char lastinspect[WORD_SIZE + 1];  /*!< Last inspect from the player*/
};