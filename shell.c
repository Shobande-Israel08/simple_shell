#include "shell.h"

/**
 * main - Main entry point for the my shell program
 *
 * It displays a prompt and continuously run a loop and
 * reads a command from the user, and executes the command
 *
 * Return: it is designed to run indefinitely therefore no return
 * value.
 */
int main(void)
{
	char command[120];

	while (true)
	{
	display_prompt();
	read_command(command, sizeof(command));
	execute_command(command);
	}
}
