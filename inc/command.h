/**
 * @brief It defines the command interpreter interface
 *
 * @file command.h
 * @author Álvaro Bravo González, Jorge Torrijos de la Cruz
 * @version 7.0
 * @date 28-04-2026
 * @copyright GNU Public License
 */

#ifndef COMMAND_H
#define COMMAND_H

#include "types.h"

/**Command structure type definition
 */
typedef struct _Command Command;

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
    CHAT,
    INSPECT,
    RECRUIT,
    ABANDON,
    USE,
    OPEN,
    SAVE,
    LOAD,
    COLLAB
} CommandCode;

/**
 * @brief It creates a new command structure, allocating memory and initializing its members
 * @author Jorge Torrijos de la Cruz
 *
 * @return A pointer to the command structure
 */
Command *command_create();

/**
 * @brief It destroys a command structure, freeing the allocated memory
 * @author Jorge Torrijos de la Cruz
 *
 * @param command A pointer to the command structure
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status command_destroy(Command *command);

/**
 * @brief It sets the code of a command
 * @author Jorge Torrijos de la Cruz
 *
 * @param command A pointer to the command structure
 * @param code The input action string
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status command_set_code(Command *command, CommandCode code);

/**
 * @brief It gets the code of a command
 * @author Jorge Torrijos de la Cruz
 *
 * @param command A pointer to the command structure
 * @return Name of the command
 */
CommandCode command_get_code(Command *command);

/**
 * @brief It sets the status of a command
 * @author Jorge Torrijos de la Cruz
 *
 * @param command A pointer to the command structure
 * @param status The status of the command
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status command_set_status(Command *command, Status status);

/**
 * @brief It gets the status of a command
 * @author Jorge Torrijos de la Cruz
 *
 * @param command A pointer to the command structure
 * @return Status of the command
 */
Status command_get_status(Command *command);

/**
 * @brief It sets the argument of a command
 * @author Jorge Torrijos de la Cruz
 *
 * @param command A pointer to the command structure
 * @param argstr The argumernt string
 * @return OK if everything goes well or ERROR if there was some mistake
 */
Status command_set_argstr(Command *command, char *argstr);

/**
 * @brief It gets the argument of a command
 * @author Jorge Torrijos de la Cruz
 *
 * @param command A pointer to the command structure
 * @param position Position in the command array
 * @return The argument of the command
 */
char *command_get_argstr(Command *command, int position);

/**
 * @brief It sets the description of a command
 * @author Álvaro Bravo González
 *
 * @param command A pointer to the command structure
 * @param  description The description of the string
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status command_set_description(Command *command, char *description);

/**
 * @brief It gets the description of a command
 * @author Álvaro Bravo González
 *
 * @param command A pointer to the command structure
 * @return The description of the command
 */
char *command_get_description(Command *command);

/**
 * @brief Saves the input and calls the other functions
 * @author Guillermo Núñez Bravo, Jorge Torrijos de la Cruz
 *
 * @param command  A pointer to the command structure
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status command_get_user_input(Command *command);

#endif