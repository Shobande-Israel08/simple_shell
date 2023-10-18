#include "shell.h"

/**
 * display_prompt - Display the shell prompt
 *
 * This function displays the shell prompt "myshell$" by
 * calling the next_print function.
 */
void display_prompt(void)
{
	next_print("myshell$");
}
