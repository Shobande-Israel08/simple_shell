#include "shell.h"

/**
 * free_recurrent_data - free where each loop is needed
 * @data: data structure for the shell
 * Return: Nothing
 */
void free_recurrent_data(data_of_program *data)
{
	if (data->tokens)
		free_array_of_pointers(data->tokens);
	if (data->input_line)
		free(data->input_line);
	if (data->command_name)
		free(data->command_name);

	data->input_line = NULL;
	data->command_name = NULL;
	data->tokens = NULL;
}

/**
 * free_all_data - all the field to be freed
 * @data: data structure of the shell
 * Return: Nothing
 */
void free_all_data(data_of_program *data)
{
	if (data->file_descriptor != 0)
	{
		if (close(data->file_descriptor))
			perror(data->program_name);
	}
	free_recurrent_data(data);
	free_array_of_pointers(data->env);
	free_array_of_pointers(data->alias_list);
}

/**
 * free_array_of_pointers - an array of the pointer to be freed
 * @array: pointer arrays
 * Return: nothing
 */
void free_array_of_pointers(char **array)
{
	int e;

	if (array != NULL)
	{
		for (e = 0; array[e]; e++)
			free(array[e]);

		free(array);
		array = NULL;
	}
}
