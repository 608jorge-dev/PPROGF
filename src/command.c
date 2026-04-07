/**
 * @brief It implements the command interpreter
 *
 * @file command.c
 * @author Profesores PPROG
 * @version 0
 * @date 24-01-2026
 * @copyright GNU Public License
 */

#include "command.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

/**
 * String that stores all the commands that can be used
 */
char *cmd_to_str[N_CMD][N_CMDT] = {{"", "No command"}, {"", "Unknown"}, {"e", "Exit"}, {"m", "Move"}, {"t", "Take"}, {"d", "Drop"}, {"a", "Attack"}, {"c", "Chat"}, {"i", "Inspect"}};

/**
 * @brief Character
 *
 * This struct stores all the information related to a command.
 */
struct _Command
{
  CommandCode code;                 /*!< Name of the command */
  Status status;                    /*!< Status of the command */
  char argstr[MAX_ARGS][WORD_SIZE]; /*!< Command arguments */
  int nArgs;                        /*!< Number of arguments */
  char *description;                /*!< Text contained in the command */
};

/**It creates a new command structure,
 * allocating memory and initializing its members
 */
Command *command_create()
{
  int i, j;
  Command *newCommand = NULL;

  newCommand = (Command *)calloc(1, sizeof(Command));
  if (newCommand == NULL)
  {
    return NULL;
  }

  /* Initialization of an empty command*/
  newCommand->code = NO_CMD;
  for (i = 0; i < MAX_S; i++)
  {
    for (j = 0; j < MAX_C; j++)
    {
      newCommand->argstr[i][j] = '\0';
    }
  }
  newCommand->nArgs = 0;
  newCommand->status = -1;
  newCommand->description = '\0';

  return newCommand;
}

/** It destroys a command structure, freeing the allocated memory
 */
Status command_destroy(Command *command)
{
  if (!command)
  {
    return ERROR;
  }

  free(command);
  command = NULL;
  return OK;
}

/** It sets the code of a command
 */
Status command_set_code(Command *command, CommandCode code)
{
  if (!command)
  {
    return ERROR;
  }

  command->code = code;

  return OK;
}

/** It gets the code of a command
 */
CommandCode command_get_code(Command *command)
{
  if (!command)
  {
    return NO_CMD;
  }
  return command->code;
}

/** It sets the status of a command
 */
Status command_set_status(Command *command, Status status)
{
  if (!command)
  {
    return ERROR;
  }

  command->status = status;

  return OK;
}

/** It gets the status of a command
 */
Status command_get_status(Command *command)
{
  if (!command)
  {
    return NO_CMD;
  }
  return command->status;
}

/** It sets the argument of a command
 */
Status command_set_argstr(Command *command, char *argstr)
{
  if (!command || !argstr || command->nArgs >= MAX_ARGS)
  {
    return ERROR;
  }

  strcpy(command->argstr[command->nArgs], argstr);
  command->nArgs++;

  return OK;
}

/** It gets the argument of a command
 */
char *command_get_argstr(Command *command)
{
  if (!command || command->nArgs == 0)
  {
    return NULL;
  }

  fprintf (stdout, "%s", command->argstr[0]);
  return command->argstr[0];
}

/** It sets the description of a command
 */
Status command_set_description(Command *command, char *description)
{
  if (!command)
  {
    return ERROR;
  }

  command->description = description;

  return OK;
}

/** It gets the description of a command
 */
char *command_get_description(Command *command)
{
  if (!command)
  {
    return NULL;
  }
  return command->description;
}

/** It sets the nArgs of a command
 */
Status command_set_nArgs(Command *command, int amount)
{
  if (!command)
  {
    return ERROR;
  }

  command->nArgs = amount;

  return OK;
}

/** It gets the nArgs of a command
 */
int command_get_nArgs(Command *command)
{
  if (!command)
  {
    return -1;
  }

  return command->nArgs;
}

/** Saves the input and calls the other functions
 */
Status command_get_user_input(Command *command)
{
  char input[CMD_LENGHT] = "", cmdarg[CMD_LENGHT] = "", *token = NULL;
  int i = UNKNOWN - NO_CMD + 1;
  CommandCode cmd;

  cmdarg[0] = '\0';
  if (!command)
  {
    command_set_status(command, OK);
    return ERROR;
  }

  if (fgets(input, CMD_LENGHT, stdin))
  {
    command_set_nArgs(command, 0);
    token = strtok(input, " \n");
    if (!token)
    {
      return command_set_code(command, UNKNOWN);
    }

    cmd = UNKNOWN;
    while (cmd == UNKNOWN && i < N_CMD)
    {
      if (!strcasecmp(token, cmd_to_str[i][CMDS]) || !strcasecmp(token, cmd_to_str[i][CMDL]))
      {
        cmd = i + NO_CMD;
      }
      else
      {
        i++;
      }
    }

    token = strtok(NULL, " \n");
    if (!token)
    {
      command_set_status(command, OK);
      return command_set_code(command, cmd);
    }

    strcpy(cmdarg, token);
    command_set_status(command, OK);
    command_set_argstr(command, cmdarg);
    command_set_nArgs(command, command_get_nArgs(command)+1);
    return command_set_code(command, cmd);
  }

  else
  {
    return command_set_code(command, EXIT);
  }
}