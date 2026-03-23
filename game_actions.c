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
		if (game_actions_chat(game) == -2)
		{
			command_set_status(command, -2);
		}
		else if (game_actions_chat(game) == ERROR)
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
 * @brief Executes the take command
 * @author Jorge Torrijos de la Cruz
 *
 * @param game A pointer to the game data
 */
Status game_actions_take(Game *game)
{
	int i;
	Id player_space_id = NO_ID, object_id = NO_ID, object_space_id = NO_ID;
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

	for (i = 0; i < game_get_n_objects(game); i++)
	{

		object = game_get_object_at(game, i);

		if (!strcmp(object_get_name(object), name))
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

		if (!strcmp(object_get_name(object), name))
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
	if (space != NULL)
	{
		game_set_object_location(game, player_space_id, object_id);
		player_del_object(player, object_id);
	}

	return OK;
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

	enemy = game_get_character_with_id(game, space_get_character(game_get_space(game, player_space_id)));
	if (!enemy)
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
			if ((player_get_health(player)) == 0)
			{
				game_set_finished(game, TRUE);
			}
		}
		else if (n >= 5 && n <= 9)
		{
			character_set_health(enemy, character_get_health(enemy) - 1);
			if ((character_get_health(enemy)) == 0)
			{
				character_destroy(enemy);
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
	const char *message = NULL;
	Id player_space_id = NO_ID;

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
		return -2;
	}

	return ERROR;
}

/**
 * @brief Executes the move command depending on the string sent
 * @author Jorge Torrijos de la Cruz
 *
 * @param game A pointer to the game data
 */
Status game_actions_move(Game *game)
{
	Id player_space_id = NO_ID, current_id = NO_ID;
	Command *cmd;
	char *direction;
	Player *player;

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

	if (strcmp("next", direction) == 0 && game_connection_is_open(game, player_space_id, S) == TRUE)	{
		current_id = link_get_destination(game_get_link_with_id(game, game_get_connection(game, player_space_id, S)));
		if (current_id != NO_ID)
		{
			game_set_player_location(game, current_id);
			return OK;
		}
	}

	if (strcmp("back", direction) == 0 && game_connection_is_open(game, player_space_id, N) == TRUE)	{
		current_id = link_get_destination(game_get_link_with_id(game, game_get_connection(game, player_space_id, N)));
		if (current_id != NO_ID)
		{
			game_set_player_location(game, current_id);
			return OK;
		}
	}

	if (strcmp("left", direction) == 0 && game_connection_is_open(game, player_space_id, W) == TRUE)	{
		current_id = link_get_destination(game_get_link_with_id(game, game_get_connection(game, player_space_id, W)));
		if (current_id != NO_ID)
		{
			game_set_player_location(game, current_id);
			return OK;
		}
	}

	if (strcmp("right", direction) == 0 && game_connection_is_open(game, player_space_id, E) == TRUE) 	{
		current_id = link_get_destination(game_get_link_with_id(game, game_get_connection(game, player_space_id, E)));
		if (current_id != NO_ID)
		{
			game_set_player_location(game, current_id);
			return OK;
		}
	}

	return ERROR;
}