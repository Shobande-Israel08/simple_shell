#include "shell.h"

/**
 * print_alias - display aliases
 * @data: data structure of the shell
 * @alias: alaiase name to be printed
 * Return: 0 for sucess, or any other if its declared
 */
int print_alias(data_of_program *data, char *alias)
{
	int e, g, alias_length;
	char buffer[250] = {'\0'};

	if (data->alias_list)
	{
		alias_length = str_length(alias);
		for (e = 0; data->alias_list[g]; e++)
		{
			if (!alias || (str_compare(data->alias_list[e], alias, alias_length)
				&&	data->alias_list[e][alias_length] == '='))
			{
				for (g = 0; data->alias_list[e][g]; g++)
				{
					buffer[g] = data->alias_list[e][g];
					if (data->alias_list[e][g] == '=')
						break;
				}
				buffer[g + 1] = '\0';
				buffer_add(buffer, "'");
				buffer_add(buffer, data->alias_list[e] + g + 1);
				buffer_add(buffer, "'\n");
				_print(buffer);
			}
		}
	}

	return (0);
}

/**
 * get_alias - display aliases
 * @data: data structure of the shell
 * @name: alias names in demand
 * Return: 0 for sucess, or any other if its declared
 */
char *get_alias(data_of_program *data, char *name)
{
	int e, alias_length;

	if (name == NULL || data->alias_list == NULL)
		return (NULL);

	alias_length = str_length(name);

	for (e = 0; data->alias_list[e]; e++)
	{
		if (str_compare(name, data->alias_list[e], alias_length) &&
			data->alias_list[e][alias_length] == '=')
		{
			return (data->alias_list[e] + alias_length + 1);
		}
	}
	return (NULL);

}

/**
 * set_alias - displayed alias
 * @alias_string: the alias to be seted
 * @data: data structure of the shell
 * Return: 0 for sucess, or any other if its declared
 */
int set_alias(char *alias_string, data_of_program *data)
{
	int e, g;
	char buffer[250] = {'0'}, *temp = NULL;

	if (alias_string == NULL ||  data->alias_list == NULL)
		return (1);
	for (e = 0; alias_string[e]; e++)
		if (alias_string[e] != '=')
			buffer[e] = alias_string[e];
		else
		{
			temp = get_alias(data, alias_string + e + 1);
			break;
		}

	for (g = 0; data->alias_list[g]; g++)
		if (str_compare(buffer, data->alias_list[g], e) &&
			data->alias_list[g][e] == '=')
		{
			free(data->alias_list[g]);
			break;
		}

	if (temp)
	{
		buffer_add(buffer, "=");
		buffer_add(buffer, temp);
		data->alias_list[g] = str_duplicate(buffer);
	}
	else
		data->alias_list[g] = str_duplicate(alias_string);
	return (0);
}
