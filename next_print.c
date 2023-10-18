#include "shell.h"

/**
 * next_print - Prints a message to standard output
 * @message: The message to be printed
 *
 * This function takes a string message and writes it to the standard output.
 * It uses the write function to achieve this.
 */

void next_print(const char *message)
{
	 write(STDOUT_FILENO, message, strlen(message));
}