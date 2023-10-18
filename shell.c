#include "shell.h"

/**
 * main - Main entry point for the shell program
 *
 * This function continuously runs a loop that displays a prompt,
 * reads a command from the user, and executes the command. This
 * loop continues indefinitely until the program is manually exited.
 *
 * Return: This function does not have a return value because it is
 * designed to run indefinitely.
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
