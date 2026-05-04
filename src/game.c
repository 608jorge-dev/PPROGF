/**
 * @brief It implements the game structure
 *
 * @file game.c
 * @author Álvaro Bravo González, Guillermo Núñez Bravo, Iván Rodríguez Camacho, Jorge Torrijos de la Cruz
 * @version 7.0
 * @date 28-04-2026
 * @copyright GNU Public License
 */

#include "game.h"
#include "game_management.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Game
 *
 * This struct stores all the information related to a game.
 */
struct _Game
{
  Player *players[MAX_OBJECTS];          /*!< Player structure pointer */
  int n_players;                         /*!< Total amount of players created */
  Playerinf *playerinf[MAX_PLAYERS];     /*!< Player info structure pointer */
  int dead_players;                      /*!< Total amount of dead players */
  Object *objects[MAX_OBJECTS];          /*!< Object structure pointer */
  int n_objects;                         /*!< Total amount of objects created */
  Space *spaces[MAX_SPACES];             /*!< Space structure pointer */
  int n_spaces;                          /*!< Total amount of spaces created */
  Character *characters[MAX_CHARACTERS]; /*!< Character structure pointer */
  int n_characters;                      /*!< Total amount of characters created */
  Link *links[MAX_LINKS];                /*!< Link structure pointer */
  int n_links;                           /*!< Total amount of links created */
  Command *last_cmd;                     /*!< Command structure pointer */
  Bool finished;                         /*!< States the finished status in the game */
  int turn;                              /*!< Indicates actual turn */
  Bool deterministic;                    /*!< Indicates if game its deterministic or not */
};

/* It creates a new game, allocating memory
 * and initializing its members 
 */
Game *game_create()
{
  Game *game = NULL;
  int i;

  game = (Game *)malloc(sizeof(Game) * 1);
  if (!game)
  {
    return NULL;
  }

  for (i = 0; i < MAX_PLAYERS; i++)
  {
    game->players[i] = NULL;
  }
  game->n_players = 0;

  for (i = 0; i < MAX_PLAYERS; i++)
  {
    game->playerinf[i] = playerinf_create(i);
  }

  for (i = 0; i < MAX_OBJECTS; i++)
  {
    game->objects[i] = NULL;
  }
  game->n_objects = 0;

  for (i = 0; i < MAX_SPACES; i++)
  {
    game->spaces[i] = NULL;
  }
  game->n_spaces = 0;

  for (i = 0; i < MAX_CHARACTERS; i++)
  {
    game->characters[i] = NULL;
  }
  game->n_characters = 0;

  for (i = 0; i < MAX_LINKS; i++)
  {
    game->links[i] = NULL;
  }
  game->n_links = 0;

  game->last_cmd = command_create();
  game->finished = FALSE;
  game->turn = 0;
  game->dead_players = 0;

  return game;
}

/* It destroys a game structure, freeing the allocated memory
 */
Status game_destroy(Game *game)
{
  int i = 0;

  for (i = 0; i < game->n_players; i++)
  {
    player_destroy(game->players[i]);
  }

  for (i = 0; i < MAX_PLAYERS; i++)
  {
    playerinf_destroy(game->playerinf[i]);
  }

  for (i = 0; i < game->n_objects; i++)
  {
    object_destroy(game->objects[i]);
  }

  for (i = 0; i < game->n_spaces; i++)
  {
    space_destroy(game->spaces[i]);
  }

  for (i = 0; i < game->n_characters; i++)
  {
    character_destroy(game->characters[i]);
  }

  for (i = 0; i < game->n_links; i++)
  {
    link_destroy(game->links[i]);
  }

  command_destroy(game->last_cmd);

  free(game);

  return OK;
}

/* PLAYER FUNCTIONS : */

/*It sets the pointer to a player structure
 */
Status game_set_player(Game *game, Player *player)
{
  if (!game)
  {
    return ERROR;
  }

  if (!player)
  {
    return ERROR;
  }

  game->players[game->turn] = player;

  return OK;
}

/* It gets the pointer to a player structure
 */
Player *game_get_player(Game *game)
{
  if (!game)
  {
    return ERROR;
  }

  return game->players[game_get_turn(game)];
}

/* It adds a player to the game player pointer
 */
Status game_add_player(Game *game, Player *player)
{
  int aux_n_players;

  if (!game || !player || game_get_n_players(game) == MAX_PLAYERS)
  {
    return ERROR;
  }

  aux_n_players = game_get_n_players(game);

  game->players[aux_n_players] = player;
  game_set_n_players(game, game_get_n_players(game) + 1);

  return OK;
}

/* It gets a player from its position in the player array
 */
Player *game_get_player_at(Game *game, int position)
{

  if (!game || position < 0 || position >= game_get_n_players(game))
  {
    return NULL;
  }

  return game->players[position];
}

/* It gets a player from its id in the player array
 */
Player *game_get_player_with_id(Game *game, Id id)
{
  int i;
  if (!game || id == NO_ID)
  {
    return NULL;
  }

  for (i = 0; i < game->n_players; i++)
  {
    if (player_get_id(game->players[i]) == id)
    {
      return game->players[i];
    }
  }

  return NULL;
}

/* It sets the location of a player
 */
Status game_set_player_location(Game *game, Id id)
{
  if (!game || id == NO_ID)
  {
    return ERROR;
  }

  player_set_location(game->players[game_get_turn(game)], id);

  return OK;
}

/* It gets the location of a player
 */
Id game_get_player_location(Game *game)
{
  if (!game)
  {
    return NO_ID;
  }

  return player_get_location(game->players[game_get_turn(game)]);
}

/* It sets the amount of players
 */
Status game_set_n_players(Game *game, int amount)
{
  if (!game || amount < 0)
  {
    return ERROR;
  }

  game->n_players = amount;

  return OK;
}

/* It gets the amount of players
 */
int game_get_n_players(Game *game)
{
  if (!game)
  {
    return -1;
  }

  return game->n_players;
}

/*It sets the amount of dead players
 */
Status game_set_dead_players(Game *game, int amount)
{
  if (!game || amount < 0)
  {
    return ERROR;
  }

  game->dead_players = amount;

  return OK;
}

/* It gets the amount of dead players
 */
int game_get_dead_players(Game *game)
{
  if (!game)
  {
    return -1;
  }

  return game->dead_players;
}

/* PLAYERINF FUNCTIONS : */

/* It gets the pointer to a player's information structure
 */
Playerinf *game_get_playerinf(Game *game)
{
  if (!game)
  {
    return ERROR;
  }

  return game->playerinf[game_get_turn(game)];
}

/* OBJECT FUNCTIONS : */

/* It adds the object to the game objects pointer
 */
Status game_add_object(Game *game, Object *object)
{
  int aux_n_objects;

  if (!game || !object || game_get_n_objects(game) == MAX_OBJECTS)
  {
    return ERROR;
  }

  aux_n_objects = game_get_n_objects(game);

  game->objects[aux_n_objects] = object;
  game_set_n_objects(game, aux_n_objects + 1);

  return OK;
}

/* It gets an object from its position in the object array
 */
Object *game_get_object_at(Game *game, int position)
{
  if (!game || position < 0 || position >= game_get_n_objects(game))
  {
    return NULL;
  }

  return game->objects[position];
}

/* It gets an object from its id in the objects array
 */
Object *game_get_object_with_id(Game *game, Id id)
{
  int i;

  if (!game || id == NO_ID)
  {
    return NULL;
  }

  for (i = 0; i < id; i++)
  {
    if (object_get_id(game->objects[i]) == id)
    {
      return game->objects[i];
    }
  }

  return NULL;
}

/* It sets the location of an object
 */
Status game_set_object_location(Game *game, Id space_id, Id object_id)
{
  int i;

  if (!game || space_id == NO_ID || object_id == NO_ID)
  {
    return ERROR;
  }

  for (i = 0; i < game->n_spaces; i++)
  {
    if (space_get_id(game->spaces[i]) == space_id)
    {
      space_add_object(game->spaces[i], object_id);
      return OK;
    }
  }

  return ERROR;
}

/* It gets the location of an object
 */
Id game_get_object_location(Game *game, Id object_id)
{
  int i;

  if (!game || object_id == NO_ID)
  {
    return NO_ID;
  }

  for (i = 0; i < game->n_objects; i++)
  {
    if (space_find_object(game->spaces[i], object_id))
    {
      return space_get_id(game->spaces[i]);
    }
  }

  return NO_ID;
}

/* It sets the amount of objects
 */
Status game_set_n_objects(Game *game, int amount)
{
  if (!game || amount < 0)
  {
    return ERROR;
  }

  game->n_objects = amount;

  return OK;
}

/* It gets the amount of objects
 */
int game_get_n_objects(Game *game)
{
  if (!game)
  {
    return 0;
  }

  return game->n_objects;
}

/* CHARACTER FUNCTIONS : */

/** Creates more spaces at the end of the allocated pointer when called */
Status game_add_character(Game *game, Character *character)
{
  if (!game || !character)
  {
    return ERROR;
  }

  game->characters[game->n_characters] = character;
  game->n_characters++;

  return OK;
}

/** It gets the character from an id */
Character *game_get_character_with_id(Game *game, Id id)
{
  int i;

  if (!game || id == NO_ID)
  {
    return NULL;
  }

  for (i = 0; i < id; i++)
  {
    if (character_get_id(game->characters[i]) == id)
    {
      return game->characters[i];
    }
  }

  return NULL;
}

/** It gets the character from its position */
Character *game_get_character_at(Game *game, int position)
{
  if (!game || position < 0 || position >= game_get_n_characters(game))
  {
    return NULL;
  }

  return game->characters[position];
}

/** It sets the character's location */
Status game_set_character_location(Game *game, Id space_id, Id character_id)
{
  Space *space;

  if (!game || space_id == NO_ID || character_id == NO_ID)
  {
    return ERROR;
  }

  space = game_get_space(game, space_id);
  if (!space)
  {
    return ERROR;
  }

  space_add_character(space, character_id);

  return OK;
}

/** It gets the id of the character's location */
Id game_get_character_location(Game *game, Id character_id)
{
  int i;

  if (!game || character_id == NO_ID)
  {
    return NO_ID;
  }

  for (i = 0; i < game->n_spaces; i++)
  {
    if (space_find_character(game->spaces[i], character_id) == TRUE)
    {
      return space_get_id(game->spaces[i]);
    }
  }
  return NO_ID;
}

/** It sets n_characters */
Status game_set_n_characters(Game *game, int number)
{
  if (!game)
  {
    return ERROR;
  }

  game->n_characters = number;

  return OK;
}

/** It gets the number of characters*/
int game_get_n_characters(Game *game)
{
  if (!game)
  {
    return ERROR;
  }

  return game->n_characters;
}

/* SPACE FUNCTIONS : */

/** It gets the spaces */
Space *game_get_space(Game *game, Id space_id)
{
  int i = 0;

  if (!game || space_id == NO_ID)
  {
    return NULL;
  }

  for (i = 0; i < game->n_spaces; i++)
  {
    if (space_id == space_get_id(game->spaces[i]))
    {
      return game->spaces[i];
    }
  }

  return NULL;
}

Space *game_get_space_at(Game *game, int position)
{
  if (!game || position < 0)
  {
    return NULL;
  }

  return game->spaces[position];
}

/** It gets the id from a space */
Id game_get_space_id_at(Game *game, int position)
{
  if (!game || position < 0 || position >= game_get_n_spaces(game))
  {
    return NO_ID;
  }

  return space_get_id(game->spaces[position]);
}

/** It gets the character from an id */
Space *game_get_space_with_id(Game *game, Id id)
{
  int i;

  if (!game || id == NO_ID)
  {
    return NULL;
  }

  for (i = 0; i < id; i++)
  {
    if (space_get_id(game->spaces[i]) == id)
    {
      return game->spaces[i];
    }
  }

  return NULL;
}

/** Creates more spaces at the end of the allocated pointer when called */
Status game_add_space(Game *game, Space *space)
{
  if (!game || !space || (game_get_n_spaces(game) >= MAX_SPACES))
  {
    return ERROR;
  }

  game->spaces[game->n_spaces] = space;
  game->n_spaces++;

  return OK;
}

/** It sets n_spaces */
Status game_set_n_spaces(Game *game, int number)
{
  if (!game)
  {
    return ERROR;
  }

  game->n_spaces = number;

  return OK;
}

/** It gets n_spaces */
int game_get_n_spaces(Game *game)
{
  if (!game)
  {
    return 0;
  }

  return game->n_spaces;
}

/** It sets last command
 */
Status game_set_last_command(Game *game, Command *command)
{
  if (!game)
  {
    return ERROR;
  }

  game->last_cmd = command;

  return OK;
}

/** It gets last command
 */
Command *game_get_last_command(Game *game)
{
  if (!game)
  {
    return NULL;
  }

  return game->last_cmd;
}

/** It sets the finished status
 */
Status game_set_finished(Game *game, Bool finished)
{
  if (!game)
  {
    return ERROR;
  }

  game->finished = finished;

  return OK;
}

/** It gets whether the game finishes or not
 */
Bool game_get_finished(Game *game)
{
  return game->finished;
}

/* LINK FUNCTIONS : */

Id game_get_connection(Game *game, Id actual_space, Direction link_dir)
{
  int i;
  if (!game || actual_space == NO_ID || link_dir > 5 || link_dir < 0)
  {
    return NO_ID;
  }

  for (i = 0; i < game->n_links; i++)
  {
    if ((link_get_origin(game->links[i]) == actual_space) && (link_get_direction(game->links[i]) == link_dir))
    {
      return link_get_destination(game->links[i]);
    }
  }

  return NO_ID;
}

Bool game_connection_is_open(Game *game, Id actual_space, Direction link_dir)
{
  int i;
  if (!game || actual_space == NO_ID || link_dir > 5 || link_dir < 0)
  {
    return FALSE;
  }

  for (i = 0; i < game->n_links; i++)
  {
    if (link_get_origin(game->links[i]) == actual_space && link_get_direction(game->links[i]) == link_dir)
    {
      return link_get_open(game->links[i]);
    }
  }
  return FALSE;
}

Link *game_get_link_with_id(Game *game, Id id)
{
  int i;
  Id temp;
  if (!game || id == NO_ID)
  {
    return NULL;
  }

  for (i = 0; i < game->n_links; i++)
  {
    temp = link_get_id(game->links[i]);
    if (temp == id)
    {
      return game->links[i];
    }
  }

  return NULL;
}

/* It adds the link to the game links pointer */
Status game_add_link(Game *game, Link *link)
{

  if (!game || !link || game_get_n_links(game) == MAX_LINKS)
  {
    return ERROR;
  }

  game->links[game->n_links] = link;
  game->n_links++;

  return OK;
}

/*It sets the amount of links */
Status game_set_n_links(Game *game, int amount)
{
  if (!game || amount < 0)
  {
    return ERROR;
  }

  game->n_links = amount;

  return OK;
}

/* It gets the amount of links */
int game_get_n_links(Game *game)
{
  if (!game)
  {
    return 0;
  }

  return game->n_links;
}

/** It gets the link from its position */
Link *game_get_link_at(Game *game, int position)
{
  if (!game || position < 0 || position >= game_get_n_objects(game))
  {
    return NULL;
  }

  return game->links[position];
}

/*It sets the actual turn */
Status game_set_turn(Game *game, int turn)
{
  if (!game || turn < 0)
  {
    return ERROR;
  }

  game->turn = turn;

  return OK;
}

/*It gets the actual turn */
int game_get_turn(Game *game)
{
  if (!game)
  {
    return -1;
  }

  return game->turn;
}

/*It sets next turn */
Status game_next_turn(Game *game)
{
  if (!game)
  {
    return ERROR;
  }

  game->turn++;
  if (game_get_turn(game) == game_get_n_players(game))
  {
    game_set_turn(game, 0);
  }

  return OK;
}

/*It gets the discovered object*/
Bool game_get_object_discovered(Game *game, Id object_id)
{
  if (object_id == NO_ID)
  {
    return FALSE;
  }

  if (space_get_discovered(game_get_space(game, game_get_object_location(game, object_id))) == TRUE)
  {
    return TRUE;
  }

  return FALSE;
}

Bool game_get_character_discovered(Game *game, Id char_id)
{
  if (char_id == NO_ID)
  {
    return FALSE;
  }

  if (space_get_discovered(game_get_space(game, game_get_character_location(game, char_id))) == TRUE)
  {
    return TRUE;
  }

  return FALSE;
}

Status game_set_deterministic(Game *game, Bool deterministic)
{
  if (game == NULL)
  {
    return ERROR;
  }

  game->deterministic = deterministic;
  return OK;
}

Bool game_get_deterministic(Game *game)
{
  if (game == NULL)
  {
    return FALSE;
  }

  if (game->deterministic == 1)
  {
    return TRUE;
  }

  return FALSE;
}

/** It prints the game information
 */
void game_print(Game *game)
{
  int i = 0;

  printf("\n\n-------------\n\n");

  printf("=> Spaces: \n");
  for (i = 0; i < game->n_spaces; i++)
  {
    space_print(game->spaces[i]);
  }

  printf("=> Objects: ");
  for (i = 0; i < MAX_OBJECTS; i++)
  {
    object_print(game->objects[i]);
  }

  printf("\n");
  player_print(game->players[game->turn]);
  printf("\n");
  printf("\n");
  character_print(game->characters[0]);
  printf("\n");
}
