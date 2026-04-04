/**
 * @brief It defines the player module interface
 *
 * @file player.h
 * @author Jorge Torrijos de la Cruz
 * @version 0
 * @date 03-02-2025
 * @copyright GNU Public License
 */

#ifndef PLAYER_H
#define PLAYER_H

#include "types.h"
#include "set.h"
#include "inventory.h"

/** Player structure type definition
 */
typedef struct _Player Player;

/**
 * @brief It creates a new player, allocating memory and initializing its members
 * @author Jorge Torrijos de la Cruz
 *
 * @param id The identification number for the new player
 * @return A new player, initialized
 */
Player *player_create(Id id);

/**
 * @brief It destroys a player, freeing the allocated memory
 * @author Jorge Torrijos de la Cruz
 *
 * @param player A pointer to the player that must be destroyed
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status player_destroy(Player *player);

/**
 * @brief It sets the id of a player
 * @author Jorge Torrijos de la Cruz
 *
 * @param player A pointer to the player
 * @param id The id number of the player
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status player_set_id(Player *player, Id id);

/**
 * @brief It gets the id of a player
 * @author Jorge Torrijos de la Cruz
 *
 * @param player A pointer to the player
 * @return The id of player
 */
Id player_get_id(Player *player);

/**
 * @brief It sets the name of a player
 * @author Jorge Torrijos de la Cruz
 *
 * @param player A pointer to the player
 * @param name A string with the name to store
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status player_set_name(Player *player, char *name);

/**
 * @brief It gets  the player name
 * @author Jorge Torrijos de la Cruz
 *
 * @param player A pointer to the player
 * @return The id of the name of the player
 */
const char *player_get_name(Player *player);

/**
 * @brief It adds the object to the player set
 * @author Jorge Torrijos de la Cruz
 *
 * @param player A pointer to the inventory
 * @param id The id of the object to add
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status player_add_object(Player *player, Id id);

/**
 * @brief It deletes the object from the player inventory
 * @author Jorge Torrijos de la Cruz
 *
 * @param player A pointer to the player
 * @param id The id of the object to delete
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status player_del_object(Player *player, Id id);

/**
 * @brief It finds the object in the set
 * @author Jorge Torrijos de la Cruz
 *
 * @param player A pointer to the player
 * @param id The id of the object to find
 * @return TRUE if the object is found, FALSE if it isn't found or if a mistake happens
 */
Bool player_find_object(Player *player, Id id);

/**
 * @brief It gets the objects
 * @author Álvaro Bravo González
 *
 * @param player A pointer to the player
 * @return A pointer to the set of objects structure
 */
Inventory *player_get_objects(Player *player);

/**
 * @brief It sets the id of a player's location
 * @author Jorge Torrijos de la Cruz
 *
 * @param player A pointer to the player
 * @param location The id of the space
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status player_set_location(Player *player, Id location);

/**
 * @brief It gets the player's location
 * @author Jorge Torrijos de la Cruz
 *
 * @param player A pointer to the player
 * @return The id of the location
 */
Id player_get_location(Player *player);

/**
 * @brief It sets the health of a player
 * @author Jorge Torrijos de la Cruz
 *
 * @param player A pointer to the player
 * @param health The amount of health to set
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status player_set_health(Player *player, int health);

/**
 * @brief It gets  the health of a player
 * @author Jorge Torrijos de la Cruz
 *
 * @param player A pointer to the player
 * @return The amount of health
 */
int player_get_health(Player *player);

/**
 * @brief It sets the description of a player
 * @author Jorge Torrijos de la Cruz
 *
 * @param player A pointer to the player
 * @param gdesc A string with the description to store
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status player_set_gdesc(Player *player, char *gdesc);

/**
 * @brief It gets the description of a  player
 * @author Jorge Torrijos de la Cruz
 *
 * @param player A pointer to the player
 * @return The id of the description of the player
 */
const char *player_get_gdesc(Player *player);

/**
 * @brief It prints the player information
 * @author Jorge Torrijos de la Cruz
 * This function shows the id and name of the player, the player's location  and wheter it has an object or not.
 * @param player A pointer to the player
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status player_print(Player *player);

#endif