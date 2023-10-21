#include "shell.h"

/**
 * builtin_exit - leaves the shell with status
 * @data: data structure for the shell
 * Return: 0 if sucess, or any other if its declared
 */
int builtin_exit(data_of_program *data)
{
	int e;

	if (data->tokens[1] != NULL)
	{
		for (e = 0; data->tokens[1][e]; e++)
			if ((data->tokens[1][e] < '0' || data->tokens[1][e] > '9')
				&& data->tokens[1][e] != '+')
			{
				errno = 2;
				return (2);
			}
		errno = _atoi(data->tokens[1]);
	}
	free_all_data(data);
	exit(errno);
}

/**
 * builtin_cd - move from the recent directory
 * @data: data structure for the shell
 * Return: 0 if sucess, or any other if its declared
 */
int builtin_cd(data_of_program *data)
{
	char *dir_home = env_get_key("HOME", data), *dir_old = NULL;
	char old_dir[128] = {0};
	int error_code = 0;

	if (data->tokens[1])
	{
		if (str_compare(data->tokens[1], "-", 0))
		{
			dir_old = env_get_key("OLDPWD", data);
			if (dir_old)
				error_code = set_work_directory(data, dir_old);
			_print(env_get_key("PWD", data));
			_print("\n");

			return (error_code);
		}
		else
		{
			return (set_work_directory(data, data->tokens[1]));
		}
	}
	else
	{
		if (!dir_home)
			dir_home = getcwd(old_dir, 128);

		return (set_work_directory(data, dir_home));
	}
	return (0);
}

/**
 * set_work_directory - create the working directory
 * @data: data structure for the shell
 * @new_dir: that is the path to set as working directory
 * Return: 0 if sucess, or any other if its declared
 */
int set_work_directory(data_of_program *data, char *new_dir)
{
	char old_dir[128] = {0};
	int err_code = 0;

	getcwd(old_dir, 128);

	if (!str_compare(old_dir, new_dir, 0))
	{
		err_code = chdir(new_dir);
		if (err_code == -1)
		{
			errno = 2;
			return (3);
		}
		env_set_key("PWD", new_dir, data);
	}
	env_set_key("OLDPWD", old_dir, data);
	return (0);
}

/**
 * builtin_help - display the environ where the program is
 * @data: data structure of the shell
 * Return: 0 if sucess, or any other if its declared
 */
int builtin_help(data_of_program *data)
{
	int e, length = 0;
	char *mensakay[6] = {NULL};

	mensakay[0] = HELP_MSG;

	if (data->tokens[1] == NULL)
	{
		_print(mensakay[0] + 6);
		return (1);
	}
	if (data->tokens[2] != NULL)
	{
		errno = E2BIG;
		perror(data->command_name);
		return (5);
	}
	mensakay[1] = HELP_EXIT_MSG;
	mensakay[2] = HELP_ENV_MSG;
	mensakay[3] = HELP_SETENV_MSG;
	mensakay[4] = HELP_UNSETENV_MSG;
	mensakay[5] = HELP_CD_MSG;

	for (e = 0; mensakay[e]; e++)
	{
		length = str_length(data->tokens[1]);
		if (str_compare(data->tokens[1], mensakay[e], length))
		{
			_print(mensakay[e] + length + 1);
			return (1);
		}
	}
	errno = EINVAL;
	perror(data->command_name);
	return (0);
}

/**
 * builtin_alias - display aliases
 * @data: data structure for the shell
 * Return: 0 if sucess, or any other if its declared
 */
int builtin_alias(data_of_program *data)
{
	int e = 0;

	if (data->tokens[1] == NULL)
		return (print_alias(data, NULL));

	while (data->tokens[++e])
	{
		if (count_characters(data->tokens[e], "="))
			set_alias(data->tokens[e], data);
		else
			print_alias(data, data->tokens[e]);
	}

	return (0);
}
