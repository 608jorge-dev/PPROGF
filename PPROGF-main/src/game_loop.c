/**
 * @brief It defines and implements the game loop
 *
 * @file game_loop.c
 * @author Guillermo Núñez Bravo, Iván Rodríguez Camacho, Jorge Torrijos de la Cruz
 * @version 7.0
 * @date 28-04-2026
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "command.h"
#include "game.h"
#include "game_management.h"
#include "game_actions.h"
#include "graphic_engine.h"
#include "playerinf.h"
#include <unistd.h>

int game_loop_init(Game *game, Graphic_engine **gengine, char *file_name);

void game_loop_cleanup(Game *game, Graphic_engine *gengine);

extern char *cmd_to_str[N_CMD][N_CMDT];

/**
 * @brief General game loop, based on calling graphic_engine, command get user input and game_actions_update
 * @author Profesores PPROG
 *
 * @param argc Amount of arguments sent
 * @param argv Array of arguments sent
 * @return 1 if game loop has an error and 0 if everything is ok
 */
int main(int argc, char *argv[])
{
  Game *game = NULL;
  Graphic_engine *gengine = NULL;
  int result = 0;
  Command *last_cmd = NULL;
  Status st, actions_status;
  FILE *log_file = NULL;
  int log = 0, cmd = 0, deterministic = 0, i;
  CommandCode code = -1;
  char *arg = NULL;

  for (i = 0; i < argc; i++)
  {
    if (strcmp(argv[i], "-d") == 0)
    {
      deterministic = 1;
    }
    if (strcmp(argv[i], "-l") == 0)
    {
      log_file = fopen(argv[argc - 1], "w");
      if (log_file == NULL)
      {
        return 1;
      }
      log = 1;
    }
  }

  if (argc < 2)
  {
    fprintf(stderr, "Use: %s <game_data_file>\n", argv[0]);
    return 1;
  }

  game = game_create();
  result = game_loop_init(game, &gengine, argv[1]);
  game_set_deterministic(game, deterministic);

  if (result == 1)
  {
    fprintf(stderr, "Error while initializing game.\n");
    return 1;
  }
  else if (result == 2)
  {
    fprintf(stderr, "Error while initializing graphic engine.\n");
    return 1;
  }

  last_cmd = game_get_last_command(game);

  while ((game_get_finished(game) == FALSE))
  {
    while (player_get_health(game_get_player(game)) == 0)
    {
      game_next_turn(game);
    }
    graphic_engine_paint_game(gengine, game);
    if (cmd == 0)
    {
      command_get_user_input(last_cmd);
    }
    if (command_get_code(last_cmd) == EXIT)
    {
      break;
    }

    actions_status = game_actions_update(game, last_cmd);
    if (game_get_playerinf(game) == NULL)
    {
      fprintf(stdout, "%ld", playerinf_get_id(game_get_playerinf(game)));
    }
    playerinf_set_lastcommand(game_get_playerinf(game), command_get_code(last_cmd));
    playerinf_set_laststatus(game_get_playerinf(game), command_get_status(last_cmd));
    if (command_get_code(last_cmd) == CHAT && command_get_status(last_cmd) == OK)
    {
      playerinf_set_lastchat(game_get_playerinf(game), command_get_description(last_cmd));
    }
    if (command_get_code(last_cmd) == INSPECT && command_get_status(last_cmd) == OK)
    {
      playerinf_set_lastinspect(game_get_playerinf(game), command_get_description(last_cmd));
    }

    code = command_get_code(last_cmd);
    arg = command_get_argstr(last_cmd, 0);
    st = command_get_status(last_cmd);

    if (log == 1)
    {
      if (arg && arg[0] != '\0')
      {
        fprintf(log_file, "Player %d: %s %s: %s \n", game_get_turn(game), cmd_to_str[code - NO_CMD][CMDL], arg, (st == OK) ? "OK" : "ERROR");
      }
      else
      {
        fprintf(log_file, "Player %d: %s: %s \n", game_get_turn(game), cmd_to_str[code - NO_CMD][CMDL], (st == OK) ? "OK" : "ERROR");
      }
    }

    if (game_get_dead_players(game) == game_get_n_players(game))
    {
      graphic_engine_paint_game(gengine, game);
      fprintf(stdout, "\n   ____     _    _    _   ____   ____    __  __   ____   _____ ");
      fprintf(stdout, "\n  / ___|   / \\ | \\_/ | |      /    \\  | | | | |      | |  \\");
      fprintf(stdout, "\n |  |  _  | O | |  __  | |____ |  /\\  | | |_| | |____  | |_ //");
      fprintf(stdout, "\n |  |_| | |___| | |  | | |     |  \\/  | |     | |      | |  \\ ");
      fprintf(stdout, "\n \\_____| |   | |_|  |_| |____ \\_____/  \\___/  |____  |_|   \\ \n\n");
      game_set_finished(game, TRUE);
    }
    sleep(1);
    if (actions_status == ERROR)
    {
      fprintf(stdout, "ERROR, REPEAT TURN");
    }
    else if (code == MOVE)
    {
      game_next_turn(game);
    }
  }

  if (log == 1)
  {
    fclose(log_file);
    log_file = NULL;
  }

  game_loop_cleanup(game, gengine);
  return 0;
}

/**
 * @brief Initiates the game calling the respective functions
 * @author Profesores PPROG
 *
 * @param game A pointer to the game data
 * @param gengine A double pointer to the graphic engine data
 * @param file_name A pointer to the name of the data file
 * @return -1 if file creation has an error, -2 if graphic engine creation has an error and 0 if everything is ok
 */
int game_loop_init(Game *game, Graphic_engine **gengine, char *file_name)
{
  if (game_management_load(game, file_name) == ERROR)
  {
    return 1;
  }

  if ((*gengine = graphic_engine_create()) == NULL)
  {
    game_destroy(game);
    return 2;
  }

  return 0;
}

/**
 * @brief  Free all used memory for the game game engine
 * @author Profesores PPROG
 *
 * @param game A pointer to the game data
 * @param gengine A double pointer to the graphic engine data
 */
void game_loop_cleanup(Game *game, Graphic_engine *gengine)
{
  game_destroy(game);
  graphic_engine_destroy(gengine);
}
