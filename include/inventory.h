/**
 * @brief It defines the inventory module interface
 *
 * @file inventory.h
 * @author Álvaro Bravo González
 * @version 0
 * @date 21-03-2026
 * @copyright GNU Public License
 */
#ifndef INVENTORY_H
#define INVENTORY_H

#include "types.h"
#include "set.h"
#include "object.h"

typedef struct _Inventory Inventory;

/**
 * @brief It creates a new inventory, allocating memory and initializing its members
 * @author Álvaro Bravo González
 *
 * @return A pointer to the inventory structure
 */
Inventory *inventory_create();

/**
 * @brief It destroys the inventory, freeing the allocated memory
 * @author Álvaro Bravo González
 *
 * @param inventory A pointer to the inventory data
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status inventory_destroy(Inventory *inventory);

/**
 * @brief It sets the set of objects
 * @author Álvaro Bravo González
 *
 * @param inventory A pointer to the inventory data
 * @param objs A pointer to the set of objects
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status inventory_set_objs(Inventory *inventory, Set *objs);

/**
 * @brief It gets the set of objects
 * @author Álvaro Bravo González
 *
 * @param inventory A pointer to the inventory data
 * @return The set of objects
 */
Set *inventory_get_objs(Inventory *inventory);

/**
 * @brief It sets the maximum quantity of objects
 * @author Álvaro Bravo González
 *
 * @param inventory A pointer to the inventory data
 * @param max_objs The maximum quantity of objects
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status inventory_set_max_objs(Inventory *inventory, int max_objs);

/**
 * @brief It gets the maximum quantity of objects
 * @author Álvaro Bravo González
 *
 * @param inventory A pointer to the inventory data
 * @return The maximum  of objects
 */
int inventory_get_max_objs(Inventory *inventory);

/**
 * @brief It adds the id of an object to the objs set
 * @author Álvaro Bravo González
 *
 * @param inventory A pointer to the inventory data
 * @param id The id of the object
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status inventory_add_object(Inventory *inventory, Id id);

/**
 * @brief It deletes an id from the inventory
 * @author Álvaro Bravo González
 *
 * @param inventory A pointer to the inventory that must be destroyed
 * @param id The id you are deleting
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status inventory_del_object(Inventory *inventory, Id id);

/**
 * @brief It find wether an object is in the set or not
 * @author Álvaro Bravo González
 *
 * @param inventory A pointer to the inventory data
 * @param object_id The id of the object
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Bool inventory_find_object(Inventory *inventory, Id object_id);

Status inventory_set_n_objs(Inventory *inventory, int n_objs);

int inventory_get_n_objs(Inventory *inventory);

/**
 * @brief It prints the inventory information
 * @author Álvaro Bravo González
 *
 * This fucntion shows the objects and maximum amount of objects stored in the inventory
 * @param inventory A pointer to the inventory
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status inventory_print();

#endif