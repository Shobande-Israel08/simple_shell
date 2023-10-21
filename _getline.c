#include "shell.h"

/**
* _getline - from the prompt, it records line
* @data: data sgtruct for the shell
*
* Return: reading counting bytes.
*/
int _getline(data_of_program *data)
{
	char buff[BUFFER_SIZE] = {'\0'};
	static char *array_commands[10] = {NULL};
	static char array_operators[10] = {'\0'};
	ssize_t bytes_read, e = 0;

	if (!array_commands[0] || (array_operators[0] == '&' && errno != 0) ||
		(array_operators[0] == '|' && errno == 0))
	{
		for (e = 0; array_commands[e]; e++)
		{
			free(array_commands[e]);
			array_commands[e] = NULL;
		}

		bytes_read = read(data->file_descriptor, &buff, BUFFER_SIZE - 1);
		if (bytes_read == 0)
			return (-1);

		e = 0;
		do {
			array_commands[e] = str_duplicate(_strtok(e ? NULL : buff, "\n;"));
			e = check_logic_ops(array_commands, e, array_operators);
		} while (array_commands[e++]);
	}

	data->input_line = array_commands[0];
	for (e = 0; array_commands[e]; e++)
	{
		array_commands[e] = array_commands[e + 1];
		array_operators[e] = array_operators[e + 1];
	}

	return (str_length(data->input_line));
}


/**
* check_logic_ops - It monitors and splits the operators
* @array_commands: the command for the array
* @i: the index for the array command
* @array_operators: the array for the logical operator
* Return: the index for the last command
*/
int check_logic_ops(char *array_commands[], int e, char array_operators[])
{
	char *temp = NULL;
	int g;

	for (g = 0; array_commands[e] != NULL  && array_commands[e][g]; g++)
	{
		if (array_commands[e][g] == '&' && array_commands[e][g + 1] == '&')
		{
			temp = array_commands[e];
			array_commands[e][g] = '\0';
			array_commands[e] = str_duplicate(array_commands[e]);
			array_commands[e + 1] = str_duplicate(temp + g + 2);
			e++;
			array_operators[e] = '&';
			free(temp);
			g = 0;
		}
		if (array_commands[e][g] == '|' && array_commands[e][g + 1] == '|')
		{
			temp = array_commands[e];
			array_commands[e][g] = '\0';
			array_commands[e] = str_duplicate(array_commands[e]);
			array_commands[e + 1] = str_duplicate(temp + g + 2);
			e++;
			array_operators[e] = '|';
			free(temp);
			g = 0;
		}
	}
	return (e);
}
