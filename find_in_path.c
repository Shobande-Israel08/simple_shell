#include "shell.h"

int check_file(char *full_path);

/**
 * find_program - look for program in the path
 * @data: data structure pointer
 * Return: 0 if there is success, errcode otherwise
 */

int find_program(data_of_program *data)
{
	int e = 0, ret_code = 0;
	char **directories;

	if (!data->command_name)
		return (2);

	if (data->command_name[0] == '/' || data->command_name[0] == '.')
		return (check_file(data->command_name));

	free(data->tokens[0]);
	data->tokens[0] = str_concat(str_duplicate("/"), data->command_name);
	if (!data->tokens[0])
		return (2);

	directories = tokenize_path(data);

	if (!directories || !directories[0])
	{
		errno = 127;
		return (127);
	}
	for (e = 0; directories[e]; e++)
	{
		directories[e] = str_concat(directories[e], data->tokens[0]);
		ret_code = check_file(directories[e]);
		if (ret_code == 0 || ret_code == 126)
		{
			errno = 0;
			free(data->tokens[0]);
			data->tokens[0] = str_duplicate(directories[e]);
			free_array_of_pointers(directories);
			return (ret_code);
		}
	}
	free(data->tokens[0]);
	data->tokens[0] = NULL;
	free_array_of_pointers(directories);
	return (ret_code);
}

/**
 * tokenize_path - it tokenize the path directory
 * @data: data structure pointer
 * Return: the array of path directories
 */

char **tokenize_path(data_of_program *data)
{
	int e = 0;
	int counter_directories = 2;
	char **tokens = NULL;
	char *PATH;

	PATH = env_get_key("PATH", data);
	if ((PATH == NULL) || PATH[0] == '\0')
	{
		return (NULL);
	}

	PATH = str_duplicate(PATH);

	for (e = 0; PATH[e]; e++)
	{
		if (PATH[e] == ':')
			counter_directories++;
	}

	tokens = malloc(sizeof(char *) * counter_directories);

	e = 0;
	tokens[e] = str_duplicate(_strtok(PATH, ":"));
	while (tokens[e++])
	{
		tokens[e] = str_duplicate(_strtok(NULL, ":"));
	}

	free(PATH);
	PATH = NULL;
	return (tokens);

}

/**
 * check_file - check if in the directory the file exit or
 * if it has execution permisions.
 * @full_path: the full file name pointer
 * Return: 0 for success, or error code if it exists.
 */

int check_file(char *full_path)
{
	struct stat sb;

	if (stat(full_path, &sb) != -1)
	{
		if (S_ISDIR(sb.st_mode) ||  access(full_path, X_OK))
		{
			errno = 126;
			return (126);
		}
		return (0);
	}

	errno = 127;
	return (127);
}
