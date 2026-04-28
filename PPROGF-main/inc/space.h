/**
 * @brief It defines the space module interface
 *
 * @file space.h
 * @author Profesores PPROG
 * @version 0
 * @date 27-01-2025
 * @copyright GNU Public License
 */

#ifndef SPACE_H
#define SPACE_H

#include "object.h"
#include "set.h"
#include "types.h"

/**Space structure type definition
 */
typedef struct _Space Space;

/**
 * @brief It creates a new space, allocating memory and initializing its members
 * @author Profesores PPROG
 *
 * @param id The identification number for the new space
 * @return A new space, initialized
 */
Space *space_create(Id id);

/**
 * @brief It destroys a space, freeing the allocated memory
 * @author Profesores PPROG
 *
 * @param space A pointer to the space that must be destroyed
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status space_destroy(Space *space);

/**
 * @brief It sets the id of a space
 * @author Profesores PPROG
 *
 * @param space A pointer to the space
 * @param id The id number of the space
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status space_set_id(Space *space, Id id);

/**
 * @brief It gets the id of a space
 * @author Profesores PPROG
 *
 * @param space A pointer to the space
 * @return The id of space
 */
Id space_get_id(Space *space);

/**
 * @brief It sets the name of a space
 * @author Profesores PPROG
 *
 * @param space A pointer to the space
 * @param name A string with the name to store
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status space_set_name(Space *space, char *name);

/**
 * @brief It gets the name of a space
 * @author Profesores PPROG
 *
 * @param space A pointer to the space
 * @return  A string with the name of the space
 */
const char *space_get_name(Space *space);

/**
 * @brief It sets the gdesc of the space
 * @author Jorge Torrijos de la Cruz
 *
 * @param space A pointer to the space
 * @param row The row of the gdesc
 * @param text The text for the gdesc
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status space_set_gdesc(Space *space, int row, char *text);

/**
 * @brief It gets the gdesc of the space
 * @author Jorge Torrijos de la Cruz
 *
 * @param space A pointer to the space
 * @param row The row of the gdesc to get
 * @return The gdesc of the space at the row
 */
const char *space_get_gdesc(Space *space, int row);

/**
 * @brief It adds the id of an object to the object set
 * @author Profesores PPROG
 *
 * @param space A pointer to the space
 * @param id The id of the object
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status space_add_object(Space *space, Id id);

/**
 * @brief It deletes the id of an object from the object set
 * @author Profesores PPROG
 *
 * @param space A pointer to the space
 * @param id The id of the object
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status space_del_object(Space *space, Id id);

/**
 * @brief It finds wether an object is in the set or not
 * @author Jorge Torrijos de la Cruz
 *
 * @param space A pointer to the space
 * @param id The id of the object
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Bool space_find_object(Space *space, Id id);

/**
 * @brief It gets the objects of a space
 * @author Jorge Torrijos de la Cruz
 *
 * @param space A pointer to the space
 * @return The set of objects in the space
 */
Set *space_get_objects(Space *space);

/**
 * @brief It adds the id of a character to the character set
 * @author Álvaro Bravo González
 *
 * @param space A pointer to the space
 * @param id The id of the character
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status space_add_character(Space *space, Id id);

/**
 * @brief It deletes the id of a character from the character set
 * @author Álvaro Bravo González
 *
 * @param space A pointer to the space
 * @param id The id of the character
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status space_del_character(Space *space, Id id);

/**
 * @brief It finds wether a character is in the set or not
 * @author Álvaro Bravo González
 *
 * @param space A pointer to the space
 * @param id The id of the character
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Bool space_find_character(Space *space, Id id);

/**
 * @brief It gets the characters of a space
 * @author Jorge Torrijos de la Cruz
 *
 * @param space A pointer to the space
 * @return The set of characters in the space
 */
Set *space_get_characters(Space *space);

/**
 * @brief It sets the discovered status of a space
 * @author Jorge Torrijos de la Cruz
 *
 * @param space A pointer to the space
 * @param discovered Wether it has been discovered or not
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status space_set_discovered(Space *space, Bool discovered);

/**
 * @brief It gets the discovered status of a space
 * @author Jorge Torrijos de la Cruz
 *
 * @param space A pointer to the space
 * @return The boolean value of discovered status
 */
Bool space_get_discovered(Space *space);

/**
 * @brief It prints the space information
 * @author Profesores PPROG
 *
 * This fucntion shows the id and name of the space, wheter it has an object or not.
 * @param space A pointer to the space
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status space_print(Space *space);

#endif