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
 * @brief It prints the object information
 * @author Álvaro Bravo González
 *
 * This fucntion shows the id and name of the object.
 * @param object A pointer to the object
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status object_print(Object *object);

#endif