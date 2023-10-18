#include "shell.h"

/**
 * read_command - Reads a command from standard input
 * @command: The buffer where the command will be stored
 * @size: The maximum size to be read
 *
 * This function reads a command from standard input using fgets.
 * If fgets returns NULL, the function checks if the end of the
 * file has been reached. If so, it prints a newline and exits
 * with success. Otherwise, it prints an error message and exits
 * with failure. The function also removes the trailing newline
 * from the command read.
 */
void read_command(char *command, size_t size)
{
	if (fgets(command, size, stdin) == NULL)

	{
	if (feof(stdin))
	{
		next_print("\n");
		exit(EXIT_SUCCESS);
	}
	else
	{
		next_print("Error while reading input.\n");
		exit(EXIT_FAILURE);
	}
	}
	command[strcspn(command, "\n")] = '\0';
}
