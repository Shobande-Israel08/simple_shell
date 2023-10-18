#include "shell.h"

/**
 * execute_command - Execute a shell command
 * @command: The command to be executed
 *
 * This function creates a child process using fork, parses the command
 * into its executable name and arguments, and then uses execvp to
 * replace the current process image with the new command. If the command
 * fails to execute, an error message is printed and the function exits
 * with a failure status. The parent process waits for the child to finish
 * before returning.
 */

void execute_command(const char *command)
{
	 pid_t child_pid = fork();

	if (child_pid == -1)

	{
		next_print("Error forking process.\n");
		exit(EXIT_FAILURE);
	}
	else if (child_pid == 0)

	{
	char *args[128];

	int arg_count = 0;

	char *token = strtok((char *)command, " ");

	while (token != NULL)

	{
		args[arg_count++] = token;
		token = strtok(NULL, " ");
	}
	args[arg_count] = NULL;


	execvp(args[0], args);


		next_print("Error executing command.\n");
		exit(EXIT_FAILURE);
	}
	else

	{
		wait(NULL);
	}
}
