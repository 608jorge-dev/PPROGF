/**
 * @brief It implements the set module
 *
 * @file set.c
 * @author Álvaro Bravo González
 * @version 0
 * @date 23-02-2026
 * @copyright GNU Public License
 */

#include "set.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Set
 *
 * This struct stores all the information of a set.
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

    /* Initialization of an empty set*/

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

Status set_del(Set *set, Id id)
{
    int pos;

    if (!set || set->n_ids >= MAX_IDS || id == NO_ID)
    {
        return ERROR;
    }

    pos = set_find(set, id);
    if (pos == -1)
    {
        return ERROR;
    }

    set->ids[pos] = set->ids[set->n_ids];
    set->ids[set->n_ids] = NO_ID;
    set->n_ids--;

    return OK;
}

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
            return TRUE;
    }

    return FALSE;
}

Id set_get_id_at(Set *set, int position)
{
    if (!set || position < 0 || position > set_get_n_ids(set))
    {
        return NO_ID;
    }

    return set->ids[position];
}

/** It sets n_ids
 */
Status set_set_n_ids(Set *set, int number)
{
    set->n_ids = number;

    return OK;
}

/** It gets n_ids
 */
int set_get_n_ids(Set *set)
{
    if (!set)
    {
        return 0;
    }

    return set->n_ids;
}

Status set_get_id_with_position(Set *set, int position)
{
    if (!set)
    {
        return ERROR;
    }

    return set->ids[position];
}

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