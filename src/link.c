/**
 * @brief It implements the link module
 *
 * @file link.c
 * @author Jorge Torrijos de la Cruz
 * @version 4.0
 * @date 21-03-2026
 * @copyright GNU Public License
 */

#include "link.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Link
 *
 * This struct stores all the information of a link.
 */
struct _Link
{
    Id id;                    /*!< Id number of the link, it must be unique */
    char name[WORD_SIZE + 1]; /*!< Name of the link */
    Id origin;                /*!< Id of the initial space */
    Id destination;           /*!< Id of the final space */
    Direction direction;      /*!< Direction where the link is facing */
    Bool open;                /*!< States wether it has been opened or not */
};

/* It creates a new player, allocating memory and initializing its members */
Link *link_create(Id id)
{
    Link *newLink = NULL;

    /* Error control */
    if (id == NO_ID)
        return NULL;

    newLink = (Link *)calloc(1, sizeof(Link));
    if (newLink == NULL)
    {
        return NULL;
    }

    /* Initialization of an empty link*/
    newLink->id = id;
    newLink->name[0] = '\0';
    newLink->origin = NO_ID;
    newLink->destination = NO_ID;
    newLink->direction = N;
    newLink->open = FALSE;

    return newLink;
}

/* It destroys a link, freeing the allocated memory*/
Status link_destroy(Link *link)
{
    if (!link)
    {
        return ERROR;
    }
    free(link);
    return OK;
}

/* It sets the id of a link*/
Status link_set_id(Link *link, Id id)
{
    if (!link)
    {
        return ERROR;
    }

    link->id = id;
    return OK;
}

/* It gets the id of the link*/
Id link_get_id(Link *link)
{
    if (!link)
    {
        return NO_ID;
    }
    return link->id;
}

/* It sets the name of the link*/
Status link_set_name(Link *link, char *name)
{
    if (!link || !name)
    {
        return ERROR;
    }

    if (!strcpy(link->name, name))
    {
        return ERROR;
    }
    return OK;
}

/* It gets the name of the link*/
const char *link_get_name(Link *link)
{
    if (!link)
    {
        return NULL;
    }
    return link->name;
}

/* It sets the origin of a link*/
Status link_set_origin(Link *link, Id id)
{
    if (!link)
    {
        return ERROR;
    }

    link->origin = id;
    return OK;
}

/* It gets the origin of the link*/
Id link_get_origin(Link *link)
{
    if (!link)
    {
        return NO_ID;
    }
    return link->origin;
}

/* It sets the destination of a link*/
Status link_set_destination(Link *link, Id id)
{
    if (!link)
    {
        return ERROR;
    }

    link->destination = id;
    return OK;
}

/* It gets the destination of the link*/
Id link_get_destination(Link *link)
{
    if (!link)
    {
        return NO_ID;
    }
    return link->destination;
}

/* It sets the direction of a link*/
Status link_set_direction(Link *link, Direction direction)
{
    if (!link)
    {
        return ERROR;
    }

    link->direction = direction;
    return OK;
}

/* It gets the direction of the link*/
Direction link_get_direction(Link *link)
{
    if (!link)
    {
        return NO_ID;
    }
    return link->direction;
}

/* It sets the open status of a link*/
Status link_set_open(Link *link, Bool open)
{
    if (!link)
    {
        return ERROR;
    }

    link->open = open;
    return OK;
}

/* It gets the open status of the link*/
Bool link_get_open(Link *link)
{
    if (!link)
    {
        return NO_ID;
    }

    return link->open;
}

/* It prints the link information*/
Status link_print(Link *link)
{
    if (!link)
    {
        return ERROR;
    }

    /*1. Prints the id and name of the link*/
    fprintf(stdout, "--> Link (Id: %ld; Name: %s)\n", link->id, link->name);

    /* 2. Prints the link origin, destination and direction */
    fprintf(stdout, "--> Origin: %ld  Destination: %ld Direction: %hu\n", link->origin, link->destination, link->direction);

    /* 3. Prints wether it has been opened or not */
    if (link->open == 0)
    {
        fprintf(stdout, "---> Link has not been opened.");
    }
    else
    {
        fprintf(stdout, "---> Link has been opened.");
    }

    return OK;
}