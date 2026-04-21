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
Status game_actions_use(Game *game);
Status game_actions_open(Game *game);
Status game_actions_save(Game *game);
Status game_actions_load(Game *game);

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

	case USE:
		if (game_actions_use(game) == ERROR)
		{
			command_set_status(command, ERROR);
		}
		break;

	case OPEN:
		if (game_actions_open(game) == ERROR)
		{
			command_set_status(command, ERROR);
		}
		break;

	case SAVE:
		if (game_actions_save(game) == ERROR)
		{
			command_set_status(command, ERROR);
		}
		break;

	case LOAD:
		if (game_actions_load(game) == ERROR)
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

	direction = command_get_argstr(cmd, 0);
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

	if ((strcmp("up", direction) == 0 || strcmp("u", direction) == 0) && game_connection_is_open(game, player_space_id, U) == TRUE)
	{
		dir = 4;
	}

	if ((strcmp("down", direction) == 0 || strcmp("d", direction) == 0) && game_connection_is_open(game, player_space_id, D) == TRUE)
	{
		dir = 5;
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

	name = command_get_argstr(cmd, 0);
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

	if (object_space_id != player_space_id && object_get_movable(object) != TRUE)
	{
		return ERROR;
	}

	if (object_get_dependency(object) != NO_ID)
	{
		if (inventory_find_object(player_get_objects(game_get_player(game)), object_get_id(object)) == FALSE)
		{
			return ERROR;
		}
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

	name = command_get_argstr(cmd, 0);
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

	return ERROR;
	;
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
	int n_rand, choice, i, followers = 0;

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
	if (!characters)
	{
		return ERROR;
	}

	enemy = game_get_character_with_id(game, set_get_id_at(characters, 0));
	if (!enemy || character_get_health(enemy) == 0)
	{
		return ERROR;
	}

	if (character_get_friendly(enemy) != TRUE)
	{
		/*if(game_get_deterministic(game) == TRUE){
			srand(1);
		}else{
			srand(time(NULL));
		}*/
		srand(time(NULL));
		choice = rand() % 10;
		for (i = 0; i < game_get_n_characters(game); i++)
		{
			if (character_get_following(game_get_character_at(game, i)) == player_get_id(player))
			{
				followers++;
			}
		}
		if (choice >= 5)
		{
			character_set_health(enemy, character_get_health(enemy) - (1 + followers));
			if ((character_get_health(enemy)) <= 0)
			{
				character_set_gdesc(enemy, "   ");
			}
		}
		else
		{
			n_rand = rand() % (followers + 1); /* +1 por player y +1 para que el modulo no se salte numeros en ese rango */
			if (n_rand == 0)
			{
				player_set_health(player, player_get_health(player) - 1);
				if (player_get_health(player) == 0)
				{
					game_set_dead_players(game, game_get_dead_players(game) + 1);
				}
			}
			else if (n_rand > 0 && n_rand <= followers)
			{
				for (i = 0; i <= game_get_n_characters(game); i++)
				{
					if (character_get_following(game_get_character_at(game, i)) == player_get_id(player))
					{
						if (n_rand > 0)
						{
							n_rand--;
						}
						else
						{
							character_set_health(game_get_character_at(game, i), character_get_health(game_get_character_at(game, i)) - 1);
						}
						if (character_get_health(game_get_character_at(game, i)) == 0)
						{
							character_set_following(game_get_character_at(game, i), NO_ID);
							character_set_gdesc(game_get_character_at(game, i), "   ");
						}
						break;
					}
				}
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
	int i;
	Player *player = NULL;
	Character *character = NULL;
	Set *characters = NULL;
	char *message = NULL, *name = NULL;
	Id player_space_id = NO_ID;
	Space *space = NULL;
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

	space = game_get_space(game, player_space_id);
	if(!space)
	{
		return ERROR;
	}

	characters = space_get_characters(space);
	if (!characters)
	{
		return ERROR;
	}

	name = command_get_argstr(cmd, 0);
	if (!name)
	{
		return ERROR;
	}

	for (i = 0; i < game_get_n_characters(game); i++)
	{
		character = game_get_character_at(game, i);
		if (!strcasecmp(character_get_name(character), name))
		{
			break;
		}
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

	name = command_get_argstr(cmd, 0);
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
	if (!cmd)
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
	if (player_id == NO_ID)
	{
		return ERROR;
	}

	name = command_get_argstr(cmd, 0);
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
	if (!cmd)
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

	name = command_get_argstr(cmd, 0);
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

Status game_actions_use(Game *game)
{
	int i;
	Object *object = NULL;
	Player *player = NULL;
	Character *character = NULL;
	Command *cmd = NULL;
	char *arg1 = NULL, *arg2 = NULL;

	if (!game)
	{
		return ERROR;
	}

	cmd = game_get_last_command(game);
	if (!cmd)
	{
		return ERROR;
	}

	arg1 = command_get_argstr(cmd, 0);
	if (!arg1)
	{
		return ERROR;
	}

	player = game_get_player(game);
	if (!player)
	{
		return ERROR;
	}

	for (i = 0; i < game_get_n_objects(game); i++)
	{
		object = game_get_object_at(game, i);
		if (!strcasecmp(object_get_name(object), arg1))
		{
			break;
		}
	}

	arg2 = command_get_argstr(cmd, 1);
	if (!arg2)
	{
		if (player_set_health(player, player_get_health(player) + object_get_health(object)) == ERROR)
		{
			return ERROR;
		}
		return OK;
	}

	for (i = 0; i < game_get_n_characters(game); i++)
	{
		character = game_get_character_at(game, i);
		if (!strcasecmp(character_get_name(character), arg2))
		{
			break;
		}
	}

	if (character_set_health(character, character_get_health(character) + object_get_health(object)) == ERROR)
	{
		return ERROR;
	}

	return OK;
}

Status game_actions_open(Game *game)
{
	Command *cmd = NULL;
	char *arg1 = NULL, *arg2 = NULL;
	int i;
	Link *link = NULL;
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

	arg1 = command_get_argstr(cmd, 0);
	if (!arg1)
	{
		return ERROR;
	}

	arg2 = command_get_argstr(cmd, 2);
	if (!arg2)
	{
		return ERROR;
	}

	for (i = 0; i < game_get_n_links(game); i++)
	{
		link = game_get_link_at(game, i);
		if (!strcasecmp(link_get_name(link), arg1))
		{
			break;
		}
	}

	if (game_get_player_location(game) != link_get_origin(link))
	{
		return ERROR;
	}

	for (i = 0; i < game_get_n_objects(game); i++)
	{
		object = game_get_object_at(game, i);
		if (!strcasecmp(object_get_name(object), arg2))
		{
			break;
		}
	}

	if (object_get_open(object) != link_get_id(link))
	{
		return ERROR;
	}

	if (link_set_open(link, TRUE) == ERROR)
	{
		return ERROR;
	}

	return OK;
}

Status game_actions_save(Game *game)
{
	Command *cmd = NULL;
	char *arg1 = NULL;

	if (!game)
	{
		return ERROR;
	}

	cmd = game_get_last_command(game);
	if (!cmd)
	{
		return ERROR;
	}

	arg1 = command_get_argstr(cmd, 0);
	if (!arg1)
	{
		return ERROR;
	}

	if (game_management_save(game, arg1) == ERROR)
	{
		return ERROR;
	}

	return OK;
}

Status game_actions_load(Game *game)
{
	Command *cmd = NULL;
	char *arg1 = NULL;

	if (!game)
	{
		return ERROR;
	}

	cmd = game_get_last_command(game);
	if (!cmd)
	{
		return ERROR;
	}

	arg1 = command_get_argstr(cmd, 0);
	if (!arg1)
	{
		return ERROR;
	}

	if (game_management_load(game, arg1) == ERROR)
	{
		return ERROR;
	}

	return OK;
}