/**
 * @brief It implements the game reader interface
 *
 * @file game_reader.c
 * @author Álvaro Bravo González
 * @version 0
 * @date 03-02-26
 * @copyright GNU Public License
 */

#include "game_reader.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
  Loads the spaces read on the .dat file
*/
Status game_reader_load_spaces(Game *game, char *filename)
{
  FILE *file = NULL;
  char line[WORD_SIZE] = "";
  char name[WORD_SIZE] = "";
  char g1[WORD_SIZE] = "", g2[WORD_SIZE] = "", g3[WORD_SIZE] = "", g4[WORD_SIZE] = "", g5[WORD_SIZE] = "";
  char *toks = NULL;
  Id id = NO_ID, north = NO_ID, east = NO_ID, south = NO_ID, west = NO_ID;
  Space *space = NULL;
  Status status = OK;

  if (!filename)
  {
    return ERROR;
  }

  file = fopen(filename, "r");
  if (file == NULL)
  {
    return ERROR;
  }

  while (fgets(line, WORD_SIZE, file))
  {
    if (strncmp("#s:", line, 3) == 0)
    {
      toks = strtok(line + 3, "|");
      id = atol(toks);
      toks = strtok(NULL, "|");
      strcpy(name, toks);
      toks = strtok(NULL, "|");
      north = atol(toks);
      toks = strtok(NULL, "|");
      east = atol(toks);
      toks = strtok(NULL, "|");
      south = atol(toks);
      toks = strtok(NULL, "|");
      west = atol(toks);
      toks = strtok(NULL, "|");
      strcpy(g1, toks);
      toks = strtok(NULL, "|");
      strcpy(g2, toks);
      toks = strtok(NULL, "|");
      strcpy(g3, toks);
      toks = strtok(NULL, "|");
      strcpy(g4, toks);
      toks = strtok(NULL, "|");
      strcpy(g5, toks);
#ifdef DEBUG
      printf("Leido: s:%ld|%s|%ld|%ld|%ld|%ld\n", id, name, north, east, south, west);
#endif
      space = space_create(id);
      if (space != NULL)
      {
        space_set_name(space, name);
        space_set_north(space, north);
        space_set_east(space, east);
        space_set_south(space, south);
        space_set_west(space, west);
        space_set_gdesc(space, 0, g1);
        space_set_gdesc(space, 1, g2);
        space_set_gdesc(space, 2, g3);
        space_set_gdesc(space, 3, g4);
        space_set_gdesc(space, 4, g5);
        game_add_space(game, space);
      }
    }
  }

  if (ferror(file))
  {
    status = ERROR;
    free(space);
  }

  fclose(file);

  return status;
}

/**
  Loads the objects read on the .dat file
*/
Status game_reader_load_objects(Game *game, char *filename)
{
  FILE *file = NULL;
  Object *object = NULL;
  char *toks = NULL;
  char line[WORD_SIZE] = "\0";
  char name[WORD_SIZE] = "\0";
  Id object_id = NO_ID, space_id = NO_ID;
  Status status = OK;

  if (!filename)
  {
    return ERROR;
  }

  file = fopen(filename, "r");
  if (file == NULL)
  {
    return ERROR;
  }

  while (fgets(line, WORD_SIZE, file))
  {
    if (strncmp("#o:", line, 3) == 0)
    {
      toks = strtok(line + 3, "|");
      object_id = atol(toks);

      toks = strtok(NULL, "|");
      strcpy(name, toks);

      toks = strtok(NULL, "|");
      if (toks)
        space_id = atol(toks);

      object = object_create(object_id);
      if (object != NULL)
      {
        object_set_name(object, name);
        game_add_object(game, object);
        game_set_object_location(game, space_id, object_id);
      }
    }
  }
#ifdef DEBUG
  printf("Leido: o:%ld|%s|%ld\n", object_id, name, space_id);
#endif

  if (ferror(file))
  {
    status = ERROR;
    free(object);
  }
  fclose(file);

  return status;
}

/**
  Loads the characters read on the .dat file
*/
Status game_reader_load_characters(Game *game, char *filename)
{
  FILE *file = NULL;
  Character *character = NULL;
  char *toks = NULL;
  char line[WORD_SIZE] = "\0";
  char name[WORD_SIZE] = "\0";
  char gdesc[WORD_SIZE] = "\0";
  char message[WORD_SIZE] = "\0";
  Id character_id = NO_ID, space_id = NO_ID;
  Status status = OK;
  int health = 0;
  Bool friendly = TRUE;

  if (!filename)
  {
    return ERROR;
  }

  file = fopen(filename, "r");
  if (file == NULL)
  {
    return ERROR;
  }

  while (fgets(line, WORD_SIZE, file))
  {
    if (strncmp("#c:", line, 3) == 0)
    {
      toks = strtok(line + 3, "|");
      character_id = atol(toks);
      toks = strtok(NULL, "|");
      strcpy(name, toks);
      toks = strtok(NULL, "|");
      strcpy(gdesc, toks);
      toks = strtok(NULL, "|");
      health = atol(toks);
      toks = strtok(NULL, "|");
      friendly = atol(toks);
      toks = strtok(NULL, "|");
      strcpy(message, toks);

      toks = strtok(NULL, "|");
      space_id = atol(toks);
      character = character_create(character_id);
      if (character != NULL)
      {
        character_set_name(character, name);
        character_set_gdesc(character, gdesc);
        character_set_health(character, health);
        character_set_friendly(character, friendly);
        character_set_message(character, message);
        game_add_character(game, character);
        game_set_character_location(game, space_id, character_id);
      }
    }
  }
#ifdef DEBUG
  printf("Leido: o:%ld|%s|%ld\n", object_id, name, space_id);
#endif

  if (ferror(file))
  {
    status = ERROR;
    free(character);
  }
  fclose(file);

  return status;
}

/** It creates a new game data structure, allocating memory and initializing its members starting from the .dat file
 */
Status game_reader_create_from_file(Game *game, char *filename)
{
  if (game_reader_load_spaces(game, filename) == ERROR)
  {
    return ERROR;
  }

  if (game_reader_load_objects(game, filename) == ERROR)
  {
    return ERROR;
  }

  if (game_reader_load_characters(game, filename) == ERROR)
  {
    return ERROR;
  }

  /* The player and the object are located in the first space */
  game_set_player_location(game, game_get_space_id_at(game, 0));
  return OK;
}