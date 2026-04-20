/**
 * @brief It defines the character module interface
 *
 * @file character.h
 * @author Jorge Torrijos de la Cruz
 * @version 0
 * @date 20-02-2025
 * @copyright GNU Public License
 */

#ifndef CHARACTER_H
#define CHARACTER_H

#include "types.h"

/** Character structure type definition
 */
typedef struct _Character Character;

/**
 * @brief It creates a new character, allocating memory and initializing its members
 * @author Jorge Torrijos de la Cruz
 *
 * @param id The identification number for the new character
 * @return A new character, initialized
 */
Character *character_create(Id id);

/**
 * @brief It destroys a character, freeing the allocated memory
 * @author Jorge Torrijos de la Cruz
 *
 * @param character a pointer to the character that must be destroyed
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status character_destroy(Character *character);

/**
 * @brief It sets the id of a character
 * @author Jorge Torrijos de la Cruz
 *
 * @param character A pointer to the character
 * @param id The id number of the character
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status character_set_id(Character *character, Id id);

/**
 * @brief It gets the id of a character
 * @author Jorge Torrijos de la Cruz
 *
 * @param character A pointer to the character
 * @return The id of character
 */
Id character_get_id(Character *character);

/**
 * @brief It sets the name of a character
 * @author Jorge Torrijos de la Cruz
 *
 * @param character A pointer to the character
 * @param name A string with the name to store
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status character_set_name(Character *character, char *name);

/**
 * @brief It gets the character name
 * @author Jorge Torrijos de la Cruz
 *
 * @param character A pointer to the character
 * @return The id of the name of the character
 */
char *character_get_name(Character *character);

/**
 * @brief It sets the description of a character
 * @author Jorge Torrijos de la Cruz
 *
 * @param character A pointer to the character
 * @param gdesc A string with the description to store
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status character_set_gdesc(Character *character, char *gdesc);

/**
 * @brief It gets the description of a  character
 * @author Jorge Torrijos de la Cruz
 *
 * @param character A pointer to the character
 * @return The id of the description of the character
 */
const char *character_get_gdesc(Character *character);

/**
 * @brief It sets the health of a character
 * @author Jorge Torrijos de la Cruz
 *
 * @param character A pointer to the character
 * @param health The amount of health to set
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status character_set_health(Character *character, int health);

/**
 * @brief It gets  the health of a character
 * @author Jorge Torrijos de la Cruz
 *
 * @param character A pointer to the character
 * @return The amount of health
 */
int character_get_health(Character *character);

/**
 * @brief It sets the friendly state of a character
 * @author Jorge Torrijos de la Cruz
 *
 * @param character A pointer to the character
 * @param friendly A boolean value that sets the friendly state
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status character_set_friendly(Character *character, Bool friendly);

/**
 * @brief It gets  the friendly state of a character
 * @author Jorge Torrijos de la Cruz
 *
 * @param character A pointer to the character
 * @return A boolean, specifying if the character finishes (TRUE) or not (FALSE)
 * It also returns FALSE in case there is an error
 */
Bool character_get_friendly(Character *character);

/**
 * @brief It sets message of a character
 * @author Jorge Torrijos de la Cruz
 *
 * @param character A pointer to the character
 * @param msg A string with the message to store
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status character_set_message(Character *character, char *msg);

/**
 * @brief It gets  the message of a character
 * @author Jorge Torrijos de la Cruz
 *
 * @param character A pointer to the character
 * @return The id of the description of the character
 */
char *character_get_message(Character *character);

/**
 * @brief It sets the id of the player being followed
 * @author Jorge Torrijos de la Cruz
 *
 * @param character A pointer to the character
 * @param id The id of the player being followed
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status character_set_following(Character *character, Id id);

/**
 * @brief It gets the id of the player being followed
 * @author Jorge Torrijos de la Cruz
 *
 * @param character A pointer to the character
 * @return The id of the player being followed
 */
Id character_get_following(Character *character);

/**
 * @brief It prints the character information
 * @author Jorge Torrijos de la Cruz
 * This function shows the id and name of the character, the description and health from the character, wether is friendly or not and the message is contains
 * @param character A pointer to the character
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status character_print(Character *character);

#endif