/**
 * @brief It implements the space module
 *
 * @file space.c
 * @author Profesores PPROG
 * @version 4.0
 * @date 24-01-2026
 * @copyright GNU Public License
 */

#include "space.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Space
 *
 * This struct stores all the information of a space.
 */
struct _Space
{
  Id id;                    /*!< Id number of the space, it must be unique */
  char name[WORD_SIZE + 1]; /*!< Name of the space */
  Set *objects;             /*!< The object id array */
  Set *characters;          /*!< The character id array */
  char gdesc[MAX_S][MAX_C]; /*!< Description of the space */
  Bool discovered;          /*!< Discovered state of the space */
};

/** space_create allocates memory for a new space and initializes its members */
Space *space_create(Id id)
{
  Space *newSpace = NULL;
  int i, j;

  /* Error control */
  if (id == NO_ID)
    return NULL;

  newSpace = (Space *)calloc(1, sizeof(Space));
  if (newSpace == NULL)
  {
    return NULL;
  }

  /* Initialization of an empty space*/
  newSpace->id = id;
  newSpace->name[0] = '\0';
  newSpace->objects = set_create();
  newSpace->characters = set_create();
  newSpace->discovered = FALSE;
  for (i = 0; i < MAX_S; i++)
  {
    for (j = 0; j < MAX_C; j++)
    {
      newSpace->gdesc[i][j] = '\0';
    }
  }

  return newSpace;
}

/* It destroys a space, freeing the allocated memory*/
Status space_destroy(Space *space)
{
  if (!space)
  {
    return ERROR;
  }
  set_destroy(space->objects);
  set_destroy(space->characters);
  free(space);
  return OK;
}

/* It sets the id of a space*/
Status space_set_id(Space *space, Id id)
{
  if (!space)
  {
    return ERROR;
  }

  space->id = id;
  return OK;
}

/* It gets the id of a space*/
Id space_get_id(Space *space)
{
  if (!space)
  {
    return NO_ID;
  }
  return space->id;
}

/* It sets the name of a space*/
Status space_set_name(Space *space, char *name)
{
  if (!space || !name)
  {
    return ERROR;
  }

  if (!strcpy(space->name, name))
  {
    return ERROR;
  }
  return OK;
}

/* It gets the name of a space*/
const char *space_get_name(Space *space)
{
  if (!space)
  {
    return NULL;
  }
  return space->name;
}

/* It sets the space gdesc
 */
Status space_set_gdesc(Space *space, int row, char *text)
{
  if (!space || row >= MAX_S || row < 0 || !text)
  {
    return ERROR;
  }

  if (strcpy(space->gdesc[row], text) == NULL)
  {
    return ERROR;
  }

  return OK;
}

/* It gets the gdesc of the space
 */
const char *space_get_gdesc(Space *space, int row)
{
  if (!space || row >= MAX_S || row < 0)
  {
    return NULL;
  }

  return space->gdesc[row];
}

/* It adds the id of an object to the object set*/
Status space_add_object(Space *space, Id id)
{
  if (!space || id == NO_ID)
  {
    return ERROR;
  }

  if (set_get_n_ids(space->objects) == MAX_OBJECTS)
  {
    return NO_SPACE;
  }

  set_add(space->objects, id);

  return OK;
}

/*  It deletes the id of an object from the object set*/
Status space_del_object(Space *space, Id id)
{
  if (!space || id == NO_ID)
  {
    return ERROR;
  }

  set_del(space->objects, id);
  return OK;
}

/* It finds wether the object is in the space or not*/
Bool space_find_object(Space *space, Id id)
{
  if (!space || id == NO_ID)
  {
    return FALSE;
  }
  if (set_find(space->objects, id) == TRUE)
  {
    return TRUE;
  }

  return FALSE;
}

/* It gets the space objects
 */
Set *space_get_objects(Space *space)
{
  if (!space)
  {
    return NULL;
  }

  return space->objects;
}

/* It adds the id of a character to the character set*/
Status space_add_character(Space *space, Id id)
{
  if (!space || id == NO_ID)
  {
    return ERROR;
  }

  if (set_get_n_ids(space->characters) == MAX_CHARACTERS)
  {
    return NO_SPACE;
  }

  set_add(space->characters, id);

  return OK;
}

/*  It deletes the id of a character from the character set*/
Status space_del_character(Space *space, Id id)
{
  if (!space || id == NO_ID)
  {
    return ERROR;
  }

  set_del(space->characters, id);
  return OK;
}

/* It finds wether the character is in the space or not*/
Bool space_find_character(Space *space, Id id)
{
  if (!space || id == NO_ID)
  {
    return FALSE;
  }
  if (set_find(space->characters, id) == TRUE)
  {
    return TRUE;
  }

  return FALSE;
}
Set *space_get_characters(Space *space)
{
  if (!space)
  {
    return NULL;
  }

  return space->characters;
}

/* It sets the discovered status */
Status space_set_discovered(Space *space, Bool discovered)
{
  if (!space)
  {
    return ERROR;
  }

  space->discovered = discovered;

  return OK;
}

/* It gets the discovered status of the space */
Bool space_get_discovered(Space *space)
{
  if (!space)
  {
    return FALSE;
  }

  return space->discovered;
}

/* It prints the space information
 */
Status space_print(Space *space)
{
  Id space_id = NO_ID;
  int i;
  /* Error Control */
  if (!space)
  {
    return ERROR;
  }

  space_id = space_get_id(space);
  if (space_id == NO_ID)
  {
    return ERROR;
  }

  /* 1. Print the id and the name of the space */
  fprintf(stdout, "--> Space (Id: %ld; Name: %s)\n", space->id, space->name);

  /* 2. Print the objects in the space or not */
  if (set_get_n_ids(space->objects) > 0)
  {
    set_print(space->objects);
  }
  else
  {
    fprintf(stdout, "---> Space has no objects.");
  }

  /* 3. Print if there is a character in the space or not */
  if (set_get_n_ids(space->characters) > 0)
  {
    set_print(space->characters);
  }
  else
  {
    fprintf(stdout, "---> Space has no characters.");
  }

  /* 4. Prints space gdesc */
  for (i = 0; i < MAX_S; i++)
  {
    fprintf(stdout, "%s", space_get_gdesc(space, i));
  }

  /* 5. Prints if it has been discovered */
  if (space_get_discovered(space))
  {
    fprintf(stdout, "---> Space has been discovered.\n");
  }
  else
  {
    fprintf(stdout, "---> Space has not been discovered.\n");
  }

  return OK;
}