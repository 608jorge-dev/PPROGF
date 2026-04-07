
/**
 * @brief It implements a textual graphic engine
 *
 * @file graphic_engine.c
 * @author Profesores PPROG
 * @version 0
 * @date 24-01-2026
 * @copyright GNU Public License
 */

#include "graphic_engine.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Graphic engine
 *
 * This struct stores all the information of the graphic engine.
 */
struct _Graphic_engine
{
  Area *map;      /*!< Map area in the screen*/
  Area *descript; /*!< Description area in the screen*/
  Area *banner;   /*!< Banner area in the screen*/
  Area *help;     /*!< Help area in the screen*/
  Area *feedback; /*!< Feedback area in the screen*/
};

/** It creates a graphic engine, allocating memory and initializing its members
 */
Graphic_engine *graphic_engine_create()
{
  static Graphic_engine *ge = NULL;

  if (ge)
  {
    return ge;
  }

  screen_init(HEIGHT_MAP + HEIGHT_BAN + HEIGHT_HLP + HEIGHT_FDB + 4, WIDTH_MAP + WIDTH_DES + 3);
  ge = (Graphic_engine *)calloc(1, sizeof(Graphic_engine));
  if (ge == NULL)
  {
    return NULL;
  }

  ge->map = screen_area_init(1, 1, WIDTH_MAP, HEIGHT_MAP);
  ge->descript = screen_area_init(WIDTH_MAP + 2, 1, WIDTH_DES, HEIGHT_MAP);
  ge->banner = screen_area_init((int)((WIDTH_MAP + WIDTH_DES + 1 - WIDTH_BAN) / 2), HEIGHT_MAP + 2, WIDTH_BAN, HEIGHT_BAN);
  ge->help = screen_area_init(1, HEIGHT_MAP + HEIGHT_BAN + 2, WIDTH_MAP + WIDTH_DES + 1, HEIGHT_HLP);
  ge->feedback = screen_area_init(1, HEIGHT_MAP + HEIGHT_BAN + HEIGHT_HLP + 3, WIDTH_MAP + WIDTH_DES + 1, HEIGHT_FDB);

  return ge;
}

/** It destroys the graphic engine, freeing the allocated memory
 */
void graphic_engine_destroy(Graphic_engine *ge)
{
  if (!ge)
    return;

  screen_area_destroy(ge->map);
  screen_area_destroy(ge->descript);
  screen_area_destroy(ge->banner);
  screen_area_destroy(ge->help);
  screen_area_destroy(ge->feedback);

  screen_destroy();
  free(ge);
}

/** Changes the game GUI (paints in the differente graphic sections)
 */
void graphic_engine_paint_game(Graphic_engine *ge, Game *game)
{
  Id id_act = NO_ID, id_back = NO_ID, id_next = NO_ID, id_left = NO_ID, id_right = NO_ID;
  int i;
  char c_gdesc[10], link1 = ' ', link2 = ' ';
  char str[255];
  char *stat = NULL;
  Id p_obj = NO_ID, player_loc = NO_ID, char_id = NO_ID;
  CommandCode last_cmd = UNKNOWN;
  extern char *cmd_to_str[N_CMD][N_CMDT];

  /* Paint the in the map area */
  screen_area_clear(ge->map);
  if ((id_act = game_get_player_location(game)) != NO_ID)
  {
    id_back = game_get_connection(game, id_act, 0);
    id_next = game_get_connection(game, id_act, 1);
    id_left = game_get_connection(game, id_act, 3);
    id_right = game_get_connection(game, id_act, 2);

    /* Paint back space */
    c_gdesc[0] = ' ';
    c_gdesc[1] = ' ';
    c_gdesc[2] = ' ';
    char_id = space_get_character(game_get_space(game, id_back));
    if (char_id != NO_ID)
    {
      strcpy(c_gdesc, character_get_gdesc(game_get_character_with_id(game, char_id)));
    }

    if (id_back != NO_ID)
    {
      if (game_connection_is_open(game, id_act, N)) {
        link1 = '^';
      }

      if (space_get_discovered(game_get_space(game, id_back)) == TRUE)  {
        sprintf(str, "                       +--------------+");
        screen_area_puts(ge->map, str);
        sprintf(str, "                       |     %-3.3s    %2d|", c_gdesc, (int)id_back);
        screen_area_puts(ge->map, str);
        sprintf(str, "                       |%-9.9s     |  ", space_get_gdesc(game_get_space(game, id_back), 0));
        screen_area_puts(ge->map, str);
        sprintf(str, "                       |%-9.9s     |  ", space_get_gdesc(game_get_space(game, id_back), 1));
        screen_area_puts(ge->map, str);
        sprintf(str, "                       |%-9.9s     |  ", space_get_gdesc(game_get_space(game, id_back), 2));
        screen_area_puts(ge->map, str);
        sprintf(str, "                       |%-9.9s     |  ", space_get_gdesc(game_get_space(game, id_back), 3));
        screen_area_puts(ge->map, str);
        sprintf(str, "                       |%-9.9s     |  ", space_get_gdesc(game_get_space(game, id_back), 4));
        screen_area_puts(ge->map, str);
        sprintf(str, "                       +--------------+");
        screen_area_puts(ge->map, str);
        sprintf(str, "                               %c", link1);
        screen_area_puts(ge->map, str);
      }

      else {
        sprintf(str, "                       +--------------+");
        screen_area_puts(ge->map, str);
        sprintf(str, "                       |           %2d|", (int)id_back);
        screen_area_puts(ge->map, str);
        sprintf(str, "                       |              |  ");
        screen_area_puts(ge->map, str);
        sprintf(str, "                       |              |  ");
        screen_area_puts(ge->map, str);
        sprintf(str, "                       |              |  ");
        screen_area_puts(ge->map, str);
        sprintf(str, "                       |              |  ");
        screen_area_puts(ge->map, str);
        sprintf(str, "                       |              |  ");
        screen_area_puts(ge->map, str);
        sprintf(str, "                       +--------------+");
        screen_area_puts(ge->map, str);
        sprintf(str, "                               %c", link1);
        screen_area_puts(ge->map, str);
      }
    }

    /* Paint current space */
    c_gdesc[0] = ' ';
    c_gdesc[1] = ' ';
    c_gdesc[2] = ' ';
    link1 = ' ';
    link2 = ' ';
    char_id = space_get_character(game_get_space(game, id_act));
    if (char_id != NO_ID)
    {
      strcpy(c_gdesc, character_get_gdesc(game_get_character_with_id(game, char_id)));
    }

    if (id_act != NO_ID && id_right != NO_ID && id_left != NO_ID)
    {
      if (game_connection_is_open(game, id_act, W)) {
        link1 = '<';
      }
      if (game_connection_is_open(game, id_act, E)) {
        link2 = '>';
      }
      if (space_get_discovered(game_get_space(game, id_left)) == TRUE && space_get_discovered(game_get_space(game, id_right)) == TRUE) {
        sprintf(str, "  +--------------+    +--------------+      +--------------+");
        screen_area_puts(ge->map, str);
        sprintf(str, "  |            %2d|    | %s %-3.3s   %2d|      |           %2d|", (int)id_left, player_get_gdesc(game_get_player(game)), c_gdesc, (int)id_act, (int)id_right);
        screen_area_puts(ge->map, str);
        sprintf(str, "  | %-9.9s    |    | %-9.9s    |      | %-9.9s    |", space_get_gdesc(game_get_space(game, id_left), 0), space_get_gdesc(game_get_space(game, id_act), 0), space_get_gdesc(game_get_space(game, id_right), 0));
        screen_area_puts(ge->map, str);
        sprintf(str, "  | %-9.9s    |    | %-9.9s    |      | %-9.9s    |", space_get_gdesc(game_get_space(game, id_left), 1), space_get_gdesc(game_get_space(game, id_act), 1), space_get_gdesc(game_get_space(game, id_right), 1));
        screen_area_puts(ge->map, str);
        sprintf(str, "  | %-9.9s    | %c  | %-9.9s    |   %c  | %-9.9s    |", space_get_gdesc(game_get_space(game, id_left), 2), link1, space_get_gdesc(game_get_space(game, id_act), 2), link2, space_get_gdesc(game_get_space(game, id_right), 2));
        screen_area_puts(ge->map, str);
        sprintf(str, "  | %-9.9s    |    | %-9.9s    |      | %-9.9s    |", space_get_gdesc(game_get_space(game, id_left), 3), space_get_gdesc(game_get_space(game, id_act), 3), space_get_gdesc(game_get_space(game, id_right), 3));
        screen_area_puts(ge->map, str);
        sprintf(str, "  | %-9.9s    |    | %-9.9s    |      | %-9.9s    |", space_get_gdesc(game_get_space(game, id_left), 4), space_get_gdesc(game_get_space(game, id_act), 4), space_get_gdesc(game_get_space(game, id_right), 4));
        screen_area_puts(ge->map, str);
        sprintf(str, "  +--------------+    +--------------+      +--------------+");
        screen_area_puts(ge->map, str);
      }

      else if (space_get_discovered(game_get_space(game, id_left)) == FALSE && space_get_discovered(game_get_space(game, id_right)) == TRUE) {
        sprintf(str, "  +--------------+    +--------------+      +--------------+");
        screen_area_puts(ge->map, str);
        sprintf(str, "  |            %2d|    | %s %-3.3s   %2d|      |           %2d|", (int)id_left, player_get_gdesc(game_get_player(game)), c_gdesc, (int)id_act, (int)id_right);
        screen_area_puts(ge->map, str);
        sprintf(str, "  |              |    | %-9.9s    |      | %-9.9s    |", space_get_gdesc(game_get_space(game, id_act), 0), space_get_gdesc(game_get_space(game, id_right), 0));
        screen_area_puts(ge->map, str);
        sprintf(str, "  |              |    | %-9.9s    |      | %-9.9s    |", space_get_gdesc(game_get_space(game, id_act), 1), space_get_gdesc(game_get_space(game, id_right), 1));
        screen_area_puts(ge->map, str);
        sprintf(str, "  |              | %c  | %-9.9s    |   %c  | %-9.9s    |", link1, space_get_gdesc(game_get_space(game, id_act), 2), link2, space_get_gdesc(game_get_space(game, id_right), 2));
        screen_area_puts(ge->map, str);
        sprintf(str, "  |              |    | %-9.9s    |      | %-9.9s    |", space_get_gdesc(game_get_space(game, id_act), 3), space_get_gdesc(game_get_space(game, id_right), 3));
        screen_area_puts(ge->map, str);
        sprintf(str, "  |              |    | %-9.9s    |      | %-9.9s    |", space_get_gdesc(game_get_space(game, id_act), 4), space_get_gdesc(game_get_space(game, id_right), 4));
        screen_area_puts(ge->map, str);
        sprintf(str, "  +--------------+    +--------------+      +--------------+");
        screen_area_puts(ge->map, str);
      }

      if (space_get_discovered(game_get_space(game, id_left)) == TRUE && space_get_discovered(game_get_space(game, id_right)) == FALSE) {
        sprintf(str, "  +--------------+    +--------------+      +--------------+");
        screen_area_puts(ge->map, str);
        sprintf(str, "  |            %2d|    | %s %-3.3s   %2d|      |           %2d|", (int)id_left, player_get_gdesc(game_get_player(game)), c_gdesc, (int)id_act, (int)id_right);
        screen_area_puts(ge->map, str);
        sprintf(str, "  | %-9.9s    |    | %-9.9s    |      |              |", space_get_gdesc(game_get_space(game, id_left), 0), space_get_gdesc(game_get_space(game, id_act), 0));
        screen_area_puts(ge->map, str);
        sprintf(str, "  | %-9.9s    |    | %-9.9s    |      |              |", space_get_gdesc(game_get_space(game, id_left), 1), space_get_gdesc(game_get_space(game, id_act), 1));
        screen_area_puts(ge->map, str);
        sprintf(str, "  | %-9.9s    | %c  | %-9.9s    |   %c  |              |", space_get_gdesc(game_get_space(game, id_left), 2), link1, space_get_gdesc(game_get_space(game, id_act), 2), link2);
        screen_area_puts(ge->map, str);
        sprintf(str, "  | %-9.9s    |    | %-9.9s    |      |              |", space_get_gdesc(game_get_space(game, id_left), 3), space_get_gdesc(game_get_space(game, id_act), 3));
        screen_area_puts(ge->map, str);
        sprintf(str, "  | %-9.9s    |    | %-9.9s    |      |              |", space_get_gdesc(game_get_space(game, id_left), 4), space_get_gdesc(game_get_space(game, id_act), 4));
        screen_area_puts(ge->map, str);
        sprintf(str, "  +--------------+    +--------------+      +--------------+");
        screen_area_puts(ge->map, str);
      }

      
    }

    if (id_act != NO_ID && id_right != NO_ID && id_left == NO_ID)
    {
       if (game_connection_is_open(game, id_act, E)) {
        link2 = '>';
      }
      sprintf(str, "                       +--------------+      +--------------+");
      screen_area_puts(ge->map, str);
      sprintf(str, "                       |  %s  %-3.3s  %2d|      |           %2d|", player_get_gdesc(game_get_player(game)), c_gdesc, (int)id_act, (int)id_right);
      screen_area_puts(ge->map, str);
      sprintf(str, "                       | %-9.9s    |      | %-9.9s    |", space_get_gdesc(game_get_space(game, id_act), 0), space_get_gdesc(game_get_space(game, id_right), 0));
      screen_area_puts(ge->map, str);
      sprintf(str, "                       | %-9.9s    |   %c  | %-9.9s    |", space_get_gdesc(game_get_space(game, id_act), 1), link2,  space_get_gdesc(game_get_space(game, id_right), 1));
      screen_area_puts(ge->map, str);
      sprintf(str, "                       | %-9.9s    |      | %-9.9s    |", space_get_gdesc(game_get_space(game, id_act), 2), space_get_gdesc(game_get_space(game, id_right), 2));
      screen_area_puts(ge->map, str);
      sprintf(str, "                       | %-9.9s    |      | %-9.9s    | ", space_get_gdesc(game_get_space(game, id_act), 3), space_get_gdesc(game_get_space(game, id_right), 3));
      screen_area_puts(ge->map, str);
      sprintf(str, "                       | %-9.9s    |      | %-9.9s    | ", space_get_gdesc(game_get_space(game, id_act), 4), space_get_gdesc(game_get_space(game, id_right), 4));
      screen_area_puts(ge->map, str);
      sprintf(str, "                       +--------------+      +--------------+");
      screen_area_puts(ge->map, str);
    }

    if (id_act != NO_ID && id_left != NO_ID && id_right == NO_ID)
    {
       if (game_connection_is_open(game, id_act, W)) {
        link1 = '<';
      }
      sprintf(str, " +--------------+      +--------------+");
      screen_area_puts(ge->map, str);
      sprintf(str, " |           %2d|      |%s  %-3.3s    %2d|      ", (int)id_left, player_get_gdesc(game_get_player(game)), c_gdesc, (int)id_act);
      screen_area_puts(ge->map, str);
      sprintf(str, " | %-9.9s    |      | %-9.9s    |", space_get_gdesc(game_get_space(game, id_left), 0), space_get_gdesc(game_get_space(game, id_act), 0));
      screen_area_puts(ge->map, str);
      sprintf(str, " | %-9.9s    |      | %-9.9s    |", space_get_gdesc(game_get_space(game, id_left), 1), space_get_gdesc(game_get_space(game, id_act), 1));
      screen_area_puts(ge->map, str);
      sprintf(str, " | %-9.9s    |   %c  | %-9.9s    |", space_get_gdesc(game_get_space(game, id_left), 2), link1, space_get_gdesc(game_get_space(game, id_act), 2));
      screen_area_puts(ge->map, str);
      sprintf(str, " | %-9.9s    |      | %-9.9s    |", space_get_gdesc(game_get_space(game, id_left), 3), space_get_gdesc(game_get_space(game, id_act), 3));
      screen_area_puts(ge->map, str);
      sprintf(str, " | %-9.9s    |      | %-9.9s    |  ", space_get_gdesc(game_get_space(game, id_left), 4), space_get_gdesc(game_get_space(game, id_act), 4));
      screen_area_puts(ge->map, str);
      sprintf(str, " +--------------+      +--------------+");
      screen_area_puts(ge->map, str);
    }

    if (id_act != NO_ID && id_left == NO_ID && id_right == NO_ID)
    {
      sprintf(str, "                       +--------------+      ");
      screen_area_puts(ge->map, str);
      sprintf(str, "                       |%s %-3.3s     %2d|      ", player_get_gdesc(game_get_player(game)), c_gdesc, (int)id_act);
      screen_area_puts(ge->map, str);
      sprintf(str, "                       | %-9.9s    |  ", space_get_gdesc(game_get_space(game, id_act), 0));
      screen_area_puts(ge->map, str);
      sprintf(str, "                       | %-9.9s    |  ", space_get_gdesc(game_get_space(game, id_act), 1));
      screen_area_puts(ge->map, str);
      sprintf(str, "                       | %-9.9s    |  ", space_get_gdesc(game_get_space(game, id_act), 2));
      screen_area_puts(ge->map, str);
      sprintf(str, "                       | %-9.9s    |  ", space_get_gdesc(game_get_space(game, id_act), 3));
      screen_area_puts(ge->map, str);
      sprintf(str, "                       | %-9.9s    |  ", space_get_gdesc(game_get_space(game, id_act), 4));
      screen_area_puts(ge->map, str);
      sprintf(str, "                       +--------------+");
      screen_area_puts(ge->map, str);
    }

    /* Paint next space */
    c_gdesc[0] = ' ';
    c_gdesc[1] = ' ';
    c_gdesc[2] = ' ';
    link1 = ' ';
    link2 = ' ';
    char_id = space_get_character(game_get_space(game, id_next));
    if (char_id != NO_ID)
    {
      strcpy(c_gdesc, character_get_gdesc(game_get_character_with_id(game, char_id)));
    }

    if (id_next != NO_ID)
    {
      if (game_connection_is_open(game, id_act, S)) {
        link1 = 'v';
      }

      if (space_get_discovered(game_get_space(game, id_next)) == TRUE) {
      sprintf(str, "                               %c", link1);
      screen_area_puts(ge->map, str);
      sprintf(str, "                       +--------------+");
      screen_area_puts(ge->map, str);
      sprintf(str, "                       |     %-3.3s    %2d|", c_gdesc, (int)id_next);
      screen_area_puts(ge->map, str);
      sprintf(str, "                       | %-9.9s    |  ", space_get_gdesc(game_get_space(game, id_next), 0));
      screen_area_puts(ge->map, str);
      sprintf(str, "                       | %-9.9s    |  ", space_get_gdesc(game_get_space(game, id_next), 1));
      screen_area_puts(ge->map, str);
      sprintf(str, "                       | %-9.9s    |  ", space_get_gdesc(game_get_space(game, id_next), 2));
      screen_area_puts(ge->map, str);
      sprintf(str, "                       | %-9.9s    |  ", space_get_gdesc(game_get_space(game, id_next), 3));
      screen_area_puts(ge->map, str);
      sprintf(str, "                       | %-9.9s    |  ", space_get_gdesc(game_get_space(game, id_next), 4));
      screen_area_puts(ge->map, str);
      sprintf(str, "                       +--------------+");
      screen_area_puts(ge->map, str);
      }

      else {
        sprintf(str, "                               %c", link1);
        screen_area_puts(ge->map, str);
        sprintf(str, "                       +--------------+");
        screen_area_puts(ge->map, str);
        sprintf(str, "                       |            %2d|", (int)id_next);
        screen_area_puts(ge->map, str);
        sprintf(str, "                       |              |  ");
        screen_area_puts(ge->map, str);
        sprintf(str, "                       |              |  ");
        screen_area_puts(ge->map, str);
        sprintf(str, "                       |              |  ");
        screen_area_puts(ge->map, str);
        sprintf(str, "                       |              |  ");
        screen_area_puts(ge->map, str);
        sprintf(str, "                       |              |  ");
        screen_area_puts(ge->map, str);
        sprintf(str, "                       +--------------+");
        screen_area_puts(ge->map, str);
      }
    }
  }
  /* Paint in the description area */
  screen_area_clear(ge->descript);
  /* Object description*/
  sprintf(str, "  Objects: ");
  screen_area_puts(ge->descript, str);
  for (i = 0; i < MAX_OBJECTS; i++)
  {
    sprintf(str, "    %s: %ld", object_get_name(game_get_object_at(game, i)), space_get_id(game_get_space(game, game_get_object_location(game, object_get_id(game_get_object_at(game, i))))));
    screen_area_puts(ge->descript, str);
  }

  sprintf(str, "  Id act: %ld ", id_act);
  screen_area_puts(ge->descript, str);
  sprintf(str, "  Id back: %ld ", id_back);
  screen_area_puts(ge->descript, str);
  sprintf(str, "  Id next: %ld ", id_next);
  screen_area_puts(ge->descript, str);
  sprintf(str, "  Id left: %ld ", id_left);
  screen_area_puts(ge->descript, str);
  sprintf(str, "  Id right: %ld ", id_right);
  screen_area_puts(ge->descript, str);

  /* Character description*/
  sprintf(str, "  Characters: ");
  screen_area_puts(ge->descript, str);

  for (i = 0; i < game_get_n_characters(game); i++)
  {
    sprintf(str, "    %s:  %ld (%d)", character_get_gdesc(game_get_character(game, i)), (game_get_character_location(game, character_get_id(game_get_character(game, i)))), character_get_health(game_get_character(game, i)));
    screen_area_puts(ge->descript, str);
  }

  /* Player description*/
  player_loc = game_get_player_location(game); /*Player location*/
  sprintf(str, "  Player:  %d  (%d)", (int)player_loc, player_get_health(game_get_player(game)));
  screen_area_puts(ge->descript, str);

  p_obj = inventory_get_n_objs(player_get_objects(game_get_player(game)));
  if (p_obj > 0)
  {
    /* Hay que cambiar esto para que printee todos los objetos*/
    sprintf(str, "      Player has object: YES");
    screen_area_puts(ge->descript, str);
    sprintf(str, "  %s", object_get_name(game_get_object_with_id(game, inventory_find_object(player_get_objects(game_get_player(game)), 0))));
    screen_area_puts(ge->descript, str);
  }
  else
  {
    sprintf(str, "      Player has no objects");
    screen_area_puts(ge->descript, str);
  }

  /* Paint in the banner area */
  screen_area_clear(ge->banner);
  screen_area_puts(ge->banner, "The haunted castle game");

  /* Paint in the help area */
  screen_area_clear(ge->help);
  sprintf(str, " The commands you can use are:");
  screen_area_puts(ge->help, str);
  sprintf(str, "    move or m, take or t, drop or d, attack or a, chat or c, inspect or i, exit or e");
  screen_area_puts(ge->help, str);

  /* Paint in the feedback area */
  last_cmd = command_get_code(game_get_last_command(game));
  if (command_get_status(game_get_last_command(game)) == ERROR)
  {
    stat = "ERROR";
  }
  else if ((command_get_status(game_get_last_command(game)) == -1))
  {
    stat = "";
  }
  else if ((command_get_status(game_get_last_command(game)) == -2))
  {
    stat = command_get_description(game_get_last_command(game));
  }
  else if ((command_get_status(game_get_last_command(game)) == OK))
  {
    stat = "OK";
  }
  sprintf(str, " %s (%s): %s", cmd_to_str[last_cmd - NO_CMD][CMDL], cmd_to_str[last_cmd - NO_CMD][CMDS], stat);
  screen_area_puts(ge->feedback, str);

  /* Dump to the terminal */
  screen_paint();
  printf("prompt:> ");
}