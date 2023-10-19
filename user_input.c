#include "shell.h"

/**
 * read_command - From standard input,it reads a command
 * @command: it is buffer where the command will be stored
 * @size: It is the maximum size to be read
 *
 * From standard input using fgets,this function reads the command
 * The function checks if the end of the thus if the fgets is NULL
 * file has been reached.
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
