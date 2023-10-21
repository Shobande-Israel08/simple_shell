#include "shell.h"

/**
 * expand_variables - it displays the variables
 * @data: the data structure pointer
 *
 * Return: do nothing, but sets to errno.
 */
void expand_variables(data_of_program *data)
{
	int e, g;
	char line[BUFFER_SIZE] = {0}, expansion[BUFFER_SIZE] = {'\0'}, *temp;

	if (data->input_line == NULL)
		return;
	buffer_add(line, data->input_line);
	for (e = 0; line[e]; e++)
		if (line[e] == '#')
			line[e--] = '\0';
		else if (line[e] == '$' && line[e + 1] == '?')
		{
			line[e] = '\0';
			long_to_string(errno, expansion, 10);
			buffer_add(line, expansion);
			buffer_add(line, data->input_line + e + 2);
		}
		else if (line[e] == '$' && line[e + 1] == '$')
		{
			line[e] = '\0';
			long_to_string(getpid(), expansion, 10);
			buffer_add(line, expansion);
			buffer_add(line, data->input_line + e + 2);
		}
		else if (line[e] == '$' && (line[e + 1] == ' ' || line[e + 1] == '\0'))
			continue;
		else if (line[e] == '$')
		{
			for (g = 1; line[e + g] && line[e + g] != ' '; g++)
				expansion[g - 1] = line[e + g];
			temp = env_get_key(expansion, data);
			line[e] = '\0', expansion[0] = '\0';
			buffer_add(expansion, line + e + g);
			temp ? buffer_add(line, temp) : 1;
			buffer_add(line, expansion);
		}
	if (!str_compare(data->input_line, line, 0))
	{
		free(data->input_line);
		data->input_line = str_duplicate(line);
	}
}

/**
 * expand_alias - display the aliases
 * @data: data structure pointer
 *
 * Return: do nothing, but sets to errno.
 */
void expand_alias(data_of_program *data)
{
	int e, g, was_expanded = 0;
	char line[BUFFER_SIZE] = {0}, expansion[BUFFER_SIZE] = {'\0'}, *temp;

	if (data->input_line == NULL)
		return;

	buffer_add(line, data->input_line);

	for (e = 0; line[e]; e++)
	{
		for (g = 0; line[e + g] && line[e + g] != ' '; g++)
			expansion[g] = line[e + g];
		expansion[g] = '\0';

		temp = get_alias(data, expansion);
		if (temp)
		{
			expansion[0] = '\0';
			buffer_add(expansion, line + e + g);
			line[e] = '\0';
			buffer_add(line, temp);
			line[str_length(line)] = '\0';
			buffer_add(line, expansion);
			was_expanded = 1;
		}
		break;
	}
	if (was_expanded)
	{
		free(data->input_line);
		data->input_line = str_duplicate(line);
	}
}

/**
 * buffer_add - at the end of the buffer display string
 * @buffer: the buffer to be fill
 * @str_to_add: string to be moved into buffer
 * Return: do nothing, but sets to errno.
 */
int buffer_add(char *buffer, char *str_to_add)
{
	int length, e;

	length = str_length(buffer);
	for (e = 0; str_to_add[e]; e++)
	{
		buffer[length + e] = str_to_add[e];
	}
	buffer[length + e] = '\0';
	return (length + e);
}
