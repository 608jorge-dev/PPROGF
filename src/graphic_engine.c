
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

void graphic_engine_paint_blank (Graphic_engine *ge) 
{
  int i;
  char str[255];

  sprintf(str, "                                       ");
  screen_area_puts(ge->map, str);
  for  (i=0; i< HEIGHT_BLANK; i++ ) {
    sprintf(str, "                                       ");
   screen_area_puts(ge->map, str);
  }
}

void graphic_engine_paint_blankspace(Graphic_engine *ge, Id id) 
{
  int i;
  char str[255];

  sprintf(str, "                       +--------------+");
  screen_area_puts(ge->map, str);
  sprintf(str, "                       |            %2d|", (int)id);
  screen_area_puts(ge->map, str);
  for (i=0; i<MAX_S; i++) {
    sprintf(str, "                       |              |  ");
    screen_area_puts(ge->map, str);
  }
  sprintf(str, "                       +--------------+");
  screen_area_puts(ge->map, str);
}

void graphic_engine_paint_northspace(Game *game, Id id_north, Id id_act, Graphic_engine *ge) {
  char str[255], c_gdesc[WORD_SIZE], link1 = 'X', obj[WORD_SIZE];
  int i;
  Id char_id = NO_ID;
  Object *ob;

  /* CHARACTER GDESC*/
  for (i=0; i<MAX_SPACES; i++)  {
    c_gdesc[i] = ' ';
  }
  char_id = space_get_character(game_get_space(game, id_north));
  if (char_id != NO_ID)
  {
    strcpy(c_gdesc, character_get_gdesc(game_get_character_with_id(game, char_id)));
  }
  /*OBJECT NAME*/
  for (i=0; i<game_get_n_objects(game); i++)  {
    ob = game_get_object_at(game, i);
    if (set_find(space_get_objects(game_get_space(game, id_north)), object_get_id(ob)) == TRUE)  {
      strcpy (obj,  object_get_name(game_get_object_at(game, i)));
    }
  }
  
  if (id_north != NO_ID)
  {
    if (space_get_discovered(game_get_space(game, id_north)) == TRUE)  
    {
      sprintf(str, "                       +--------------+");
      screen_area_puts(ge->map, str);
      sprintf(str, "                       |     %-3.3s    %2d|", c_gdesc, (int)id_north);
      screen_area_puts(ge->map, str);
      for (i=0; i<MAX_S; i++) {
        sprintf(str, "                       |%-9.9s     |  ", space_get_gdesc(game_get_space(game, id_north), i));
        screen_area_puts(ge->map, str);
      }
      sprintf(str, "                       |%-9.9s     |  ", obj);
      screen_area_puts(ge->map, str);
      sprintf(str, "                       +--------------+");
      screen_area_puts(ge->map, str);
    }
    else 
    {
      graphic_engine_paint_blankspace (ge, id_north);
    }

    if (game_connection_is_open(game, id_act, N)) 
    {
      link1 = '^';
    }
    sprintf(str, "                               %c", link1);
    screen_area_puts(ge->map, str);
    }

  else 
  {
    graphic_engine_paint_blank(ge);
  }
}

void graphic_engine_paint_southspace(Game *game, Id id_south, Id id_act, Graphic_engine *ge) {
  char str[255], c_gdesc[WORD_SIZE], link1 = 'X', link2 = 'X';
  int i;
  Id char_id = NO_ID;

  for (i=0; i<MAX_SPACES; i++)  {
    c_gdesc[i] = ' ';
  }
  char_id = space_get_character(game_get_space(game, id_south));
  if (char_id != NO_ID)
  {
    strcpy(c_gdesc, character_get_gdesc(game_get_character_with_id(game, char_id)));
  }

  if (id_south != NO_ID)
  {
    if (game_connection_is_open(game, id_act, S)) {
      link1 = 'v';
    }
    sprintf(str, "                              %c", link1);
    screen_area_puts(ge->map, str);
    if (space_get_discovered(game_get_space(game, id_south)) == TRUE) {
      sprintf(str, "                       +--------------+");
      screen_area_puts(ge->map, str);
      sprintf(str, "                       |     %-3.3s    %2d|", c_gdesc, (int)id_south);
      screen_area_puts(ge->map, str);
      for (i=0; i<MAX_S; i++) {
        sprintf(str, "                       | %-9.9s    |  ", space_get_gdesc(game_get_space(game, id_south), i));
        screen_area_puts(ge->map, str);
      }
      sprintf(str, "                       +--------------+");
      screen_area_puts(ge->map, str);
    }

    else {
      graphic_engine_paint_blankspace(ge, id_south);
    }
  }
  else {
    graphic_engine_paint_blank(ge);
  }
}


/** Changes the game GUI (paints in the differente graphic sections)
 */
void graphic_engine_paint_game(Graphic_engine *ge, Game *game)
{
  Id id_act = NO_ID, id_north = NO_ID, id_south = NO_ID, id_west = NO_ID, id_east = NO_ID;
  int i;
  char c_gdesc[WORD_SIZE], c_gdesc1[WORD_SIZE], c_gdesc2[WORD_SIZE], link1 = 'X', link2 = 'X';
  char str[255];
  char *stat = NULL;
  Id p_obj = NO_ID, player_loc = NO_ID, char_id = NO_ID;
  CommandCode last_cmd = UNKNOWN;
  extern char *cmd_to_str[N_CMD][N_CMDT];

  /* Paint the in the map area */
  screen_area_clear(ge->map);
  if ((id_act = game_get_player_location(game)) != NO_ID)
  {
    id_north = game_get_connection(game, id_act, 0);
    id_south = game_get_connection(game, id_act, 1);
    id_west = game_get_connection(game, id_act, 3);
    id_east = game_get_connection(game, id_act, 2);

    /* PAINTING NORTH SPACE */
    graphic_engine_paint_northspace(game, id_north, id_act, ge);
    
    /* PAINTING CURRENT SPACE */
    for (i=0; i<MAX_SPACES; i++)  {
      c_gdesc[i] = ' ';
      c_gdesc1[i] = ' ';
      c_gdesc2[i] = ' ';
    }
    link1 = 'X';
    link2 = 'X';

    if (id_act != NO_ID && id_east != NO_ID && id_west != NO_ID)
    {
      if (game_connection_is_open(game, id_act, W)) 
      {
        link1 = '<';
      }
      if (game_connection_is_open(game, id_act, E)) 
      {
        link2 = '>';
      }
      sprintf(str, "  +--------------+    +--------------+      +--------------+");
      screen_area_puts(ge->map, str);
      sprintf(str, "  |            %2d|    | %s %-3.3s   %2d|      |           %2d|", (int)id_west, player_get_gdesc(game_get_player(game)), c_gdesc, (int)id_act, (int)id_east);
      screen_area_puts(ge->map, str);
      if (space_get_discovered(game_get_space(game, id_west)) == FALSE && space_get_discovered(game_get_space(game, id_east)) == TRUE)   {
        id_west = NUL;
      }
      if (space_get_discovered(game_get_space(game, id_west)) == TRUE && space_get_discovered(game_get_space(game, id_east)) == FALSE)   {
        id_east= NUL;
      }
      if (space_get_discovered(game_get_space(game, id_west)) == FALSE && space_get_discovered(game_get_space(game, id_east)) == FALSE)   {
        id_east= NUL;
        id_west = NUL;
      }

      for (i=0; i<MAX_S; i++) {
        sprintf(str, "  | %-9.9s    |    | %-9.9s    |      | %-9.9s    |", space_get_gdesc(game_get_space(game, id_west), i), space_get_gdesc(game_get_space(game, id_act), 0), space_get_gdesc(game_get_space(game, id_east), i));
        screen_area_puts(ge->map, str);
      }
      sprintf(str, "  +--------------+    +--------------+      +--------------+");
      screen_area_puts(ge->map, str);
      id_west = game_get_connection(game, id_act, 3);
      id_east = game_get_connection(game, id_act, 2);
    }

    if (id_act != NO_ID && id_east != NO_ID && id_west == NO_ID)
    {
      if (game_connection_is_open(game, id_act, E)) {
        link2 = '>';
      }      
      sprintf(str, "                       +--------------+      +--------------+");
      screen_area_puts(ge->map, str);
      sprintf(str, "                       |  %s  %-3.3s  %2d|      |           %2d|", player_get_gdesc(game_get_player(game)), c_gdesc, (int)id_act, (int)id_east);
      screen_area_puts(ge->map, str);
      if (space_get_discovered(game_get_space(game, id_east)) != TRUE ) {
        id_east = NUL;
      }
      sprintf(str, "                       | %-9.9s    |      | %-9.9s    |", space_get_gdesc(game_get_space(game, id_act), 0), space_get_gdesc(game_get_space(game, id_east), 0));
      screen_area_puts(ge->map, str);
      sprintf(str, "                       | %-9.9s    |   %c  | %-9.9s    |", space_get_gdesc(game_get_space(game, id_act), 1), link2,  space_get_gdesc(game_get_space(game, id_east), 1));
      screen_area_puts(ge->map, str);
      sprintf(str, "                       | %-9.9s    |      | %-9.9s    |", space_get_gdesc(game_get_space(game, id_act), 2), space_get_gdesc(game_get_space(game, id_east), 2));
      screen_area_puts(ge->map, str);
      sprintf(str, "                       | %-9.9s    |      | %-9.9s    | ", space_get_gdesc(game_get_space(game, id_act), 3), space_get_gdesc(game_get_space(game, id_east), 3));
      screen_area_puts(ge->map, str);
      sprintf(str, "                       | %-9.9s    |      | %-9.9s    | ", space_get_gdesc(game_get_space(game, id_act), 4), space_get_gdesc(game_get_space(game, id_east), 4));
      screen_area_puts(ge->map, str);
      sprintf(str, "                       +--------------+      +--------------+");
      screen_area_puts(ge->map, str);
    }

    if (id_act != NO_ID && id_west != NO_ID && id_east == NO_ID)
    {
      if (game_connection_is_open(game, id_act, W)) {
        link1 = '<';
      }
      sprintf(str, " +--------------+      +--------------+");
      screen_area_puts(ge->map, str);
      sprintf(str, " |           %2d|      |%-3.3s  %-3.3s    %2d|      ", (int)id_west, player_get_gdesc(game_get_player(game)), c_gdesc, (int)id_act);
      screen_area_puts(ge->map, str);
      if (space_get_discovered(game_get_space(game, id_west)) != TRUE ) {
        id_west = NUL;
      }
      sprintf(str, " | %-9.9s    |      | %-9.9s    |", space_get_gdesc(game_get_space(game, id_west), 0), space_get_gdesc(game_get_space(game, id_act), 0));
      screen_area_puts(ge->map, str);
      sprintf(str, " | %-9.9s    |      | %-9.9s    |", space_get_gdesc(game_get_space(game, id_west), 1), space_get_gdesc(game_get_space(game, id_act), 1));
      screen_area_puts(ge->map, str);
      sprintf(str, " | %-9.9s    |   %c  | %-9.9s    |", space_get_gdesc(game_get_space(game, id_west), 2), link1, space_get_gdesc(game_get_space(game, id_act), 2));
      screen_area_puts(ge->map, str);
      sprintf(str, " | %-9.9s    |      | %-9.9s    |", space_get_gdesc(game_get_space(game, id_west), 3), space_get_gdesc(game_get_space(game, id_act), 3));
      screen_area_puts(ge->map, str);
      sprintf(str, " | %-9.9s    |      | %-9.9s    |  ", space_get_gdesc(game_get_space(game, id_west), 4), space_get_gdesc(game_get_space(game, id_act), 4));
      screen_area_puts(ge->map, str);
      sprintf(str, " +--------------+      +--------------+");
      screen_area_puts(ge->map, str);
      id_west = game_get_connection(game, id_act, 3);
    }

    if (id_act != NO_ID && id_west == NO_ID && id_east == NO_ID)
    {
      sprintf(str, "                       +--------------+      ");
      screen_area_puts(ge->map, str);
      sprintf(str, "                       |%s %-3.3s     %2d|      ", player_get_gdesc(game_get_player(game)), c_gdesc, (int)id_act);
      screen_area_puts(ge->map, str);
      for (i=0; i< MAX_S; i++)  {
        sprintf(str, "                       | %-9.9s    |  ", space_get_gdesc(game_get_space(game, id_act), i));
        screen_area_puts(ge->map, str);
      }
      sprintf(str, "                       +--------------+");
      screen_area_puts(ge->map, str);
    }

    /* PAINT SOUTH SPACE*/
    graphic_engine_paint_southspace(game, id_south, id_act, ge);
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
  screen_area_puts(ge->banner, "   The haunted castle game");

  /* Paint in the help area */
  screen_area_clear(ge->help);
  sprintf(str, " The commands you can use are:");
  screen_area_puts(ge->help, str);
  sprintf(str, "    move or m (north, south, west, east), take or t, drop or d, attack or a, chat or c, inspect or i, exit or e");
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


