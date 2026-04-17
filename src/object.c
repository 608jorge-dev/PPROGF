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
  Id id;                           /*!< Id number of the object, it must be unique */
  char name[WORD_SIZE + 1];        /*!< Name of the object */
  char description[WORD_SIZE + 1]; /*!< Description of the object */
  int health;                      /*!< Health field of the object */
  Bool movable;                    /*!< movable field of the object */
  Id dependency;                   /*!< dependency field of the object */
  Id open;                         /*!< open field of the object */
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
  newObject->description[0] = '\0';
  newObject->health = 0;
  newObject->movable = FALSE;
  newObject->dependency = NO_ID;
  newObject->open = NO_ID;

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

/* It sets the desc of an object
 */
Status object_set_desc(Object *object, char *desc)
{
  if (!object || !desc)
  {
    return ERROR;
  }

  if (!strcpy(object->description, desc))
  {
    return ERROR;
  }

  return OK;
}

/* It gets the desc of an object
 */
char *object_get_desc(Object *object)
{
  if (!object)
  {
    return NULL;
  }

  return object->description;
}

/* It sets the health value of an object
 */
Status object_set_health(Object *object, int health)
{
  if (!object)
  {
    return ERROR;
  }

  object->health = health;

  return OK;
}

/* It gets the health value of an object
 */
int object_get_health(Object *object)
{
  if (!object)
  {
    return NULL;
  }

  return object->health;
}

/* It sets the movable value of an object
 */
Status object_set_movable(Object *object, Bool movable)
{
  if (!object)
  {
    return ERROR;
  }

  object->movable = movable;

  return OK;
}

/* It gets the movable value of an object
 */
Bool object_get_movable(Object *object)
{
  if (!object)
  {
    return NULL;
  }

  return object->movable;
}

/* It sets the dependency value of an object
 */
Status object_set_dependency(Object *object, Id dependency_id)
{
  if (!object)
  {
    return ERROR;
  }

  object->dependency = dependency_id;

  return OK;
}

/* It gets the dependency value of an object
 */
Id object_get_dependency(Object *object)
{
  if (!object)
  {
    return NULL;
  }

  return object->dependency;
}

/* It sets the open value of an object
 */
Id object_set_open(Object *object, Id space_id)
{
  if (!object)
  {
    return ERROR;
  }

  object->open = space_id;

  return OK;
}

/* It gets the open value of an object
 */
Id object_get_open(Object *object)
{
  if (!object)
  {
    return NULL;
  }

  return object->open;
}

/* It prints the object information
 */
Status object_print(Object *object)
{

  if (!object)
  {
    return ERROR;
  }

  /*1. Prints the id and name of the object*/
  fprintf(stdout, "--> Object (Id: %ld; Name: %s)\n", object->id, object->name);

  /*2. Prints the health value of the object, the boolean value of the movable field, the id of the dependency and the id of the space it opens*/
  fprintf(stdout, "--> Health: %d, Movable: %d, Dependency: %d, Open: %d\n", object->health, object->movable, object->dependency, object->open);
  return OK;
}