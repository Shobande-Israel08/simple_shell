#include "shell.h"

/**
 * next_print - Prints a message to standard output
 * @message: Thats the message to be printed
 *
 * This function takes in a string from the standard outpute.
 * It uses the write function to achieve this.
 */

void next_print(const char *message)
{
	 write(STDOUT_FILENO, message, strlen(message));
}
