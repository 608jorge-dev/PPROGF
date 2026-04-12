/**
 * @brief It implements the player info module
 *
 * @file playerinf.c
 * @author Jorge Torrijos de la Cruz
 * @version 0
 * @date 03-02-2026
 * @copyright GNU Public License
 */

#include "playerinf.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Player
 *
 * This struct stores all the information of a player.
 */
struct _Playerinf
{
  Id id;                            /*!< Id number of the player*/
  char lastcommand[WORD_SIZE + 1];  /*!< Last command the player sent */
  Bool laststatus;                   /*!< Status of last command */
  char lastchat[WORD_SIZE + 1];     /*!< Last chat from the player*/
  char lastinspect[WORD_SIZE + 1];  /*!< Last inspect from the player*/
};

/* It creates a new playerinf, allocating memory
 */
Playerinf *playerinf_create(Id id){
  Playerinf *new_playerinf = NULL;

  if(id == NO_ID){
    return NULL;
  }

  new_playerinf = (Playerinf *)calloc(1, sizeof(Playerinf));
  if(new_playerinf == NULL){
    return NULL;
  }

  new_playerinf->id = id;
  new_playerinf->lastcommand[0] = '\0';
  new_playerinf->laststatus = FALSE;
  new_playerinf->lastchat[0] = '\0';
  new_playerinf->lastinspect[0] = '\0';

  return new_playerinf;
}

/* It destroys a playerinf, freeing the allocated memory
 */
Status playerinf_destroy(Playerinf *playerinf){
  if(playerinf == NULL){
    return ERROR;
  }

  free(playerinf);

  return OK;
}

/* It sets the id of a playerinf
 */
Status playerinf_set_id(Playerinf *playerinf, Id id){
  if(playerinf == NULL || id ==NO_ID || id<0){
    return ERROR;
  }

  playerinf->id = id;
  return OK;
}

/* It gets the id of a playerinf
 */
Id playerinf_get_id(Playerinf *playerinf){
  if(playerinf == NULL){
    return NO_ID;
  }

  return playerinf->id;
}

/* It sets the lastcommand of a playerinf
 */
Status playerinf_set_lastcommand(Playerinf *playerinf, char *lastcommand){
  if(playerinf == NULL || lastcommand == NULL){
    return ERROR;
  }

  strcpy(playerinf->lastcommand, lastcommand);
  return OK;
}

/* It gets the lastcommand of a playerinf
 */
char *playerinf_get_lastcommand(Playerinf *playerinf){
  if(playerinf == NULL){
    return NULL;
  }

  return playerinf->lastcommand;
}

/* It sets the laststatus of a playerinf
 */
Status player_set_laststatus(Playerinf *playerinf, Bool laststatus){
  if(playerinf == NULL){
    return ERROR;
  }

  playerinf->laststatus = laststatus;

  return OK;
}

/* It gets the laststatus of a playerinf
 */
Bool player_get_laststatus(Playerinf *playerinf){
  if(playerinf == NULL){
    return FALSE;
  }

  return playerinf->laststatus;
}

/* It sets the lastchat of a playerinf
 */
Status player_set_lastchat(Playerinf *playerinf, char *lastchat){
  if(playerinf == NULL || lastchat == NULL){
    return ERROR;
  }

  strcpy(playerinf->lastchat, lastchat);
  return OK;
}

/* It gets the lastchat of a playerinf
 */
char *player_get_lastchat(Playerinf *playerinf){
  if(playerinf == NULL){
    return NULL;
  }

  return playerinf->lastchat;
}

/* It sets the lastinspect of a playerinf
 */
Status player_set_lastinspect(Playerinf *playerinf, char *lastinspect){
  if(playerinf == NULL || lastinspect == NULL){
    return ERROR;
  }

  strcpy(playerinf->lastinspect, lastinspect);
  return OK;
}

/* It gets the lastinspect of a playerinf
 */
char *player_get_lastinspect(Playerinf *playerinf){
  if(playerinf == NULL){
    return NULL;
  }

  return playerinf->lastinspect;
}

/* It prints the playerinf information
 */
Status playerinf_print(Playerinf *playerinf){
  if(playerinf == NULL){
    return ERROR;
  }
  fprintf(stdout, "--> Playerinf (Id: %ld)\n", playerinf_get_id(playerinf));
  fprintf(stdout, "---> Last command: %s\n",    playerinf_get_lastcommand(playerinf));
  fprintf(stdout, "---> Last status:  %s\n",    playerinf_get_laststatus(playerinf) == TRUE ? "OK" : "ERROR");
  fprintf(stdout, "---> Last chat:    %s\n",    playerinf_get_lastchat(playerinf));
  fprintf(stdout, "---> Last inspect: %s\n",    playerinf_get_lastinspect(playerinf));
 
  return OK;
}