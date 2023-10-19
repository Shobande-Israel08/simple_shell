#include "shell.h"


/**
 * read_command - Reads the command from the user inpute
 * @lineptr: The buffer where the command will be stored
 * @n: The maximum size to be read from the function
 *
 * The function prints an error message and returns -1.
 * If getline is -1
 * Return: The number of characters read, or -1 if an error occurred
 */
ssize_t read_command(char **lineptr, size_t *n)
{
	 ssize_t nchars_read;
	printf("myshell$");
	nchars_read = getline(lineptr, n, stdin);

	if (nchars_read == -1)
	{
	printf("Exiting shell....\n");
	return (-1);
	}

	return (nchars_read);
}

/**
 * process_command - Processes the command read from the user inpute
 * @lineptr: Thats the buffer where the command was stored
 * @lineptr_copy: A copy of the command from the user
 * @num_tokens: Thats the number of tokens in the command
 * @argv: The arguments for the command from user inpute
 * Return: 0 if successful, -1 otherwise
 */
int process_command(char *lineptr, char *lineptr_copy,
		int num_tokens, char **argv)
{
	char *token;
	int i;

	token = strtok(lineptr, " \n");

	while (token != NULL)
	{
	num_tokens++;
	token = strtok(NULL, " \n");
	}
	num_tokens++;

	argv = malloc(sizeof(char *) * num_tokens);

	token = strtok(lineptr_copy, " \n");

	for (i = 0; token != NULL; i++)
	{
	argv[i] = malloc(sizeof(char) * strlen(token));
	strcpy(argv[i], token);

	token = strtok(NULL, " \n");
	}
	argv[i] = NULL;

	execmd(argv);

	return (0);
}

/**
 * main - Main entry point for my shell program
 * @ac: The number of arguments for user inpute
 * @argv: The arguments for the command
 * When the function displays a prompt,
 * It reads a command from the user.
 * The loop continues indefinitely till the getline function fails
 * or user uses CTRL + D.
 *
 * Return: 0 if successful, -1 otherwise
 */
int main(int ac, char **argv)
{
	char *prompt = "myshell$";
	char *lineptr = NULL, *lineptr_copy = NULL;
	size_t n = 0;
	ssize_t nchars_read;
	int num_tokens = 0;
	/*int i;*/

	(void)ac;
	(void)prompt;

	while (1)
	{
	nchars_read = read_command(&lineptr, &n);

	if (nchars_read == -1)
	{
		return (-1);
	}

	lineptr_copy = malloc(sizeof(char) * nchars_read);
	if (lineptr_copy == NULL)
	{
		perror("tsh: memory allocation error");
		return (-1);
	}

	strcpy(lineptr_copy, lineptr);

	process_command(lineptr, lineptr_copy, num_tokens, argv);
	}

	free(lineptr_copy);
	free(lineptr);

	return (0);
}
