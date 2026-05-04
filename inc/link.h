/**
 * @brief It defines the link module interface
 *
 * @file link.h
 * @author Jorge Torrijos de la Cruz
 * @version 0
 * @date 28-04-2026
 * @copyright GNU Public License
 */
#ifndef LINK_H
#define LINK_H

#include "types.h"

/**Link structure type definition
 */
typedef struct _Link Link;

/**
 * @brief It creates a new link, allocating memory and initializing its members
 * @author Jorge Torrijos de la Cruz
 *
 * @param id The identification number for the new link
 * @return A new link, initialized
 */
Link *link_create(Id id);

/**
 * @brief It destroys a link, freeing the allocated memory
 * @author Jorge Torrijos de la Cruz
 *
 * @param link A pointer to the link that must be destroyed
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status link_destroy(Link *link);

/**
 * @brief It sets the id of a link
 * @author Jorge Torrijos de la Cruz
 *
 * @param link A pointer to the link
 * @param id The id number of the link
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status link_set_id(Link *link, Id id);

/**
 * @brief It gets the id of a link
 * @author Jorge Torrijos de la Cruz
 *
 * @param link A pointer to the link
 * @return The id of link
 */
Id link_get_id(Link *link);

/**
 * @brief It sets the name of a link
 * @author Jorge Torrijos de la Cruz
 *
 * @param link A pointer to the link
 * @param name A string with the name to store
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status link_set_name(Link *link, char *name);

/**
 * @brief It gets the link name
 * @author Jorge Torrijos de la Cruz
 *
 * @param link A pointer to the link
 * @return The id of the name of the link
 */
const char *link_get_name(Link *link);

/**
 * @brief It sets the origin of a link
 * @author Jorge Torrijos de la Cruz
 *
 * @param link A pointer to the link
 * @param id The id number of the origin space
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status link_set_origin(Link *link, Id id);

/**
 * @brief It gets the id of the origin space
 * @author Jorge Torrijos de la Cruz
 *
 * @param link A pointer to the link
 * @return The id of origin space
 */
Id link_get_origin(Link *link);

/**
 * @brief It sets the destination of a link
 * @author Jorge Torrijos de la Cruz
 *
 * @param link A pointer to the link
 * @param id The id number of the destination space
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status link_set_destination(Link *link, Id id);

/**
 * @brief It gets the id of the destination space
 * @author Jorge Torrijos de la Cruz
 *
 * @param link A pointer to the link
 * @return The id of destination space
 */
Id link_get_destination(Link *link);

/**
 * @brief It sets the direction of the link
 * @author Jorge Torrijos de la Cruz
 *
 * @param link A pointer to the link
 * @param direction The direction where the link is facing
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status link_set_direction(Link *link, Direction direction);

/**
 * @brief It gets the id the direction of the link
 * @author Jorge Torrijos de la Cruz
 *
 * @param link A pointer to the link
 * @return The direction of the link
 */
Direction link_get_direction(Link *link);

/**
 * @brief It sets the open status of the link
 * @author Jorge Torrijos de la Cruz
 *
 * @param link A pointer to the link
 * @param open Wether it has been opened or not
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status link_set_open(Link *link, Bool open);

/**
 * @brief It gets the open status of the link
 * @author Jorge Torrijos de la Cruz
 *
 * @param link A pointer to the link
 * @return Wether it has been opened or not
 */
Bool link_get_open(Link *link);

/**
 * @brief It prints the link information
 * @author Jorge Torrijos de la Cruz
 * This function shows the id and name of the link, the link's origin and destination id, the link's direction and wheter it has been opened or not.
 * @param link A pointer to the link
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status link_print(Link *link);
#endif