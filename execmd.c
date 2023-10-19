#include "shell.h"

/**
 * execmd - Executes a command
 * @argv: The arguments for the command
 *
 * This function takes an array of arguments, gets the command from
 * the first argument, generates the path to the command, and then
 * executes the command using execve. If execve fails, it prints an
 * error message.
 */
void execmd(char **argv)
{
	 char *command = NULL, *actual_command = NULL;

	if (argv)
	{
		command = argv[0];
		actual_command = get_location(command);

	if (execve(actual_command, argv, NULL) == -1)
	{
		perror("Error:");
	}
	}
}
