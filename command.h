/**
 * @brief It defines the command interpreter interface
 *
 * @file command.h
 * @author Profesores PPROG
 * @version 0
 * @date 27-01-2025
 * @copyright GNU Public License
 */

#ifndef COMMAND_H
#define COMMAND_H

#include "types.h"

/**
 * @brief Command type() enumeration
 */
typedef enum
{
    CMDS,
    CMDL
} CommandType;

/**
 * @brief All possible command input enumeration
 */
typedef enum
{
    NO_CMD = -1,
    UNKNOWN,
    EXIT,
    MOVE,
    TAKE,
    DROP,
    ATTACK,
    CHAT
} CommandCode;

/**Command structure type definition
 */
typedef struct _Command Command;

/**
 * @brief It creates a new command structure, allocating memory and initializing its members
 * @author Profesores PPROG
 *
 * @return A pointer to the command structure
 */
Command *command_create();

/**
 * @brief It destroys a command structure, freeing the allocated memory
 * @author Profesores PPROG
 *
 * @param command A pointer to the command structure
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status command_destroy(Command *command);

/**
 * @brief It sets the code of a command
 * @author Profesores PPROG
 *
 * @param command A pointer to the command structure
 * @param code The input action string
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status command_set_code(Command *command, CommandCode code);

/**
 * @brief It gets the code of a command
 * @author Profesores PPROG
 *
 * @param command A pointer to the command structure
 * @return Name of the command
 */
CommandCode command_get_code(Command *command);

Status command_set_status(Command *command, Status status);
Status command_get_status(Command *command);

/**
 * @brief It sets the argument of a command
 * @author Álvaro Bravo González
 *
 * @param command A pointer to the command structure
 * @param argstr The argumernt string
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status command_set_argstr(Command *command, char *argstr);

/**
 * @brief It gets the argument of a command
 * @author Álvaro Bravo González
 *
 * @param command A pointer to the command structure
 * @return Argument of the command
 */
char *command_get_argstr(Command *command);

/**
 * @brief Saves the input and calls the other functions
 * @author Profesores PPROG
 *
 * @param command  A pointer to the command structure
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status command_get_user_input(Command *command);

#endif