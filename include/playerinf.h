/**
 * @brief It defines the player module interface
 *
 * @file player.h
 * @author Jorge Torrijos de la Cruz
 * @version 0
 * @date 03-02-2025
 * @copyright GNU Public License
 */

#ifndef PLAYERINF_H
#define PLAYERINF_H

#include "types.h"
#include "set.h"
#include "command.h"
#include "inventory.h"

/** Playerinf structure type definition
 */
typedef struct _Playerinf Playerinf;

/**
 * @brief It creates a new playerinf, allocating memory and initializing its members
 * @author Jorge Torrijos de la Cruz
 *
 * @param id The identification number for the new playerinf
 * @return A new playerinf, initialized
 */
Playerinf *playerinf_create(Id id);

/**
 * @brief It destroys a playerinf, freeing the allocated memory
 * @author Jorge Torrijos de la Cruz
 *
 * @param playerinf A pointer to the playerinf that must be destroyed
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status playerinf_destroy(Playerinf *playerinf);

/**
 * @brief It sets the id of a playerinf
 * @author Jorge Torrijos de la Cruz
 *
 * @param playerinf A pointer to the playerinf
 * @param id The id to set
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status playerinf_set_id(Playerinf *playerinf, Id id);

/**
 * @brief It gets the id of playerinf
 * @author Jorge Torrijos de la Cruz
 *
 * @param playerinf A pointer to the Playerinf
 * @return id, if everything goes well or NO_ID if there was some mistake
 */
Id playerinf_get_id(Playerinf *playerinf);

/**
 * @brief It sets the lastcommand of a playerinf
 * @author Jorge Torrijos de la Cruz
 *
 * @param playerinf A pointer to the playerinf
 * @param lastcommand A pointer to the lastcommand to set
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status playerinf_set_lastcommand(Playerinf *playerinf, CommandCode lastcommand);

/**
 * @brief It gets the lastcommand of playerinf
 * @author Jorge Torrijos de la Cruz
 *
 * @param playerinf A pointer to the Playerinf
 * @return lastcommand, if everything goes well or NULL if there was some mistake
 */
CommandCode playerinf_get_lastcommand(Playerinf *playerinf);

/**
 * @brief It sets the laststatus of a playerinf
 * @author Jorge Torrijos de la Cruz
 *
 * @param playerinf A pointer to the playerinf
 * @param laststatus A pointer to the laststatus to set
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status playerinf_set_laststatus(Playerinf *playerinf, Bool laststatus);

/**
 * @brief It gets the laststatus of playerinf
 * @author Jorge Torrijos de la Cruz
 *
 * @param playerinf A pointer to the Playerinf
 * @return laststatus, if everything goes well or FALSE if there was some mistake
 */
Bool playerinf_get_laststatus(Playerinf *playerinf);

/**
 * @brief It sets the lastchat of a playerinf
 * @author Jorge Torrijos de la Cruz
 *
 * @param playerinf A pointer to the playerinf
 * @param lastchat A pointer to the lastchat to set
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status playerinf_set_lastchat(Playerinf *playerinf, char *lastchat);

/**
 * @brief It gets the lastchat of playerinf
 * @author Jorge Torrijos de la Cruz
 *
 * @param playerinf A pointer to the Playerinf
 * @return lastchat, if everything goes well or NULL if there was some mistake
 */
const char *playerinf_get_lastchat(Playerinf *playerinf);

/**
 * @brief It sets the lastinspect of a playerinf
 * @author Jorge Torrijos de la Cruz
 *
 * @param playerinf A pointer to the playerinf
 * @param lastinspect A pointer to the lastinspect to set
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status playerinf_set_lastinspect(Playerinf *playerinf, char *lastinspect);

/**
 * @brief It gets the lastinspect of playerinf
 * @author Jorge Torrijos de la Cruz
 *
 * @param playerinf A pointer to the Playerinf
 * @return lastinspect, if everything goes well or NULL if there was some mistake
 */
const char *playerinf_get_lastinspect(Playerinf *playerinf);

/**
 * @brief It prints the playerinf information
 * @author Jorge Torrijos de la Cruz
 * 
 * @param playerinf A pointer to the Playerinf
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status playerinf_print(Playerinf *playerinf);

#endif