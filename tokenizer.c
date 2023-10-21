#include "shell.h"
/**
 * tokenize - using delimeter to separate strings
 * @data: data pointer
 * Return: an array of another side of a string
 */
void tokenize(data_of_program *data)
{
	char *delimiter = " \t";
	int e, g, counter = 2, length;

	length = str_length(data->input_line);
	if (length)
	{
		if (data->input_line[length - 1] == '\n')
			data->input_line[length - 1] = '\0';
	}

	for (e = 0; data->input_line[e]; e++)
	{
		for (g = 0; delimiter[g]; g++)
		{
			if (data->input_line[e] == delimiter[g])
				counter++;
		}
	}

	data->tokens = malloc(counter * sizeof(char *));
	if (data->tokens == NULL)
	{
		perror(data->program_name);
		exit(errno);
	}
	e = 0;
	data->tokens[e] = str_duplicate(_strtok(data->input_line, delimiter));
	data->command_name = str_duplicate(data->tokens[0]);
	while (data->tokens[e++])
	{
		data->tokens[e] = str_duplicate(_strtok(NULL, delimiter));
	}
}
