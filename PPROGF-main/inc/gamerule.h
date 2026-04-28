#ifndef GAMERULE_H
#define GAMERULE_H

#include "types.h"

typedef struct _Gamerule Gamerule;

typedef enum
{
    NO_RULE = -1,
    UNKNOWN,
    OPEN_LINK,
    CLOSE_LINK,
    CHANGE_OBJ_LOCATION,
    FOG,

} Rules;

Gamerule *gamerule_create();

Status gamerule_destroy(Gamerule *gamerule);

Status gamerule_set_rule(Gamerule *gamerule, Rules r);

Rules *gamerule_get_rule(Gamerule *gamerule);

Status gamerule_set_status(Gamerule *gamerule, Status status);

Status gamerule_get_status(Gamerule *gamerule);

Status gamerule_set_argstr(Gamerule *gamerule, char *argstr);

char *gamerule_get_argstr(Gamerule *gamerule, int position);

Status gamerule_set_description(Gamerule *gamerule, char *description);

char *gamerule_get_description(Gamerule *gamerule);

Status gamerule_set_nArgs(Gamerule *gamerule, int amount);

int gamerule_get_nArgs(Gamerule *gamerule);

#endif