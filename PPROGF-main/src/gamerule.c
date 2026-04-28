/**
 * @brief It implements the gamerule module
 *
 * @file gamerule.c
 * @author Iván Rodríguez Camacho, Guillermo Núñez Bravo
 * @version 7.0
 * @date 28-04-2026
 * @copyright GNU Public License
 */

#include "gamerule.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

/**
 * @brief Gamerule
 *
 * This struct stores all the information related to a gamerule.
 */
struct _Gamerule
{
    Rules rule;                       /*!< Name of the Rule */
    Status status;                    /*!< Status of the Rule */
    char argstr[MAX_ARGS][WORD_SIZE]; /*!< Rule arguments */
    int nArgs;                        /*!< Number of arguments */
    char *description;                /*!< Text contained in the Rule */
};

Gamerule *gamerule_create()
{
    int i, j;
    Gamerule *newGamerule = NULL;

    newGamerule = (Gamerule *)calloc(1, sizeof(Gamerule)); /*calloc peligroso!!!!!!!!!!!!*/
    if (!newGamerule)
    {
        return NULL;
    }

    newGamerule->rule = NO_RULE;

    for (i = 0; i < MAX_S; i++)
    {
        for (j = 0; j < MAX_C; j++)
        {
            newGamerule->argstr[i][j] = '\0';
        }
    }
    newGamerule->nArgs = 0;
    newGamerule->status = -1;
    newGamerule->description = '\0';

    return newGamerule;
}

Status gamerule_destroy(Gamerule *gamerule)
{
    if (!gamerule)
    {
        return ERROR;
    }

    free(gamerule);
    gamerule = NULL;
    return OK;
}

Status gamerule_set_rule(Gamerule *gamerule, Rules r)
{

    if (!gamerule)
    {
        return ERROR;
    }

    gamerule->rule = r;

    return OK;
}

Rules *gamerule_get_rule(Gamerule *gamerule)
{

    if (!gamerule)
    {
        return NO_RULE;
    }

    return gamerule->rule;
}

Status gamerule_set_status(Gamerule *gamerule, Status status)
{
    if (!gamerule)
    {
        return ERROR;
    }

    gamerule->status = status;

    return OK;
}

Status gamerule_get_status(Gamerule *gamerule)
{
    if (!gamerule)
    {
        return NO_RULE;
    }
    return gamerule->status;
}

Status gamerule_set_argstr(Gamerule *gamerule, char *argstr)
{
    if (!gamerule || !argstr || gamerule->nArgs >= MAX_ARGS)
    {
        return ERROR;
    }

    strcpy(gamerule->argstr[gamerule->nArgs], argstr);
    gamerule->nArgs++;

    return OK;
}

char *gamerule_get_argstr(Gamerule *gamerule, int position)
{
    if (!gamerule || gamerule->nArgs == 0)
    {
        return NULL;
    }

    return gamerule->argstr[position];
}

Status gamerule_set_description(Gamerule *gamerule, char *description)
{
    if (!gamerule)
    {
        return ERROR;
    }

    gamerule->description = description;

    return OK;
}

char *gamerule_get_description(Gamerule *gamerule)
{
    if (!gamerule)
    {
        return NULL;
    }
    return gamerule->description;
}

Status gamerule_set_nArgs(Gamerule *gamerule, int amount)
{
    if (!gamerule)
    {
        return ERROR;
    }

    gamerule->nArgs = amount;

    return OK;
}

/** It gets the nArgs of a command
 */
int gamerule_get_nArgs(Gamerule *gamerule)
{
    if (!gamerule)
    {
        return -1;
    }

    return gamerule->nArgs;
}

Status gamerule_check(Gamerule *gamerule)
{

    if (gamerule->status == ERROR)
    {
        return ERROR;
    }

    if (gamerule->rule == NO_RULE)
    {
        return ERROR;
    }

    if (gamerule->description == NULL)
    {

        return ERROR;
    }

    if (gamerule->nArgs == -1)
    {
        return ERROR;
    }

    return OK;
}
