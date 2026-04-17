/**
 * @brief It defines the object module interface
 *
 * @file object.h
 * @author Álvaro Bravo González
 * @version 0
 * @date 03-02-2026
 * @copyright GNU Public License
 */

#ifndef OBJECT_H
#define OBJECT_H

#include "types.h"

/** Object structure type definition
 */
typedef struct _Object Object;

/**
 * @brief It creates a new object, allocating memory and initializing its members
 * @author Álvaro Bravo González
 *
 * @param id The identification number for the new object
 * @return A new object, initialized
 */
Object *object_create(Id id);

/**
 * @brief It destroys the object, freeing the allocated memory
 * @author Álvaro Bravo González
 *
 * @param object A pointer to the object that must be destroyed
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status object_destroy(Object *object);

/**
 * @brief It sets the id of an object
 * @author Álvaro Bravo González
 *
 * @param object A pointer to the object
 * @param id The id of the object
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status object_set_id(Object *object, Id id);

/**
 * @brief It gets the id of an object
 * @author Álvaro Bravo González
 *
 * @param object A pointer to the object
 * @return The id of the object
 */
Id object_get_id(Object *object);

/**
 * @brief It sets the name of an object
 * @author Álvaro Bravo González
 *
 * @param object A pointer to the object
 * @param name A string with the name to store
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status object_set_name(Object *object, char *name);

/**
 * @brief It gets the name of an object
 * @author Álvaro Bravo González
 *
 * @param object A pointer to the object
 * @return A string with the name of the object
 */
char *object_get_name(Object *object);

/**
 * @brief It sets the description of an object
 * @author Álvaro Bravo González
 *
 * @param object A pointer to the object
 * @param desc A string with the description to store
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status object_set_desc(Object *object, char *desc);

/**
 * @brief It gets the description of an object
 * @author Álvaro Bravo González
 *
 * @param object A pointer to the object
 * @return A string with the description of the object
 */
char *object_get_desc(Object *object);

/**
 * @brief It sets the health value of an object
 * @author Jorge Torrijos de la Cruz
 *
 * @param object A pointer to the object
 * @param health An integer with the amount of health to store
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status object_set_health(Object *object, int health);

/**
 * @brief It gets the health value of an object
 * @author Jorge Torrijos de la Cruz
 *
 * @param object A pointer to the object
 * @return An integer with the amount of health to store
 */
int object_get_health(Object *object);

/**
 * @brief It sets the health movable value of an object
 * @author Jorge Torrijos de la Cruz
 *
 * @param object A pointer to the object
 * @param movable The boolean value, if it can be moved or not
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status object_set_movable(Object *object, Bool movable);

/**
 * @brief It gets the movable value of an object
 * @author Jorge Torrijos de la Cruz
 *
 * @param object A pointer to the object
 * @return The boolean value, if it can be moved or not
 */
Bool object_get_movable(Object *object);

/**
 * @brief It sets the dependency value of an object
 * @author Jorge Torrijos de la Cruz
 *
 * @param object A pointer to the object
 * @param dependency_id The id of the object or space needed
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status object_set_dependency(Object *object, Id dependency_id);

/**
 * @brief It gets the dependency value of an object
 * @author Jorge Torrijos de la Cruz
 *
 * @param object A pointer to the object
 * @return The id of the object or space needed
 */
Id object_get_dependency(Object *object);

/**
 * @brief It sets the open value of an object
 * @author Jorge Torrijos de la Cruz
 *
 * @param object A pointer to the object
 * @param space_id The id of the link it opens
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Id object_set_open(Object *object, Id space_id);

/**
 * @brief It gets the open value of an object
 * @author Jorge Torrijos de la Cruz
 *
 * @param object A pointer to the object
 * @return The id of the link it opens
 */
Id object_get_open(Object *object);

/**
 * @brief It prints the object information
 * @author Álvaro Bravo González
 *
 * This fucntion shows the id, name of the object, description, health value, movable value, dependency ID and open ID.
 * @param object A pointer to the object
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status object_print(Object *object);

#endif