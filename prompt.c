#include "shell.h"

/**
 * display_prompt - Display prompt from the shell
 *
 * This function displays the shell prompt "myshell$" by
 * calling the next_print function.
 */
void display_prompt(void)
{
	next_print("myshell$");
}
