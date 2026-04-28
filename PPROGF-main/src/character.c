/**
 * @brief It implements the character module
 *
 * @file character.c
 * @author Álvaro Bravo González, Jorge Torrijos de la Cruz
 * @version 7.0
 * @date 28-04-2026
 * @copyright GNU Public License
 */

#include "character.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Character
 *
 * This struct stores all the information related to a character.
 */
struct _Character
{
  Id id;                       /*!< Id number of the character, it must be unique */
  char name[WORD_SIZE + 1];    /*!< Name of the character */
  char gdesc[WORD_SIZE + 1];   /*!< Description of the character */
  int health;                  /*!< Amount of health the character has */
  Bool friendly;               /*!< Wether the character is friendly or not */
  char message[WORD_SIZE + 1]; /*!< The message the character says */
  Id following;                /*!< The id of the player the character follows */
};

/* It creates a new character, allocating memory and initializing its members */
Character *character_create(Id id)
{
  Character *newCharacter = NULL;

  if (id == NO_ID)
  {
    return NULL;
  }

  newCharacter = (Character *)calloc(1, sizeof(Character));
  if (newCharacter == NULL)
  {
    return NULL;
  }

  /* Initialization of an empty character*/
  newCharacter->id = id;
  newCharacter->name[0] = '\0';
  newCharacter->gdesc[0] = '\0';
  newCharacter->health = '0';
  newCharacter->friendly = TRUE;
  newCharacter->message[0] = '\0';
  newCharacter->following = NO_ID;

  return newCharacter;
}

/* It destroys a character, freeing the allocated memory */
Status character_destroy(Character *character)
{
  if (!character)
  {
    return ERROR;
  }

  free(character);
  return OK;
}

/* It sets the id of a character */
Status character_set_id(Character *character, Id id)
{
  if (!character || id == NO_ID)
  {
    return ERROR;
  }

  character->id = id;

  return OK;
}

/* It gets the id of a character */
Id character_get_id(Character *character)
{
  if (!character)
  {
    return NO_ID;
  }

  return character->id;
}

/* It sets the name of a character */
Status character_set_name(Character *character, char *name)
{
  if (!character || !name)
  {
    return ERROR;
  }

  if (!strcpy(character->name, name))
  {
    return ERROR;
  }

  return OK;
}

/* It gets the character name */
char *character_get_name(Character *character)
{
  if (!character)
  {
    return NULL;
  }

  return character->name;
}

/* It sets the gdesc of a character */
Status character_set_gdesc(Character *character, char *gdesc)
{
  if (!character || !gdesc)
  {
    return ERROR;
  }

  if (!strcpy(character->gdesc, gdesc))
  {
    return ERROR;
  }

  return OK;
}

/* It gets the character gdesc */
const char *character_get_gdesc(Character *character)
{
  if (!character)
  {
    return NULL;
  }

  return character->gdesc;
}

/* It sets the health of a character */
Status character_set_health(Character *character, int health)
{
  if (!character)
  {
    return ERROR;
  }

  character->health = health;

  return OK;
}

/* It gets the health of a character */
int character_get_health(Character *character)
{
  if (!character)
  {
    return NO_ID;
  }

  return character->health;
}

/* It sets the friendly status of a character*/
Status character_set_friendly(Character *character, Bool friendly)
{
  if (!character)
  {
    return ERROR;
  }

  character->friendly = friendly;

  return OK;
}

/* It gets the friendly status of a character */
Bool character_get_friendly(Character *character)
{
  if (!character)
  {
    return FALSE;
  }

  return character->friendly;
}

/* It sets the message of a character */
Status character_set_message(Character *character, char *msg)
{
  if (!character || !msg)
  {
    return ERROR;
  }

  if (!strcpy(character->message, msg))
  {
    return ERROR;
  }

  return OK;
}

/* It gets the character msg */
char *character_get_message(Character *character)
{
  if (!character)
  {
    return NULL;
  }

  return character->message;
}

/* It sets the id of the player the character follows */
Status character_set_following(Character *character, Id following)
{
  if (!character || following == NO_ID)
  {
    return ERROR;
  }

  character->following = following;

  return OK;
}

/* It gets the id of the player the character follows */
Id character_get_following(Character *character)
{
  if (!character)
  {
    return NO_ID;
  }

  return character->following;
}

/* It prints the character information */
Status character_print(Character *character)
{
  /* Error Control */
  if (!character)
  {
    return ERROR;
  }

  /* 1. Print the id and the name of the character */
  fprintf(stdout, "--> Character (Id: %ld; Name: %s)\n", character_get_id(character), character_get_name(character));

  /* 2. Print the character's description */
  fprintf(stdout, "---> Description: %s.\n", character_get_gdesc(character));

  /* 3. Print the character's health */
  fprintf(stdout, "---> Health: %d.\n", character_get_health(character));

  /* 4. Print if the character is friendly or not */
  if (character_get_friendly(character) == TRUE)
  {
    fprintf(stdout, "---> The character is friendly\n");
  }
  else
  {
    fprintf(stdout, "---> The character is not friendly\n");
  }

  /* 5. Print if the character is following a player or not */
  if (character_get_following(character) != NO_ID)
  {
    fprintf(stdout, "---> The character is following player %ld\n", character_get_following(character));
  }
  else
  {
    fprintf(stdout, "---> The character is not following any player\n");
  }

  /* 5. Print the character's message */
  fprintf(stdout, "---> Message: %s.\n", character_get_message(character));

  return OK;
}