/**
 * @brief It defines the game interface
 *
 * @file game.h
 * @author Profesores PPROG
 * @version 0
 * @date 27-01-2025
 * @copyright GNU Public License
 */

#ifndef GAME_H
#define GAME_H

#include "command.h"
#include "player.h"
#include "object.h"
#include "space.h"
#include "character.h"
#include "link.h"
#include "types.h"
#include "inventory.h"
#include "playerinf.h"

/**Game structure type definition
 */
typedef struct _Game Game;

/**
 * @brief It creates a new game, allocating memory and initializing its members
 * @author Profesores PPROG
 *
 * @return A pointer to the game structure
 */
Game *game_create();

/**
 * @brief It destroys a game structure, freeing the allocated memory
 * @author Profesores PPROG
 *
 * @param game A pointer to the game data
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status game_destroy(Game *game);

/* PLAYER FUNCTIONS : */

/**
 * @brief It sets player pointer
 * @author Jorge Torrijos de la Cruz
 *
 * @param game A pointer to the game data
 * @param player A pointer to the allocated memory for the player
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status game_set_player(Game *game, Player *player);

/**
 * @brief It gets the player pointer
 * @author Jorge Torrijos de la Cruz
 *
 * @param game A pointer to the game data
 * @return A pointer to the player structure
 */
Player *game_get_player(Game *game);

/**
 * @brief It adds the player to the game player pointer
 * @author Guillermo Nuñez Bravo
 *
 * @param game A pointer to the game data
 * @param player A pointer to the allocated memory for the player
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status game_add_player(Game *game, Player *player);

/**
 * @brief It gets Player from its position
 * @author Ivan Rodriguez
 *
 * @param game A pointer to the game data
 * @param position The position of the player in the player array
 * @return A pointer to the Player structure
 */
Player *game_get_player_at(Game *game, int position);

/**
 * @brief It gets Player from with the id
 * @author Ivan Rodriguez
 *
 * @param game A pointer to the game data
 * @param id The id of the player in the player array
 * @return A pointer to the Player structure
 */
Player *game_get_player_with_id(Game *game, Id id);

/**
 * @brief It sets the player's location
 * @author Álvaro Bravo González
 *
 * @param game A pointer to the game data
 * @param id The identification number for the location of the player
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status game_set_player_location(Game *game, Id id);

/**
 * @brief It gets the id of the player's location
 * @author Álvaro Bravo González
 *
 * @param game A pointer to game
 * @return The id of the player's location
 */
Id game_get_player_location(Game *game);

/**
 * @brief It sets the amount of players
 * @author Guillermo Nuñez Bravo
 *
 * @param game A pointer to the game data
 * @param amount The new quantity of players
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status game_set_n_players(Game *game, int amount);

/**
 * @brief It gets the amount of players
 * @author Guillermo Nuñez Bravo
 *
 * @param game A pointer to the game data
 * @return The quantity of players
 */
int game_get_n_players(Game *game);

/* PLAYERINF FUNCTIONS : */

/**
 * @brief It gets the playerinf pointer
 * @author Jorge Torrijos de la Cruz
 *
 * @param game A pointer to the game data
 * @return A pointer to the playerinf structure
 */
Playerinf *game_get_playerinf(Game *game);

/**
 * @brief It sets the amount of  dead players
 * @author Jorge Torrijos de la Cruz
 *
 * @param game A pointer to the game data
 * @param amount The amount of dead players
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status game_set_dead_players(Game *game, int amount);

/**
 * @brief It gets the amount of dead players
 * @author Jorge Torrijos de la Cruz
 *
 * @param game A pointer to the game data
 * @return The number of dead players
 */
int game_get_dead_players(Game *game);

/* OBJECT FUNCTIONS : */

/**
 * @brief It adds the object to the game objects pointer
 * @author Jorge Torrijos de la Cruz
 *
 * @param game A pointer to the game data
 * @param object A pointer to the allocated memory for the object
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status game_add_object(Game *game, Object *object);

/**
 * @brief It gets the object from an id
 * @author Jorge Torrijos de la Cruz
 *
 * @param game A pointer to the game data
 * @param id The id of the object
 * @return A pointer to the object structure
 */
Object *game_get_object_with_id(Game *game, Id id);

/**
 * @brief It gets the object from its position
 * @author Álvaro Bravo González
 *
 * @param game A pointer to the game data
 * @param position The position of the object in the object array
 * @return A pointer to the object structure
 */
Object *game_get_object_at(Game *game, int position);

/**
 * @brief It sets the object's location
 * @author Jorge Torrijos de la Cruz
 *
 * @param game A pointer to the game data
 * @param space_id The identification number for the space of the object
 * @param object_id The identification number for the location of the object
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status game_set_object_location(Game *game, Id space_id, Id object_id);

/**
 * @brief It gets the id of the object's location
 * @author Jorge Torrijos de la Cruz
 *
 * @param game A pointer to the game data
 * @param object_id The object id
 * @return the id of the object's location
 */
Id game_get_object_location(Game *game, Id object_id);

/**
 * @brief It sets the amount of objects
 * @author Jorge Torrijos de la Cruz
 *
 * @param game A pointer to the game data
 * @param amount The new quantity of objects
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status game_set_n_objects(Game *game, int amount);

/**
 * @brief It gets the amount of objects
 * @author Jorge Torrijos de la Cruz
 *
 * @param game A pointer to the game data
 * @return The quantity of objects
 */
int game_get_n_objects(Game *game);

/* CHARACTER FUNCTIONS : */

/**
 * @brief It adds the character to the game character pointer
 * @author Guillermo Nuñez Bravo
 *
 * @param game A pointer to the game data
 * @param character A pointer to the allocated memory for the character
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status game_add_character(Game *game, Character *character);

/**
 * @brief It gets the character from an id
 * @author Jorge Torrijos de la Cruz
 *
 * @param game A pointer to the game data
 * @param id The id of the character
 * @return A pointer to the character structure
 */
Character *game_get_character_with_id(Game *game, Id id);

/**
 * @brief It gets the character from its position
 * @author Álvaro Bravo González
 *
 * @param game A pointer to the game data
 * @param position The position of the character in the character array
 * @return A pointer to the character structure
 */
Character *game_get_character_at(Game *game, int position);

/**
 * @brief It sets the character's location
 * @author Jorge Torrijos de la Cruz
 *
 * @param game A pointer to the game data
 * @param space_id The identification number for the space of the object
 * @param character_id The identification number for the location of the character
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status game_set_character_location(Game *game, Id space_id, Id character_id);

/**
 * @brief It gets the id of the character's location
 * @author Jorge Torrijos de la Cruz
 *
 * @param game A pointer to the game data
 * @param character_id The character's id
 * @return the id of the character's location
 */
Id game_get_character_location(Game *game, Id character_id);

/**
 * @brief It sets n_characters
 * @author Álvaro Bravo González
 *
 * @param game A pointer to the game data
 * @param number The amount of characters
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status game_set_n_characters(Game *game, int number);

/**
 * @brief It gets n_characters
 * @author Álvaro Bravo González
 *
 * @param game A pointer to the game data
 * @return The amount of characters
 */
int game_get_n_characters(Game *game);

/* SPACE FUNCTIONS : */

/**
 * @brief It gets the spaces
 * @author Profesores PPROG
 *
 * @param id The identification number for the new space
 * @param game A pointer to the game data
 * @return A pointer to the space structure
 */
Space *game_get_space(Game *game, Id space_id);

/**
 * @brief It gets the spaces at the positio
 * @author Profesores PPROG
 *
 * @param id The identification number for the new space
 * @param game A pointer to the game data
 * @return A pointer to the space structure
 */
Space *game_get_space_at(Game *game, int position);

/**
 * @brief Adds spaces when called
 * @author Profesores PPROG
 *
 * @param game A pointer to the game data
 * @param space A pointer to a space
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status game_add_space(Game *game, Space *space);

/**
 * @brief It gets the id from a space
 * @author Jorge Torrijos de la Cruz
 *
 * @param game A pointer to the game data
 * @param position The position of the space in the spaces array
 * @return The id of the space
 */
Id game_get_space_id_at(Game *game, int position);

/**
 * @brief It gets the space from an id
 * @author Jorge Torrijos de la Cruz
 *
 * @param game A pointer to the game data
 * @param id The id of the character
 * @return A pointer to the space structure
 */
Space *game_get_space_with_id(Game *game, Id id);

/**
 * @brief It sets n_spaces
 * @author Jorge Torrijos de la Cruz
 *
 * @param game A pointer to the game data
 * @param number The amount of spaces, as an integer
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status game_set_n_spaces(Game *game, int number);

/**
 * @brief It gets n_spaces
 * @author Jorge Torrijos de la Cruz
 *
 * @param game A pointer to the game data
 * @return The amount of spaces, as an integer
 */
int game_get_n_spaces(Game *game);

/* COMMAND FUNCTIONS : */

/**
 * @brief It sets last command
 * @author Profesores PPROG
 *
 * @param game A pointer to the game data
 * @param command A pointer to the allocated memory for the command input
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status game_set_last_command(Game *game, Command *command);

/**
 * @brief It gets the last command
 * @author Profesores PPROG
 *
 * @param game A pointer to the game data
 * @return A pointer to the command structure
 */
Command *game_get_last_command(Game *game);

/* LINK FUNCTIONS : */

/**
 * @brief It gets the id of the space in the direction given
 * @author Jorge Torrijos de la Cruz
 *
 * @param game A pointer to the game data
 * @param actual_space The id of the current id
 * @param link_dir The direction where the space is relative to the link
 * @return A pointer to the command structure
 */
Id game_get_connection(Game *game, Id actual_space, Direction link_dir);

/**
 * @brief It gets the wether the connection at a respective directin is open or not
 * @author Jorge Torrijos de la Cruz
 *
 * @param game A pointer to the game data
 * @param actual_space The id of the current id
 * @param link_dir The direction where the space is relative to the link
 * @return The boolean value of the open connection
 */
Bool game_connection_is_open(Game *game, Id actual_space, Direction link_dir);

/**
 * @brief It adds the link to the game links pointer
 * @author Guillermo Nuñez Bravo
 *
 * @param game A pointer to the game data
 * @param link A pointer to the allocated memory for the link
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status game_add_link(Game *game, Link *link);

/**
 * @brief It gets the link from an id
 * @author Jorge Torrijos de la Cruz
 *
 * @param game A pointer to the game data
 * @param id The id of the character
 * @return A pointer to the character link
 */
Link *game_get_link_with_id(Game *game, Id id);

/**
 * @brief It gets the link from its position
 * @author Jorge Torrijos de la Cruz
 *
 * @param game A pointer to the game data
 * @param position The position of the object in the object array
 * @return A pointer to the link structure
 */
Link *game_get_link_at(Game *game, int position);

/**
 * @brief It sets the amount of links
 * @author Guillermo Nuñez Bravo
 *
 * @param game A pointer to the game data
 * @param amount The new quantity of links
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status game_set_n_links(Game *game, int amount);

/**
 * @brief It gets n_links
 * @author Guillermo Nuñez Bravo
 *
 * @param game A pointer to the game data
 * @return The amount of links, as an integer
 */
int game_get_n_links(Game *game);

/**
 * @brief It sets the finished status
 * @author Profesores PPROG
 *
 * @param game A pointer to the game data
 * @param finished A variable to save wether the action has finished or not
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status game_set_finished(Game *game, Bool finished);

/**
 * @brief It gets whether the game finishes or not
 * @author Profesores PPROG
 *
 * @param game A pointer to the game data
 * @return A boolean, specifying if the game finishes (TRUE) or not (FALSE)
 */
Bool game_get_finished(Game *game);

/**
 * @brief It sets turn
 * @author Guillermo Nuñez Bravo
 *
 * @param game A pointer to the game data
 * @param turn The turn
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status game_set_turn(Game *game, int turn);

/**
 * @brief It gets the actual turn
 * @author Guillermo Nuñez Bravo
 *
 * @param game A pointer to the game data
 * @return The actual turn
 */
int game_get_turn(Game *game);

/**
 * @brief It pushes the turn value once
 * @author Guillermo Nuñez Bravo
 *
 * @param game A pointer to the game data
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status game_next_turn(Game *game);

/**
 * @brief It gets the discovery status of a character
 * @author Jorge Torrijos de la Cruz
 *
 * @param game A pointer to the game data
 * @param char_id The id of the character
 * @return The boolean value of the discovery status
 */
Bool game_get_character_discovered(Game *game, Id char_id);

/**
 * @brief It gets the discovery status of an object
 * @author Jorge Torrijos de la Cruz
 *
 * @param game A pointer to the game data
 * @param object_id The id of the object
 * @return The boolean value of the discovery status
 */
Bool game_get_object_discovered(Game *game, Id object_id);

/**
 * @brief It sets the game determinism
 * @author Guillermo Nuñez Bravo
 *
 * @param game A pointer to the game data
 * @param deterministic a variable to save is the game is deterministic or not
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status game_set_deterministic(Game *game, Bool deterministic);

/**
 * @brief It gets the deterministic status of the game
 * @author Guillermo Nuñez Bravo
 *
 * @param game A pointer to the game data
 * @return The boolean value of the deterministic status
 */
Bool game_get_deterministic(Game *game);

/**
 * @brief It prints the game information
 * @author Profesores PPROG
 *
 * @param game A pointer to the game data
 */
void game_print(Game *game);

#endif
