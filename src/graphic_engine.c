/**
 * @brief It implements a textual graphic engine
 *
 * @file graphic_engine.c
 * @author Jorge Torrijos de la Cruz
 * @version 7.0
 * @date 28-04-2026
 * @copyright GNU Public License
 */

#include "graphic_engine.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Graphic engine
 *
 * This struct stores all the information related to the graphic engine.
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

/** It paints a blank space in the map
 */
void graphic_engine_paint_blank(Graphic_engine *ge)
{
  int i;
  char str[255];

  sprintf(str, "                                         ");
  screen_area_puts(ge->map, str);
  for (i = 0; i < HEIGHT_BLANK; i++)
  {
    sprintf(str, "                                         ");
    screen_area_puts(ge->map, str);
  }
}

/** It paints a space without a graphic description in the map
 */
void graphic_engine_paint_blankspace(Graphic_engine *ge, Id id)
{
  int i;
  char str[255];

  sprintf(str, "                         +----------------+");
  screen_area_puts(ge->map, str);
  sprintf(str, "                         |              %2d|", (int)id);
  screen_area_puts(ge->map, str);
  for (i = 0; i < MAX_S + 1; i++)
  {
    sprintf(str, "                         |                |  ");
    screen_area_puts(ge->map, str);
  }
  sprintf(str, "                         +----------------+");
  screen_area_puts(ge->map, str);
}

char *graphic_engine_get_objects(Game *game, Id id_paint, Graphic_engine *ge)
{
  int i;
  char obj[MAC_SIZE + 1], *obs = NULL;
  Object *ob = NULL;

  for (i = 0; i < MAC_SIZE; i++)
  {
    obj[i] = ' ';
  }
  obj[MAC_SIZE] = '\0';

  for (i = 0; i < game_get_n_objects(game); i++)
  {
    ob = game_get_object_at(game, i);
    if (set_find(space_get_objects(game_get_space(game, id_paint)), object_get_id(ob)) == TRUE)
    {
      strcat(obj, object_get_name(ob));
    }
  }

  strcpy(obs, obj);
  return obs;
}

char *graphic_engine_get_characters(Game *game, Id id_paint, Graphic_engine *ge)
{
  int i;
  char charac[MAC_SIZE + 1], *chs = NULL;
  Character *ch = NULL;

  for (i = 0; i < MAC_SIZE; i++)
  {
    charac[i] = ' ';
  }
  charac[MAC_SIZE] = '\0';

  for (i = 0; i < game_get_n_characters(game); i++)
  {
    ch = game_get_character_at(game, i);
    if (set_find(space_get_characters(game_get_space(game, id_paint)), character_get_id(ch)) == TRUE)
    {
      strcat(charac, character_get_gdesc(ch));
    }
  }

  strcpy(chs, charac);
  return chs;
}

/** It paints the space on the north of the actual space
 */
void graphic_engine_paint_northorsouthspace(Game *game, Id id_paint, Id id_act, Graphic_engine *ge, int D)
{
  char str[255], link1 = 'X', ob[MAC_SIZE + 1], ch[MAC_SIZE + 1];
  int i = 0;

  /* CHARACTER GDESC*/
  strcpy(ch, graphic_engine_get_characters(game, id_paint, ge));
  /*OBJECT NAME*/
  strcpy(ob, graphic_engine_get_objects(game, id_paint, ge));

  /* SPACE PRINTING*/
  if (id_paint != NO_ID)
  {
    if (game_connection_is_open(game, id_act, S) == TRUE && D == 0)
    {
      link1 = 'v';
      sprintf(str, "                                %c", link1);
      screen_area_puts(ge->map, str);
    }
    if (space_get_discovered(game_get_space(game, id_paint)) == TRUE)
    {
      sprintf(str, "                         +----------------+");
      screen_area_puts(ge->map, str);
      sprintf(str, "                         |      %-3.3s     %2d|", ch, (int)id_paint);
      screen_area_puts(ge->map, str);
      for (i = 0; i < MAX_S; i++)
      {
        sprintf(str, "                         |   %-9.9s    |  ", space_get_gdesc(game_get_space(game, id_paint), i));
        screen_area_puts(ge->map, str);
      }
      sprintf(str, "                         | %-12.12s |  ", ob);
      screen_area_puts(ge->map, str);
      sprintf(str, "                         +----------------+");
      screen_area_puts(ge->map, str);
    }
    else
    {
      graphic_engine_paint_blankspace(ge, id_paint);
    }

    if (game_connection_is_open(game, id_act, N) == TRUE && D == 1)
    {
      link1 = '^';
      sprintf(str, "                                %c", link1);
      screen_area_puts(ge->map, str);
    }
  }

  else
  {
    graphic_engine_paint_blank(ge);
  }
}

/** It paints the actual space
 */
void graphic_engine_paint_currentspace(Game *game, Id id_west, Id id_east, Id id_act, Graphic_engine *ge)
{
  char str[255], ch[MAC_SIZE], ch1[MAC_SIZE], ch2[MAC_SIZE], link1 = 'X', link2 = 'X', ob[MAC_SIZE], ob1[MAC_SIZE], ob2[MAC_SIZE];
  int i;

  /* CHARACTER GDESC*/
  strcpy(ch, graphic_engine_get_characters(game, id_act, ge));
  strcpy(ch1, graphic_engine_get_characters(game, id_east, ge));
  strcpy(ch2, graphic_engine_get_characters(game, id_west, ge));

  /*OBJECT NAME*/
  strcpy(ob, graphic_engine_get_objects(game, id_act, ge));
  strcpy(ob1, graphic_engine_get_objects(game, id_east, ge));
  strcpy(ob2, graphic_engine_get_objects(game, id_west, ge));

  /* SPACE PRINTING*/
  /*EAST, ACT, WEST*/
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
    sprintf(str, "  +----------------+      +----------------+     +----------------+");
    screen_area_puts(ge->map, str);
    sprintf(str, "  |    %-3.3s       %2d|      | %s %-3.3s     %2d|     |  %-3.3s        %2d|", ch1, (int)id_west, player_get_gdesc(game_get_player(game)), ch, (int)id_act, ch2, (int)id_east);
    screen_area_puts(ge->map, str);
    if (space_get_discovered(game_get_space(game, id_west)) == FALSE)
    {
      id_west = NUL;
    }
    if (space_get_discovered(game_get_space(game, id_east)) == FALSE)
    {
      id_east = NUL;
    }

    for (i = 0; i < MAX_S; i++)
    {
      sprintf(str, "  |   %-9.9s    |      |   %-9.9s    |     |    %-9.9s   |", space_get_gdesc(game_get_space(game, id_west), i), space_get_gdesc(game_get_space(game, id_act), i), space_get_gdesc(game_get_space(game, id_east), i));
      screen_area_puts(ge->map, str);
    }
    sprintf(str, "  | %-12.12s |   %c  | %-12.12s |  %c  | %-12.12s |", ob1, link1, ob, link2, ob2);
    screen_area_puts(ge->map, str);
    sprintf(str, "  +----------------+      +----------------+     +----------------+");
    screen_area_puts(ge->map, str);
    id_west = game_get_connection(game, id_act, 3);
    id_east = game_get_connection(game, id_act, 2);
  }

  /*ACT, WEST*/
  if (id_act != NO_ID && id_east != NO_ID && id_west == NO_ID)
  {
    if (game_connection_is_open(game, id_act, E))
    {
      link2 = '>';
    }
    sprintf(str, "                         +----------------+     +----------------+");
    screen_area_puts(ge->map, str);
    sprintf(str, "                         |  %s  %-3.3s    %2d|     |       %-3.3s   %2d|", player_get_gdesc(game_get_player(game)), ch, (int)id_act, ch2, (int)id_east);
    screen_area_puts(ge->map, str);
    if (space_get_discovered(game_get_space(game, id_east)) != TRUE)
    {
      id_east = NUL;
    }
    for (i = 0; i < MAX_S; i++)
    {
      sprintf(str, "                         |   %-9.9s    |     |   %-9.9s    |", space_get_gdesc(game_get_space(game, id_act), i), space_get_gdesc(game_get_space(game, id_east), i));
      screen_area_puts(ge->map, str);
    }
    sprintf(str, "                         | %-12.12s |  %c  | %-12.12s |", ob, link2, ob2);
    screen_area_puts(ge->map, str);
    sprintf(str, "                         +----------------+     +----------------+");
    screen_area_puts(ge->map, str);
  }

  /*EAST, ACT*/
  if (id_act != NO_ID && id_west != NO_ID && id_east == NO_ID)
  {
    if (game_connection_is_open(game, id_act, W))
    {
      link1 = '<';
    }
    sprintf(str, " +----------------+      +----------------+");
    screen_area_puts(ge->map, str);
    sprintf(str, " |    %-3.3s      %2d|      | %-3.3s  %-5.5s   %2d|      ", ch1, (int)id_west, player_get_gdesc(game_get_player(game)), ch, (int)id_act);
    screen_area_puts(ge->map, str);
    if (space_get_discovered(game_get_space(game, id_west)) != TRUE)
    {
      id_west = NUL;
    }
    for (i = 0; i < MAX_S; i++)
    {
      sprintf(str, " | %-9.9s      |      |  %-9.9s     |", space_get_gdesc(game_get_space(game, id_west), i), space_get_gdesc(game_get_space(game, id_act), i));
      screen_area_puts(ge->map, str);
    }
    sprintf(str, " | %-12.12s |  %c   | %-12.12s |", ob1, link1, ob2);
    screen_area_puts(ge->map, str);
    sprintf(str, " +----------------+      +----------------+");
    screen_area_puts(ge->map, str);
    id_west = game_get_connection(game, id_act, 3);
  }

  /*ACT*/
  if (id_act != NO_ID && id_west == NO_ID && id_east == NO_ID)
  {
    sprintf(str, "                         +----------------+      ");
    screen_area_puts(ge->map, str);
    sprintf(str, "                         | %-3.3s %-3.3s      %2d|      ", player_get_gdesc(game_get_player(game)), ch, (int)id_act);
    screen_area_puts(ge->map, str);
    for (i = 0; i < MAX_S; i++)
    {
      sprintf(str, "                         |   %-9.9s    |  ", space_get_gdesc(game_get_space(game, id_act), i));
      screen_area_puts(ge->map, str);
    }
    sprintf(str, "                         | %-12.12s |  ", ob);
    screen_area_puts(ge->map, str);
    sprintf(str, "                         +----------------+");
    screen_area_puts(ge->map, str);
  }
}

/** Changes the game GUI (paints in the differente graphic sections)
 */
void graphic_engine_paint_game(Graphic_engine *ge, Game *game)
{
  Id id_act = NO_ID, id_north = NO_ID, id_south = NO_ID, id_west = NO_ID, id_east = NO_ID;
  int i;
  char str[255], last_chat[MAC_SIZE], last_inspect[MAC_SIZE];
  char *stat = NULL;
  Id p_obj = NO_ID, player_loc = NO_ID;
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
    graphic_engine_paint_northorsouthspace(game, id_north, id_act, ge, 1);

    /* PAINTING CURRENT SPACE */
    graphic_engine_paint_currentspace(game, id_west, id_east, id_act, ge);

    /* PAINT SOUTH SPACE*/
    graphic_engine_paint_northorsouthspace(game, id_south, id_act, ge, 0);
  }

  /* Paint in the description area */
  screen_area_clear(ge->descript);
  /* Object description*/
  sprintf(str, "  Objects: ");
  screen_area_puts(ge->descript, str);
  for (i = 0; i < game_get_n_objects(game); i++)
  {
    if (game_get_object_discovered(game, object_get_id(game_get_object_at(game, i))))
    {
      sprintf(str, "    %s: %ld", object_get_name(game_get_object_at(game, i)), space_get_id(game_get_space(game, game_get_object_location(game, object_get_id(game_get_object_at(game, i))))));
      screen_area_puts(ge->descript, str);
    }
  }

  /* Character description*/
  sprintf(str, "  Characters: ");
  screen_area_puts(ge->descript, str);

  for (i = 0; i < game_get_n_characters(game); i++)
  {
    if (character_get_health(game_get_character_at(game, i)) > 0 && game_get_character_discovered(game, character_get_id(game_get_character_at(game, i))))
    {
      sprintf(str, "    %s:  %ld (%d)", character_get_gdesc(game_get_character_at(game, i)), (game_get_character_location(game, character_get_id(game_get_character_at(game, i)))), character_get_health(game_get_character_at(game, i)));
      screen_area_puts(ge->descript, str);
    }
  }

  /* Player description*/
  player_loc = game_get_player_location(game); /*Player location*/
  sprintf(str, "  Player:  %d  (%d)", (int)player_loc, player_get_health(game_get_player(game)));
  screen_area_puts(ge->descript, str);

  p_obj = inventory_get_n_objs(player_get_objects(game_get_player(game)));
  if (p_obj > 0)
  {
    sprintf(str, "  Player has object (%d/%d): YES", inventory_get_n_objs(player_get_objects(game_get_player(game))), inventory_get_max_objs(player_get_objects(game_get_player(game))));
    screen_area_puts(ge->descript, str);
    for (i = 0; i < inventory_get_n_objs(player_get_objects(game_get_player(game))); i++)
    {
      sprintf(str, "  - %s", object_get_name(game_get_object_with_id(game, set_get_id_at(inventory_get_objs(player_get_objects(game_get_player(game))), i))));
      screen_area_puts(ge->descript, str);
    }
  }
  else
  {
    sprintf(str, "  Player has no objects");
    screen_area_puts(ge->descript, str);
  }

  /* LAST CHAT AND LAST INSPECT*/
  for (i = 0; i < 5; i++)
  {
    last_chat[i] = ' ';
    last_inspect[i] = ' ';
  }
  if (playerinf_get_lastchat(game_get_playerinf(game)))
  {
    strcpy(last_chat, playerinf_get_lastchat(game_get_playerinf(game)));
  }
  if (playerinf_get_lastinspect(game_get_playerinf(game)))
  {
    strcpy(last_inspect, playerinf_get_lastinspect(game_get_playerinf(game)));
  }
  sprintf(str, "  Chat: %s", last_chat);
  screen_area_puts(ge->descript, str);
  sprintf(str, "  Inspect: %s", last_inspect);
  screen_area_puts(ge->descript, str);
  /* Paint in the banner area */
  screen_area_clear(ge->banner);
  screen_area_puts(ge->banner, "   The haunted castle game");
  sprintf(str, "         PLAYER %d", game_get_turn(game));
  screen_area_puts(ge->banner, str);

  /* Paint in the help area */
  screen_area_clear(ge->help);
  sprintf(str, " The commands you can use are:");
  screen_area_puts(ge->help, str);
  sprintf(str, "    move or m (north, south, west, east), take or t, drop or d, attack or a, chat or c, inspect or i, recruit or r, abandon or ab, use or u, open or o, exit or e");
  screen_area_puts(ge->help, str);

  /* Paint in the feedback area */
  screen_area_clear(ge->feedback);
  last_cmd = playerinf_get_lastcommand(game_get_playerinf(game));
  if (playerinf_get_laststatus(game_get_playerinf(game)) == FALSE)
  {
    stat = "ERROR";
  }
  if (playerinf_get_laststatus(game_get_playerinf(game)) == -1)
  {
    stat = " ";
  }
  else if (playerinf_get_laststatus(game_get_playerinf(game)) == TRUE)
  {
    stat = "OK";
  }
  sprintf(str, " %s (%s): %s", cmd_to_str[last_cmd - NO_CMD][CMDL], cmd_to_str[last_cmd - NO_CMD][CMDS], stat);
  screen_area_puts(ge->feedback, str);

  /* Dump to the terminal */
  screen_paint(BLACK);
  printf("prompt:> ");
}
