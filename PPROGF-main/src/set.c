/**
 * @brief It implements the set module
 *
 * @file set.c
 * @author Álvaro Bravo González, Jorge Torrijos de la Cruz
 * @version 7.0
 * @date 28-04-2026
 * @copyright GNU Public License
 */

#include "set.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Set
 *
 * This struct stores all the information related to a set.
 */
struct _Set
{
    Id *ids;   /*!< Array of ids*/
    int n_ids; /*!< Number of ids*/
};

/* It creates a new set, allocating memory
 *  and initializing its members
 */
Set *set_create()
{
    Set *newSet = NULL;
    int i;

    newSet = (Set *)calloc(1, sizeof(Set));
    if (newSet == NULL)
    {
        return NULL;
    }
    newSet->ids = (Id *)calloc(MAX_IDS, sizeof(Id));
    if (newSet->ids == NULL)
    {
        return NULL;
    }

    for (i = 0; i < MAX_IDS; i++)
    {
        newSet->ids[i] = NO_ID;
    }
    newSet->n_ids = 0;

    return newSet;
}

/* It destroys a set, freeing the allocated memory
 */
Status set_destroy(Set *set)
{
    if (!set)
    {
        return ERROR;
    }

    if (set->ids)
    {
        free(set->ids);
    }
    free(set);

    return OK;
}

/* It adds an id to the set
 */
Status set_add(Set *set, Id id)
{
    if (!set || set->n_ids >= MAX_IDS || id == NO_ID)
    {
        return ERROR;
    }

    set->ids[set->n_ids] = id;
    set->n_ids++;

    return OK;
}

/* It deletes an id from the set
 */
Status set_del(Set *set, Id id)
{
    int pos;

    if (!set || set->n_ids >= MAX_IDS || id == NO_ID)
    {
        return ERROR;
    }

    pos = set_findpos(set, id);
    if (pos == -1)
    {
        return ERROR;
    }

    set->ids[pos] = set->ids[set->n_ids - 1];
    set->ids[set->n_ids - 1] = NO_ID;
    set->n_ids--;

    return OK;
}

/* It finds an id in the id array of the set
 */
Bool set_find(Set *set, Id id)
{
    int i;

    if (!set || id == NO_ID || set->n_ids >= MAX_IDS)
    {
        return FALSE;
    }

    for (i = 0; i < set->n_ids; i++)
    {
        if (set->ids[i] == id)
        {
            return TRUE;
        }
    }

    return FALSE;
}

/* It finds the position of an id in the id array of the set
 */
int set_findpos(Set *set, Id id)
{
    int i;

    if (!set || id == NO_ID || set->n_ids >= MAX_IDS)
    {
        return FALSE;
    }

    for (i = 0; i < set->n_ids; i++)
    {
        if (set->ids[i] == id)
            return i;
    }

    return -1;
}

/* It gets an id in the id array of the set by its position
 */
Id set_get_id_at(Set *set, int position)
{
    if (!set || position < 0 || position > set_get_n_ids(set))
    {
        return NO_ID;
    }

    return set->ids[position];
}

/** It sets the amount of ids stored in the set
 */
Status set_set_n_ids(Set *set, int n_ids)
{
    if (!set || n_ids < 0 || n_ids > MAX_IDS)
    {
        return ERROR;
    }

    set->n_ids = n_ids;

    return OK;
}

/** It gets the amount of ids stored in the set
 */
int set_get_n_ids(Set *set)
{
    if (!set)
    {
        return -1;
    }

    return set->n_ids;
}

/** It gets the id from its position
 */
Status set_get_id_with_position(Set *set, int position)
{
    if (!set || position < 0 || position > set_get_n_ids(set))
    {
        return ERROR;
    }

    return set->ids[position];
}

/** It prints the set information
 */
Status set_print(Set *set)
{
    int i;

    /* Error Control */
    if (!set)
    {
        return ERROR;
    }

    if (set->n_ids == 0)
    {
        return NO_ID;
    }

    /* 1. Print the ids of the set */
    for (i = 0; i < MAX_IDS; i++)
    {
        fprintf(stdout, "%ld", set->ids[i]);
    }

    /*2. Print the amount of ids*/
    fprintf(stdout, "%d", set->n_ids);

    return OK;
}