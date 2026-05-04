/**
 * @brief It defines the set module interface
 *
 * @file set.h
 * @author Álvaro Bravo González
 * @version 0
 * @date 28-04-2026
 * @copyright GNU Public License
 */

#ifndef SET_H
#define SET_H

#include "types.h"

/** Set structure type definition
 */
typedef struct _Set Set;

/**
 * @brief It creates a new set, allocating memory and initializing its members
 * @author Álvaro Bravo González
 *
 * @return A new set, initialized
 */
Set *set_create();

/**
 * @brief It destroys a set, freeing the allocated memory
 * @author Álvaro Bravo González
 *
 * @param set A pointer to the set that must be destroyed
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status set_destroy(Set *set);

/**
 * @brief It adds an id to the set
 * @author Álvaro Bravo González
 *
 * @param set A pointer to the set
 * @param id The new id you are adding
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status set_add(Set *set, Id id);

/**
 * @brief It deletes an id from the set
 * @author Álvaro Bravo González
 *
 * @param set A pointer to the set that must be destroyed
 * @param id The id you are deleting
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status set_del(Set *set, Id id);

/**
 * @brief It finds an id in the id array of the set
 * @author Álvaro Bravo González
 *
 * @param set A pointer to the set
 * @param id The id you are searching for
 * @return TRUE if the id is in the set or FALSE if it is not
 */
Bool set_find(Set *set, Id id);

/**
 * @brief It finds the position of an id in the id array of the set
 * @author Jorge Torrijos de la Cruz
 *
 * @param set A pointer to the set
 * @param id The id you are searching for
 * @return The position of the id in the id array of the set
 */
int set_findpos(Set *set, Id id);

/**
 * @brief It gets an id in the id array of the set by its position
 * @author Jorge Torrijos de la Cruz
 *
 * @param set A pointer to the set
 * @param position The position of the id in the set
 * @return The id located in that position
 */
Id set_get_id_at(Set *set, int position);

/**
 * @brief It sets the amount of ids stored in the set
 * @author Álvaro Bravo González
 *
 * @param set A pointer to the set 
 * @param n_ids The amount of ids that wants to be stored
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status set_set_n_ids(Set *set, int n_ids);

/**
 * @brief It gets the amount of ids stored in the set
 * @author Álvaro Bravo González
 *
 * @param set A pointer to the set
 * @return The amount of ids stored in the set
 */
int set_get_n_ids(Set *set);

/**
 * @brief It gets the id from its position
 * @author Álvaro Bravo González
 *
 * @param set A pointer to the set
 * @param position The position of the id in the set
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status set_get_id_with_position(Set *set, int position);

/**
 * @brief It prints the set information
 * @author Álvaro Bravo González
 *
 * This function shows the ids and the amount of ids stored in the set
 * @param set A pointer to the set
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status set_print(Set *set);
#endif