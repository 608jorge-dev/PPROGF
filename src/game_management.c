
/**
 * @brief It implements the game management interface
 *
 * @file game_management.c
 * @author Guillermo Núñez Bravo, Iván Rodríguez Camacho, Jorge Torrijos de la Cruz
 * @version 7.0
 * @date 28-04-26
 * @copyright GNU Public License
 */

#include "game_management.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Saves in a file the game progress data
 */
Status game_management_save(Game *game, char *filename)
{
    FILE *f = NULL;
    int i = 0;
    Space *s = NULL;
    Object *o = NULL;
    Character *c = NULL;
    Player *p = NULL;
    Link *l = NULL;

    if (!filename || !game)
    {
        return ERROR;
    }

    f = fopen(filename, "w");
    if (!f)
    {
        return ERROR;
    }

    while (game_get_space_at(game, i) != NULL)
    {
        s = game_get_space_at(game, i);
        fprintf(f, "#s:%ld|%s|%s|%s|%s|%s|%s|%d| \n", space_get_id(s), space_get_name(s), space_get_gdesc(s, 0), space_get_gdesc(s, 1), space_get_gdesc(s, 2), space_get_gdesc(s, 3), space_get_gdesc(s, 4), space_get_discovered(s));

        i++;
    }

    i = 0;

    fprintf(f, "\n");

    while (game_get_object_at(game, i) != NULL)
    {
        o = game_get_object_at(game, i);
        fprintf(f, "#o:%ld|%s|%ld|%s|%d|%ld|  \n", object_get_id(o), object_get_name(o), game_get_object_location(game, object_get_id(o)), object_get_desc(o), object_get_movable(o), object_get_dependency(o));
        i++;
    }

    i = 0;

    fprintf(f, "\n\n");

    while (game_get_character_at(game, i) != NULL)
    {
        c = game_get_character_at(game, i);
        fprintf(f, "#c:%ld|%s|%s|%ld|%d|%hu|%s| \n", character_get_id(c), character_get_name(c), character_get_gdesc(c), game_get_character_location(game, character_get_id(c)), character_get_health(c), character_get_friendly(c), character_get_message(c));
        i++;
    }

    i = 0;

    fprintf(f, "\n");

    while (game_get_player_at(game, i) != NULL)
    {
        p = game_get_player_at(game, i);
        fprintf(f, "#p:%ld|%s|%s|%d|%ld|%d| \n", player_get_id(p), player_get_name(p), player_get_gdesc(p), player_get_health(p), player_get_location(p), inventory_get_max_objs(player_get_objects(p)));
        i++;
    }

    i = 0;

    fprintf(f, "\n");
    fprintf(f, "\n");

    while (game_get_link_at(game, i) != NULL)
    {
        l = game_get_link_at(game, i);

        fprintf(f, "#l:%ld|%s|%ld|%ld|%d|%d| \n", link_get_id(l), link_get_name(l), link_get_origin(l), link_get_destination(l), link_get_direction(l), link_get_open(l));
        i++;
    }

    fprintf(f, "\n");

    return OK;
}

/* Loads the whole game read on file
 */
Status game_management_load(Game *game, char *filename)
{
    if (game_management_load_spaces(game, filename) == ERROR)
    {
        return ERROR;
    }

    if (game_management_load_objects(game, filename) == ERROR)
    {
        return ERROR;
    }
  
    if (game_management_load_characters(game, filename) == ERROR)
    {
        return ERROR;
    }

    if (game_management_load_spaces(game, filename) == ERROR)
    {
        return ERROR;
    }

    if (game_management_load_player(game, filename) == ERROR)
    {
        return ERROR;
    }

    if (game_management_load_link(game, filename) == ERROR)
    {
        return ERROR;
    }

    return OK;
}

/* Loads the spaces read on file
 */
Status game_management_load_spaces(Game *game, char *filename)
{
    FILE *file = NULL;
    char line[WORD_SIZE] = "";
    char name[WORD_SIZE] = "";
    char g1[WORD_SIZE] = "", g2[WORD_SIZE] = "", g3[WORD_SIZE] = "", g4[WORD_SIZE] = "", g5[WORD_SIZE] = "";
    char *toks = NULL;
    Id id = NO_ID;
    Space *space = NULL;
    Bool disc;
    Status status = OK;

    if (!filename)
    {
        return ERROR;
    }

    file = fopen(filename, "r");
    if (file == NULL)
    {
        return ERROR;
    }

    while (fgets(line, WORD_SIZE, file))
    {
        if (strncmp("#s:", line, 3) == 0)
        {
            toks = strtok(line + 3, "|");
            id = atol(toks);
            toks = strtok(NULL, "|");
            strcpy(name, toks);
            toks = strtok(NULL, "|");
            strcpy(g1, toks);
            toks = strtok(NULL, "|");
            strcpy(g2, toks);
            toks = strtok(NULL, "|");
            strcpy(g3, toks);
            toks = strtok(NULL, "|");
            strcpy(g4, toks);
            toks = strtok(NULL, "|");
            strcpy(g5, toks);
            toks = strtok(NULL, "|");
            disc = atol(toks);

#ifdef DEBUG
            printf("Leido: s:%ld|%s|\n", id, name);
#endif
            space = space_create(id);
            if (space != NULL)
            {
                space_set_name(space, name);
                space_set_gdesc(space, 0, g1);
                space_set_gdesc(space, 1, g2);
                space_set_gdesc(space, 2, g3);
                space_set_gdesc(space, 3, g4);
                space_set_gdesc(space, 4, g5);
                space_set_discovered(space, disc);
                game_add_space(game, space);
            }
        }
    }

    if (ferror(file))
    {
        status = ERROR;
        free(space);
    }

    fclose(file);

    return status;
}

/* Loads the objects read on file
 */
Status game_management_load_objects(Game *game, char *filename)
{
    FILE *file = NULL;
    Object *object = NULL;
    char *toks = NULL;
    char line[WORD_SIZE] = "\0";
    char name[WORD_SIZE] = "\0";
    char desc[WORD_SIZE] = "\0";
    Id object_id = NO_ID, space_id = NO_ID;
    Status status = OK;

    if (!filename)
    {
        return ERROR;
    }

    file = fopen(filename, "r");
    if (file == NULL)
    {
        return ERROR;
    }

    while (fgets(line, WORD_SIZE, file))
    {
        if (strncmp("#o:", line, 3) == 0)
        {
            toks = strtok(line + 3, "|");
            object_id = atol(toks);
            toks = strtok(NULL, "|");
            strcpy(name, toks);
            toks = strtok(NULL, "|");
            if (toks)
                space_id = atol(toks);
            toks = strtok(NULL, "|");
            strcpy(desc, toks);

            object = object_create(object_id);
            if (object != NULL)
            {
                object_set_name(object, name);
                object_set_desc(object, desc);
                game_add_object(game, object);
                game_set_object_location(game, space_id, object_id);
            }
        }
    }
#ifdef DEBUG
    printf("Leido: o:%ld|%s|%ld\n", object_id, name, space_id);
#endif

    if (ferror(file))
    {
        status = ERROR;
        free(object);
    }
    fclose(file);

    return status;
}

/* Loads the characters read on file
 */
Status game_management_load_characters(Game *game, char *filename)
{
    FILE *file = NULL;
    Character *character = NULL;
    char *toks = NULL;
    char line[WORD_SIZE] = "\0";
    char name[WORD_SIZE] = "\0";
    char gdesc[WORD_SIZE] = "\0";
    char message[WORD_SIZE] = "\0";
    Id character_id = NO_ID, space_id = NO_ID;
    Status status = OK;
    int health = 0;
    Bool friendly = TRUE;

    if (!filename)
    {
        return ERROR;
    }

    file = fopen(filename, "r");
    if (file == NULL)
    {
        return ERROR;
    }

    while (fgets(line, WORD_SIZE, file))
    {
        if (strncmp("#c:", line, 3) == 0)
        {
            toks = strtok(line + 3, "|");
            character_id = atol(toks);
            toks = strtok(NULL, "|");
            strcpy(name, toks);
            toks = strtok(NULL, "|");
            strcpy(gdesc, toks);
            toks = strtok(NULL, "|");
            space_id = atol(toks);
            toks = strtok(NULL, "|");
            health = atol(toks);
            toks = strtok(NULL, "|");
            friendly = atol(toks);
            toks = strtok(NULL, "|");
            strcpy(message, toks);

            character = character_create(character_id);
            if (character != NULL)
            {
                character_set_name(character, name);
                character_set_gdesc(character, gdesc);
                character_set_health(character, health);
                character_set_friendly(character, friendly);
                character_set_message(character, message);
                game_add_character(game, character);
                game_set_character_location(game, space_id, character_id);
            }
        }
    }
#ifdef DEBUG
    printf("Leido: c:%ld|%s|%ld|%s\n", object_id, name, space_id, message);
#endif

    if (ferror(file))
    {
        status = ERROR;
        free(character);
    }
    fclose(file);

    return status;
}

/* Loads the players read on file
 */
Status game_management_load_player(Game *game, char *filename)
{
    FILE *file = NULL;
    Player *player = NULL;
    Inventory *inventory = NULL;
    char *toks = NULL;
    char line[WORD_SIZE] = "\0";
    char name[WORD_SIZE] = "\0";
    char gdesc[WORD_SIZE] = "\0";
    Id player_id = NO_ID, space_id = NO_ID;
    Status status = OK;
    int health = 0, max_inventory = 0;

    if (!filename)
    {
        return ERROR;
    }

    file = fopen(filename, "r");
    if (file == NULL)
    {
        return ERROR;
    }

    while (fgets(line, WORD_SIZE, file))
    {
        if (strncmp("#p:", line, 3) == 0)
        {
            toks = strtok(line + 3, "|");
            player_id = atol(toks);
            toks = strtok(NULL, "|");
            strcpy(name, toks);
            toks = strtok(NULL, "|");
            strcpy(gdesc, toks);
            toks = strtok(NULL, "|");
            health = atol(toks);
            toks = strtok(NULL, "|");
            space_id = atol(toks);
            toks = strtok(NULL, "|");
            max_inventory = atol(toks);

            player = player_create(player_id);
            if (player != NULL)
            {
                player_set_name(player, name);
                player_set_gdesc(player, gdesc);
                player_set_health(player, health);
                player_set_location(player, space_id);
                game_add_player(game, player);
                space_set_discovered(game_get_space_with_id(game, space_id), TRUE);
                inventory_set_max_objs(player_get_objects(player), max_inventory);
            }
        }
    }
#ifdef DEBUG
    printf("Leido: p:%ld|%s|%ld|%ld\n", player_id, name, space_id, inventory);
#endif

    if (ferror(file))
    {
        status = ERROR;
        free(player);
        free(inventory);
    }
    fclose(file);

    return status;
}

/* Loads the links read on file
 */
Status game_management_load_link(Game *game, char *filename)
{
    FILE *file = NULL;
    Link *link = NULL;
    char *toks = NULL;
    char line[WORD_SIZE] = "\0";
    char name[WORD_SIZE] = "\0";
    Id link_id = NO_ID, space_id_orig = NO_ID, space_id_dest = NO_ID;
    Bool openst = FALSE;
    Direction dt = -1;
    Status status = OK;

    if (!filename)
    {
        return ERROR;
    }

    file = fopen(filename, "r");
    if (file == NULL)
    {
        return ERROR;
    }

    while (fgets(line, WORD_SIZE, file))
    {
        if (strncmp("#l:", line, 3) == 0)
        {
            toks = strtok(line + 3, "|");
            link_id = atol(toks);
            toks = strtok(NULL, "|");
            strcpy(name, toks);
            toks = strtok(NULL, "|");
            space_id_orig = atol(toks);
            toks = strtok(NULL, "|");
            space_id_dest = atol(toks);
            toks = strtok(NULL, "|");
            dt = atol(toks);
            toks = strtok(NULL, "|");
            openst = atol(toks);

            link = link_create(link_id);
            if (link != NULL)
            {
                link_set_name(link, name);
                link_set_origin(link, space_id_orig);
                link_set_destination(link, space_id_dest);
                link_set_direction(link, dt);
                link_set_open(link, openst);
                game_add_link(game, link);
            }
        }
    }
#ifdef DEBUG
    printf("Leido: l:%ld|%s|%ld|%ld\n", link_id, name, space_id_orig, space_id_dest);
#endif

    if (ferror(file))
    {
        status = ERROR;
        free(link);
    }
    fclose(file);

    return status;
}