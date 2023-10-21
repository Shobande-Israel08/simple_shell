#include "shell.h"

/**
 * env_get_key - take the value of the environ
 * @key: the variable of interest
 * @data: data structure
 * Return: the pointer to the value
 */
char *env_get_key(char *key, data_of_program *data)
{
	int e, key_length = 0;

	if (key == NULL || data->env == NULL)
		return (NULL);

	key_length = str_length(key);

	for (e = 0; data->env[e]; e++)
	{
		if (str_compare(key, data->env[e], key_length) &&
		 data->env[e][key_length] == '=')
		{
			return (data->env[e] + key_length + 1);
		}
	}
	return (NULL);
}

/**
 * env_set_key - rewrite the value of the environ
 * @key: That is the variable to set
 * @value: new value
 * @data: the data structure
 * Return: 1 if for NULL, 2 is for an erroror 0 if sucess.
 */

int env_set_key(char *key, char *value, data_of_program *data)
{
	int e, key_length = 0, is_new_key = 1;

	if (key == NULL || value == NULL || data->env == NULL)
		return (1);

	key_length = str_length(key);

	for (e = 0; data->env[e]; e++)
	{
		if (str_compare(key, data->env[e], key_length) &&
		 data->env[e][key_length] == '=')
		{
			is_new_key = 0;
			free(data->env[e]);
			break;
		}
	}
	data->env[e] = str_concat(str_duplicate(key), "=");
	data->env[e] = str_concat(data->env[e], value);

	if (is_new_key)
	{
		data->env[e + 1] = NULL;
	}
	return (0);
}

/**
 * env_remove_key - the key to be removed from environ
 * @key: removed key to be
 * @data: data structure of the shell
 * Return: 1 for removed key, 0 it does not exist;
 */
int env_remove_key(char *key, data_of_program *data)
{
	int e, key_length = 0;

	if (key == NULL || data->env == NULL)
		return (0);

	key_length = str_length(key);

	for (e = 0; data->env[e]; e++)
	{
		if (str_compare(key, data->env[e], key_length) &&
		 data->env[e][key_length] == '=')
		{
			free(data->env[e]);

			e++;
			for (; data->env[e]; e++)
			{
				data->env[e - 1] = data->env[e];
			}
			data->env[e - 1] = NULL;
			return (1);
		}
	}
	return (0);
}


/**
 * print_environ - the recent environ to be printed
 * @data: data structure
 * Return: nothing
 */
void print_environ(data_of_program *data)
{
	int g;

	for (g = 0; data->env[g]; g++)
	{
		_print(data->env[g]);
		_print("\n");
	}
}
