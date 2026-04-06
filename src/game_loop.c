/**
 * @brief It defines the game loop
 *
 * @file game_loop.c
 * @author Profesores PPROG
 * @version 0
 * @date 24-01-2026
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "command.h"
#include "game.h"
#include "game_reader.h"
#include "game_actions.h"
#include "graphic_engine.h"

int game_loop_init(Game *game, Graphic_engine **gengine, char *file_name);

void game_loop_cleanup(Game *game, Graphic_engine *gengine);

extern char *cmd_to_str[N_CMD][N_CMDT];

/**
 * @brief General game loop, based on calling graphic_engine, command get user input and game_actions_update
 * @author Profesores PPROG
 *
 * @param argc amount of arguments sent
 * @param argv Array of arguments sent
 * @return 1 if game loop has an error and 0 if everything is ok
 */
int main(int argc, char *argv[])
{
  Game *game = NULL;
  Graphic_engine *gengine;
  int result;
  Command *last_cmd;
  Status status;
  FILE *log_file = NULL, *cmd_file = NULL;
  int log = 0, cmd = 0;
  CommandCode code, cmd_code;
  char *arg = NULL, *cmd_arg = NULL;

  if (argc < 2)
  {
    fprintf(stderr, "Use: %s <game_data_file>\n", argv[0]);
    return 1;
  }

  if (argc < 4 && strcmp(argv[argc - 2], "-l") == 0)
  {
    log_file = fopen(argv[argc - 1], "a");
    if (log_file == NULL)
    {
      game_loop_cleanup(game, gengine);
      return 1;
    }
    log = 1;
  }

  /* Hay que cambiarlo para que reconozca cualquier archivo .cmd */
  /*if (argc < 6 && strcmp(argv[argc - 1], "game1.cmd") == 0 && strcmp(argv[argc - 4], "-l") == 0) {}
    cmd_file = fopen(argv[argc - 1], "r");
    if (log_file == NULL)
    {
      game_loop_cleanup(game, gengine);
      return 1;
    }
    log_file = fopen(argv[argc - 3], "a");
    if (log_file == NULL)
    {
      game_loop_cleanup(game, gengine);
      return 1;
    }
    log = 1;
    cmd = 1;
  }*/

  game = game_create();
  result = game_loop_init(game, &gengine, argv[1]);

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

  while ((command_get_code(last_cmd) != EXIT) && (game_get_finished(game) == FALSE))
  {
    graphic_engine_paint_game(gengine, game);
    if (cmd = 0)  {
      command_get_user_input(last_cmd);
    }
    /* else if (cmd = 1) {
      if (fscanf (cmd_file, "%s %s", cmd_code, cmd_arg) == 2)  {
        command_set_code(last_cmd, cmd_code);
        command_set_argstr(last_cmd, cmd_arg);
      }

        if (fscanf (cmd_file, "%s", cmd_code) == 1) {
          command_set_code(last_cmd, cmd_code);
        }
    }*/

    status = game_actions_update(game, last_cmd);

    if (log == 1)
    {
      code = command_get_code(last_cmd);
      arg = command_get_argstr(last_cmd);

      if (arg && arg[0] != '\0')
      {
        fprintf(log_file, "%s %s: %s \n", cmd_to_str[code - NO_CMD][CMDL], arg, (status == OK) ? "OK" : "ERROR");
      }
      else
      {
        fprintf(log_file, "%s: %s \n", cmd_to_str[code - NO_CMD][CMDL], (status == OK) ? "OK" : "ERROR");
      }
    }
  }

  if(log == 1){
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
  if (game_reader_create_from_file(game, file_name) == ERROR)
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
