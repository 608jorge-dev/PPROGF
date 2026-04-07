/**
 * @brief It implements the object module
 *
 * @file object.c
 * @author Álvaro Bravo González
 * @version 0
 * @date 04-02-2026
 * @copyright GNU Public License
 */

#include "object.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Object
 *
 * This struct stores all the information of the object.
 */

struct _Object
{
  Id id;                     /*!< Id number of the object, it must be unique */
  char name[WORD_SIZE + 1];  /*!< Name of the object */
  char gdesc[WORD_SIZE + 1]; /*!< Description of the object */
};

/* It creates a new object, allocating memory and initializing its members
 */
Object *object_create(Id id)
{
  Object *newObject = NULL;

  /* Error control */
  if (id == NO_ID)
    return NULL;

  newObject = (Object *)calloc(1, sizeof(Object));
  if (newObject == NULL)
  {
    return NULL;
  }

  /* Initialization of an empty object*/
  newObject->id = id;
  newObject->name[0] = '\0';

  return newObject;
}

/* It destroys the object, freeing the allocated memory
 */
Status object_destroy(Object *object)
{
  if (!object)
  {
    return ERROR;
  }

  free(object);
  return OK;
}

/* It sets the id of an object
 */
Status object_set_id(Object *object, Id id)
{
  if (!object)
  {
    return ERROR;
  }
  object->id = id;
  return OK;
}

/* It gets the id of an object
 */
Id object_get_id(Object *object)
{
  if (!object)
  {
    return NO_ID;
  }
  return object->id;
}

/* It sets the name of an object
 */
Status object_set_name(Object *object, char *name)
{
  if (!object || !name)
  {
    return ERROR;
  }

  if (!strcpy(object->name, name))
  {
    return ERROR;
  }
  return OK;
}

/* It gets the name of an object
 */
char *object_get_name(Object *object)
{
  if (!object)
  {
    return NULL;
  }
  return object->name;
}

/* It sets the gdesc of an object
 */
Status object_set_gdesc(Object *object, char *desc)
{
  if (!object || !desc)
  {
    return ERROR;
  }

  if (!strcpy(object->gdesc, desc))
  {
    return ERROR;
  }

  return OK;
}

/* It gets the gdesc of an object
 */
char *object_get_gdesc(Object *object)
{
  if (!object)
  {
    return NULL;
  }

  return object->gdesc;
}

/* It prints the object information
 */
Status object_print(Object *object)
{

  if (!object)
  {
    return ERROR;
  }

  /*Prints the id and name of the object*/

  fprintf(stdout, "--> Object (Id: %ld; Name: %s)\n", object->id, object->name);
  return OK;
}