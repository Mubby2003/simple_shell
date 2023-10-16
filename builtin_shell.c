#include "shell.h"

/**
 * verify_Builtin - A function that checks if a given command is a
 * built-in command in the shell.
 * @shellinfo: Pointer to a struct containing shell-related information.
 * @args: Array of arguments.
 * Return: 1 if the command is a built-in, 0 otherwise.
 */
int verify_Builtin(shellinfo_t *shellinfo, char **args)
{
	typedef struct
	{
		const char *cmd;
		void (*func)(shellinfo_t *, char **);
	} BuiltinCommand;

	BuiltinCommand builtins[] = {
		{"exit", binaryExit},
		{"env", binaryEnv}
	};

	size_t numBuiltins = sizeof(builtins) / sizeof(builtins[0]);

	for (size_t g = 0; g < numBuiltins; ++g)
	{
		if (_strcmp(shellinfo->cmd, builtins[g].cmd) == 0)
		{
			builtins[g].func(shellinfo, args);
			return (1); /* Command is a built-in */
		}
	}

	return (0); /* Command is not a built-in */
}

/**
 * is_Builtin_Command - A function that checks if a given command
 * is a built-in in the shell.
 * @shellinfo: Pointer to a struct containing shell-related information.
 * @command: The command to be checked.
 * *
 * Return: 1 if the command is a built-in, 0 otherwise.
 */
int is_Builtin_Command(shellinfo_t *shellinfo, char **command)
{
	int is_Builtin = verify_Builtin(shellinfo, command);

	if (is_Builtin == 0)
	{
		return (0); /* Not a built-in command */
	}
	return (1); /* A Built-in command */
}
