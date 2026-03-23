/**
 * @brief It implements the player module
 *
 * @file player.c
 * @author Jorge Torrijos de la Cruz
 * @version 0
 * @date 03-02-2026
 * @copyright GNU Public License
 */

#include "player.h"


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Player
 *
 * This struct stores all the information of a player.
 */
struct _Player
{
  Id id;                     /*!< Id number of the player, it must be unique */
  char name[WORD_SIZE + 1];  /*!< Name of the player */
  Id location;               /*!< Id of player's location */
  Inventory *objects;        /*!< Set of the player object's */
  int n_objects;             /*!< Total amount of objects created */
  int health;                /*!< Amount of health the player has */
  char gdesc[WORD_SIZE + 1]; /*!< Description of the lpayer */
};

/* It creates a new player, allocating memory
 *and initializing its members
 */
Player *player_create(Id id)
{
  Player *newPlayer = NULL;
  if (id == NO_ID)
  {
    return NULL;
  }
  newPlayer = (Player *)calloc(1, sizeof(Player));
  if (newPlayer == NULL)
  {
    return NULL;
  }
  /* Initialization of an empty player*/
  newPlayer->id = id;
  newPlayer->name[0] = '\0';
  newPlayer->location = NO_ID;
  newPlayer->objects = inventory_create();
  newPlayer->n_objects = 0;
  newPlayer->health = 4;
  newPlayer->gdesc[0] = '^';
  newPlayer->gdesc[1] = 'C';
  newPlayer->gdesc[2] = '>';

  return newPlayer;
}

/* It destroys a player, freeing the allocated memory
 */
Status player_destroy(Player *player)
{
  if (!player)
  {
    return ERROR;
  }

  free(player);
  return OK;
}

/* It sets the id of a player
 */
Status player_set_id(Player *player, Id id)
{
  if (!player)
  {
    return ERROR;
  }
  player->id = id;
  return OK;
}

/* It gets the id of a player
 */
Id player_get_id(Player *player)
{
  if (!player)
  {
    return NO_ID;
  }
  return player->id;
}

/* It sets the name of a player
 */
Status player_set_name(Player *player, char *name)
{
  if (!player || !name)
  {
    return ERROR;
  }

  if (!strcpy(player->name, name))
  {
    return ERROR;
  }
  return OK;
}

/* It gets the player name
 */
const char *player_get_name(Player *player)
{
  if (!player)
  {
    return NULL;
  }

  return player->name;
}

/*It set the id of a player's location
 */
Status player_set_location(Player *player, Id location)
{
  if (!player)
  {
    return ERROR;
  }
  player->location = location;
  return OK;
}

/* It gets the player location
 */
Id player_get_location(Player *player)
{
  if (!player)
  {
    return NO_ID;
  }
  return player->location;
}

/** It adds the object to the game objects pointer
 */
Status player_add_object(Player *player, Id id)
{
  if (!player || !player_get_objects(player) || inventory_get_max_objs(player_get_objects(player)) == MAX_OBJECTS)
  {
    return ERROR;
  }

  if(inventory_add_object(player_get_objects(player), id) == ERROR )
  {
     return ERROR;
  }

  return OK;
}

/** It deletes the object from the game objects pointer
 */
Status player_del_object(Player *player, Id id)
{
  Inventory *objects;
  int n_invents;

  if (!player || id == NO_ID)
  {
    return ERROR;
  }

  objects = player_get_objects(player);
  if (!objects)
  {
    return ERROR;
  }

  /*n_invents = set_get_n_ids(objects);  */
   n_invents = inventory_get_max_objs(objects);
  if (n_invents == 0)
  {
    return ERROR;
  }

  if(inventory_del_object(objects, id)==ERROR)
  {
     return ERROR;
  }

  return OK;
}

/* It finds the object in the player inventory
 */
Bool player_find_object(Player *player, Id id)
{
  Inventory *objects;
  int location;

  if (!player || id == NO_ID)
  {
    return FALSE;
  }

  objects = player_get_objects(player);
  if (!objects)
  {
    return FALSE;
  }

  location = inventory_find_object(objects, id);

  if (location != -1)
  {
    return TRUE;
  }

  return FALSE;
}

/* It gets the player objects
 */
Inventory* player_get_objects(Player *player)
{
  if (!player)
  {
    return NULL;
  }

  return player->objects;
}

/* It sets the health of a player
 */
Status player_set_health(Player *player, int health)
{
  if (!player)
  {
    return ERROR;
  }
  player->health = health;
  return OK;
}

/* It gets the health of a player
 */
int player_get_health(Player *player)
{
  if (!player)
  {
    return NO_ID;
  }

  return player->health;
}

/* It sets the gdesc of a player
 */
Status player_set_gdesc(Player *player, char *gdesc)
{
  if (!player || !gdesc)
  {
    return ERROR;
  }

  if (!strcpy(player->gdesc, gdesc))
  {
    return ERROR;
  }
  return OK;
}

/* It gets the player gdesc
 */
const char *player_get_gdesc(Player *player)
{
  if (!player)
  {
    return NULL;
  }

  return player->gdesc;
}

/* It prints the player information
 */
Status player_print(Player *player)
{
  Id idaux = NO_ID;

  /* Error Control */
  if (!player)
  {
    return ERROR;
  }

  /* 1. Print the id and the name of the player */
  fprintf(stdout, "--> Player (Id: %ld; Name: %s)\n", player->id, player->name);

  /* 2. Print the player's location */
  idaux = player_get_location(player);
  fprintf(stdout, "---> Location: %ld.\n", idaux);

  /* 3. Print the objects in the player or not */
  if (inventory_get_max_objs(player->objects) > 0)
  {
    inventory_print(player->objects);
  }
  else
  {
    fprintf(stdout, "---> Space has no objects.");
  }
  /* 4. Print the player's health */
  fprintf(stdout, "---> Health: %d.\n", player_get_health(player));

  /* 5. Print the player's gdesc */
  fprintf(stdout, "---> Message: %s.\n", player_get_gdesc(player));

  return OK;
}