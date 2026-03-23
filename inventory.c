
#include "inventory.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct _Inventory
{
    Set *objs;    /*!< The object id array */
    int max_objs; /*!< Maximum amount of objects */
    int n_objs;   /*!< Total amount of objects */
};

Inventory *inventory_create()
{
    Inventory *newInventory;

    newInventory = (Inventory *)malloc(sizeof(Inventory));
    if (!newInventory)
    {
        return NULL;
    }

    newInventory->objs = set_create();
    newInventory->max_objs = 0;

    return newInventory;
}

Status inventory_destroy(Inventory *inventory)
{
    if (!inventory)
    {
        return ERROR;
    }

    free(inventory);

    return OK;
}

Status inventory_set_objs(Inventory *inventory, Set *objs)
{
    if (!inventory || !objs)
    {
        return ERROR;
    }

    inventory->objs = objs;

    return OK;
}

Set *inventory_get_objs(Inventory *inventory)
{
    if (!inventory)
    {
        return NULL;
    }

    return inventory->objs;
}

Status inventory_set_max_objs(Inventory *inventory, int max_objs)
{
    if (!inventory || max_objs < 0)
    {
        return ERROR;
    }

    inventory->max_objs = max_objs;

    return OK;
}

int inventory_get_max_objs(Inventory *inventory)
{
    if (!inventory)
    {
        return -1;
    }

    return inventory->max_objs;
}

Status inventory_set_n_objs(Inventory *inventory, int n_objs)
{
    if (!inventory || n_objs < 0)
    {
        return ERROR;
    }

    inventory->n_objs = n_objs;

    return OK;
}

int inventory_get_n_objs(Inventory *inventory)
{
    if (!inventory)
    {
        return -1;
    }

    return inventory->n_objs;
}

Status inventory_add_object(Inventory *inventory, Id id)
{
    if (!inventory || id == NO_ID)
    {
        return ERROR;
    }

    if (set_get_n_ids(inventory->objs) == inventory_get_max_objs(inventory))
    {
        return NO_SPACE;
    }

    set_add(inventory->objs, id);

    inventory_set_n_objs(inventory, inventory_get_n_objs(inventory) + 1);

    return OK;
}

Status inventory_del_object(Inventory *inventory, Id id)
{
    if (!inventory || id == NO_ID)
    {
        return ERROR;
    }

    set_del(inventory->objs, id);

    inventory_set_n_objs(inventory, inventory_get_n_objs(inventory) - 1);

    return OK;
}

int inventory_find_object(Inventory *inventory, Id object_id)
{
    if (!inventory || object_id == NO_ID)
    {
        return FALSE;
    }

    if (set_find(inventory->objs, object_id) != -1)
    {
        return TRUE;
    }

    return FALSE;
}

Status inventory_print(Inventory *inventory)
{
    /* Error Control */
    if (!inventory)
    {
        return ERROR;
    }

    /* 1. Print the inventory declaration */
    fprintf(stdout, "--> Inventory: \n");

    /* 2. Print the player's location */
    fprintf(stdout, "---> Objects:\n");

    /*Hay que implementar con un bucle el nombre de cada objeto, o si no se hace en player, estoy un poco perdido aqui*/

    return OK;
}