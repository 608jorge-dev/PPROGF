/**
 * @brief It implements the game update through user actions
 *
 * @file game_actions.c
 * @author Profesores PPROG
 * @version 0
 * @date 27-01-2025
 * @copyright GNU Public License
 */

#include "game_actions.h"
#include "player.h"
#include "object.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <time.h>

/* Private functions
 */
void game_actions_unknown(Game *game);
void game_actions_exit(Game *game);
Status game_actions_move(Game *game);
Status game_actions_take(Game *game);
Status game_actions_drop(Game *game);
Status game_actions_attack(Game *game);
Status game_actions_chat(Game *game);
Status game_actions_inspect(Game *game);
Status game_actions_recruit(Game *game);
Status game_actions_abandon(Game *game);

/**
   Transfers the actual command state to the game function and calls the respective command function
*/
Status game_actions_update(Game *game, Command *command)
{
	CommandCode cmd;

	game_set_last_command(game, command);

	cmd = command_get_code(command);

	switch (cmd)
	{
	case UNKNOWN:
		game_actions_unknown(game);
		command_set_status(command, -1);
		break;

	case EXIT:
		game_actions_exit(game);
		command_set_status(command, -1);
		break;

	case MOVE:
		if (game_actions_move(game) == ERROR)
		{
			command_set_status(command, ERROR);
		};
		break;

	case TAKE:
		if (game_actions_take(game) == ERROR)
		{
			command_set_status(command, ERROR);
		};
		break;

	case DROP:
		if (game_actions_drop(game) == ERROR)
		{
			command_set_status(command, ERROR);
		}
		break;

	case ATTACK:
		if (game_actions_attack(game) == ERROR)
		{
			command_set_status(command, ERROR);
		}
		break;

	case CHAT:
		if (game_actions_chat(game) == ERROR)
		{
			command_set_status(command, ERROR);
		}
		break;

	case INSPECT:
		if (game_actions_inspect(game) == ERROR)
		{
			command_set_status(command, ERROR);
		}
		break;

	case RECRUIT:
		if (game_actions_recruit(game) == ERROR)
		{
			command_set_status(command, ERROR);
		}
		break;

	case ABANDON:
		if (game_actions_abandon(game) == ERROR)
		{
			command_set_status(command, ERROR);
		}
		break;

	default:
		break;
	}

	return OK;
}

/**
 * @brief Executes the unknow command
 * @author Profesores PPROG
 *
 * @param game A pointer to the game data
 */
void game_actions_unknown(Game *game) { return; }

/**
 * @brief Executes the exit command
 * @author Profesores PPROG
 *
 * @param game A pointer to the game data
 */
void game_actions_exit(Game *game) { return; }

/**
 * @brief Executes the move command depending on the string sent
 * @author Jorge Torrijos de la Cruz
 *
 * @param game A pointer to the game data
 */
Status game_actions_move(Game *game)
{
	Id player_space_id = NO_ID, current_id = NO_ID;
	Command *cmd = NULL;
	Direction dir = -1;
	char *direction = NULL;

	if (!game)
	{
		return ERROR;
	}

	cmd = game_get_last_command(game);
	if (!cmd)
	{
		return ERROR;
	}

	direction = command_get_argstr(cmd);
	if (!direction)
	{
		return ERROR;
	}

	player_space_id = game_get_player_location(game);
	if (player_space_id == NO_ID)
	{
		return ERROR;
	}

	if ((strcmp("south", direction) == 0 || strcmp("s", direction) == 0) && game_connection_is_open(game, player_space_id, S) == TRUE)
	{
		dir = 1;
	}

	if ((strcmp("north", direction) == 0 || strcmp("n", direction) == 0) && game_connection_is_open(game, player_space_id, N) == TRUE)
	{
		dir = 0;
	}

	if ((strcmp("east", direction) == 0 || strcmp("e", direction) == 0) && game_connection_is_open(game, player_space_id, E) == TRUE)
	{
		dir = 2;
	}

	if ((strcmp("west", direction) == 0 || strcmp("w", direction) == 0) && game_connection_is_open(game, player_space_id, W) == TRUE)
	{
		dir = 3;
	}

	if (dir >= 0)
	{
		current_id = game_get_connection(game, player_space_id, dir);
		if (current_id != NO_ID)
		{
			game_set_player_location(game, current_id);
			space_set_discovered(game_get_space(game, current_id), TRUE);
			return OK;
		}
	}

	return ERROR;
}

/**
 * @brief Executes the take command
 * @author Jorge Torrijos de la Cruz
 *
 * @param game A pointer to the game data
 */
Status game_actions_take(Game *game)
{
	int i;
	Id player_space_id = NO_ID, object_id = NO_ID, object_space_id = NO_ID;
	Command *cmd = NULL;
	char *name = NULL;
	Player *player = NULL;
	Object *object = NULL;

	if (!game)
	{
		return ERROR;
	}

	cmd = game_get_last_command(game);
	if (!cmd)
	{
		return ERROR;
	}

	name = command_get_argstr(cmd);
	if (!name)
	{
		return ERROR;
	}

	for (i = 0; i < game_get_n_objects(game); i++)
	{
		object = game_get_object_at(game, i);
		if (!strcasecmp(object_get_name(object), name))
		{
			object_id = object_get_id(object);
			break;
		}
	}

	player = game_get_player(game);
	if (!player)
	{
		return ERROR;
	}

	player_space_id = game_get_player_location(game);
	if (player_space_id == NO_ID)
	{
		return ERROR;
	}

	object_space_id = game_get_object_location(game, object_id);
	if (object_space_id == NO_ID)
	{
		return ERROR;
	}

	if (object_space_id != player_space_id)
	{
		return ERROR;
	}

	if (inventory_get_n_objs(player_get_objects(game_get_player(game))) == inventory_get_max_objs(player_get_objects(game_get_player(game))))
	{
		return ERROR;
	}
	player_add_object(player, object_id);
	space_del_object(game_get_space(game, object_space_id), object_id);

	return OK;
}

/**
 * @brief Executes the drop command
 * @author Jorge Torrijos de la Cruz
 *
 * @param game A pointer to the game data
 */
Status game_actions_drop(Game *game)
{
	int i;
	Id player_space_id = NO_ID, object_id = NO_ID;
	Command *cmd;
	char *name;
	Player *player;
	Object *object;
	Space *space;

	if (!game)
	{
		return ERROR;
	}

	player = game_get_player(game);
	if (!player)
	{
		return ERROR;
	}

	cmd = game_get_last_command(game);
	if (!cmd)
	{
		return ERROR;
	}

	name = command_get_argstr(cmd);
	if (!name)
	{
		return ERROR;
	}

	for (i = 0; i < game_get_n_objects(game); i++)
	{
		object = game_get_object_at(game, i);
		if (!strcasecmp(object_get_name(object), name))
		{
			object_id = object_get_id(object);
			break;
		}
	}

	player_space_id = game_get_player_location(game);
	if (player_space_id == NO_ID)
	{
		return ERROR;
	}

	space = game_get_space(game, player_space_id);
	if (space != NULL && (inventory_find_object(player_get_objects(game_get_player(game)), object_get_id(object)) == TRUE))
	{
		game_set_object_location(game, player_space_id, object_id);
		player_del_object(player, object_id);
		return OK;
	}

	return ERROR;;
}

/**
 * @brief Executes the attack command
 * @author Jorge Torrijos de la Cruz
 *
 * @param game A pointer to the game data
 */
Status game_actions_attack(Game *game)
{
	Player *player = NULL;
	Set *characters = NULL; 
	Character *enemy = NULL;
	Id player_space_id = NO_ID;
	int n;

	if (!game)
	{
		return ERROR;
	}

	player = game_get_player(game);
	if (!player)
	{
		return ERROR;
	}

	player_space_id = game_get_player_location(game);
	if (player_space_id == NO_ID)
	{
		return ERROR;
	}

	characters = space_get_characters(game_get_space(game, player_space_id));
	if(!characters)
	{
		return ERROR;
	}

	enemy = game_get_character_with_id(game, set_get_id_at(characters, 0));
	if (!enemy)
	{
		return ERROR;
	}

	if ((character_get_health(enemy)) == 0)
	{
		return ERROR;
	}

	if (character_get_friendly(enemy) != TRUE)
	{
		srand(time(NULL));
		n = rand() % 10;
		if (n <= 4 && n >= 0)
		{
			player_set_health(player, player_get_health(player) - 1);
			if (player_get_health(player) == 0)
			{
				game_set_dead_players(game, game_get_dead_players(game) + 1);
			}
		}
		else if (n >= 5 && n <= 9)
		{
			character_set_health(enemy, character_get_health(enemy) - 1);
			if ((character_get_health(enemy)) == 0)
			{
				character_set_gdesc(enemy, " ");
			}
		}
		return OK;
	}

	return ERROR;
}

/**
 * @brief Executes the chat command
 * @author Álvaro Bravo González
 *
 * @param game A pointer to the game data
 */
Status game_actions_chat(Game *game)
{
	Player *player = NULL;
	Character *character = NULL;
	char *message = NULL;
	Id player_space_id = NO_ID;
	Command *cmd = NULL;

	if (!game)
	{
		return ERROR;
	}

	cmd = game_get_last_command(game);
	if (!cmd)
	{
		return ERROR;
	}

	player = game_get_player(game);
	if (!player)
	{
		return ERROR;
	}

	player_space_id = game_get_player_location(game);
	if (player_space_id == NO_ID)
	{
		return ERROR;
	}

	character = game_get_character_with_id(game, space_get_character(game_get_space(game, player_space_id)));
	if (!character)
	{
		return ERROR;
	}

	message = character_get_message(character);
	if (!message)
	{
		return ERROR;
	}

	if (character_get_friendly(character))
	{
		command_set_description(cmd, message);
		return OK;
	}

	return ERROR;
}

/**
 * @brief Executes the inspect command depending on the string sent
 * @author Jorge Torrijos de la Cruz
 *
 * @param game A pointer to the game data
 */
Status game_actions_inspect(Game *game)
{
	int i;
	Id player_space_id = NO_ID, object_space_id = NO_ID;
	Command *cmd;
	char *name;
	Player *player;
	Object *object;

	if (!game)
	{
		return ERROR;
	}

	cmd = game_get_last_command(game);
	if (!cmd)
	{
		return ERROR;
	}

	name = command_get_argstr(cmd);
	if (!name)
	{
		return ERROR;
	}

	player = game_get_player(game);
	if (!player)
	{
		return ERROR;
	}

	player_space_id = game_get_player_location(game);
	if (player_space_id == NO_ID)
	{
		return ERROR;
	}

	for (i = 0; i < game_get_n_objects(game); i++)
	{
		object = game_get_object_at(game, i);
		if (strcasecmp(object_get_name(object), name) == 0)
		{
			object_space_id = game_get_object_location(game, object_get_id(object));
			if (object_space_id != player_space_id && object_space_id == NO_ID && inventory_find_object(player_get_objects(game_get_player(game)), object_get_id(object)) != TRUE)
			{
				return ERROR;
			}
			break;
		}
	}

	if (command_set_description(cmd, object_get_desc(object)) == ERROR)
	{
		return ERROR;
	}

	return OK;
}

Status game_actions_recruit(Game *game)
{
	int i;
	char *name = NULL;
	Character *character = NULL;
	Id player_space_id = NO_ID, player_id = NO_ID;
	Space *space = NULL;
	Player *player = NULL;
	Command *cmd = NULL;

	if (!game)
	{
		return ERROR;
	}

	cmd = game_get_last_command(game);
	if(!cmd)
	{
		return ERROR;
	}

	player_space_id = game_get_player_location(game);
	if (player_space_id == NO_ID)
	{
		return ERROR;
	}

	space = game_get_space(game, player_space_id);
	if (!space)
	{
		return ERROR;
	}

	player = game_get_player(game);
	if (!player)
	{
		return ERROR;
	}

	player_id = player_get_id(player);
	if(player_id == NO_ID)
	{
		return ERROR;
	}

	name = command_get_argstr(cmd);
	if (!name)
	{
		return ERROR;
	}

	for (i = 0; i < game_get_n_characters(game); i++)
	{
		character = game_get_character_at(game, i);
		if (!strcasecmp(character_get_name(character), name) && character_get_friendly(character))
		{
			character_set_following(character, player_id);
			break;
		}
	}

	return OK;
}

Status game_actions_abandon(Game *game)
{
	int i;
	char *name = NULL;
	Character *character = NULL;
	Id player_space_id = NO_ID;
	Space *space = NULL;
	Command *cmd = NULL;

	if (!game)
	{
		return ERROR;
	}

	cmd = game_get_last_command(game);
	if(!cmd)
	{
		return ERROR;
	}

	player_space_id = game_get_player_location(game);
	if (player_space_id == NO_ID)
	{
		return ERROR;
	}

	space = game_get_space(game, player_space_id);
	if (!space)
	{
		return ERROR;
	}

	name = command_get_argstr(cmd);
	if (!name)
	{
		return ERROR;
	}

	for (i = 0; i < game_get_n_characters(game); i++)
	{
		character = game_get_character_at(game, i);
		if (!strcasecmp(character_get_name(character), name) && character_get_friendly(character))
		{
			character_set_following(character, NO_ID);
			break;
		}
	}

	return OK;
}