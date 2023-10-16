envi.c
#include "shell.h"

/**
 * myenv1 - prints the current environment
 * @info: Structure possesing potential arguments and
 * Used to maintain constant function prototype.
 * Return: Always 0
 */
int myenv1(info_l *info)
{
	print_list_str(info->env);
	return (0);
}

/**
 * getenv1 - gets the value of an environ variable
 * @info: Structure possesing potential arguments. Used to maintain
 * @name: environ var name
 * Return: the value
 */
char *getenv1(info_l *info, const char *name)
{
	my_list *node = info->env;
	char *p;

	while (node)
	{
		p = starts_with(node->str, name);
		if (p && *p)
			return (p);
		node = node->next;
	}
	return (NULL);
}

/**
 * _mysetenv - Initiate a new environ var,
 *             or modify an existing one
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: Always 0
 */

int mysetenv1(info_l *info)
{
	if (info->argc != 3)
	{
		_eputs("Incorrect number of arguements\n");
		return (1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
 * myunsetenv1 - eliminate an environment variable
 * @info: Structure possesing potential arguments. Used to maintain
 *        constant function prototype.
 * Return: Always 0
 */

int myunsetenv1(info_l *info)
{
	int i;

	if (info->argc == 1)
	{
		eputs1("Too few arguements.\n");
		return (1);
	}
	for (i = 1; i <= info->argc; i++)
		_unsetenv(info, info->argv[i]);

	return (0);
}

/**
 * populate_env_list - populates environ linked list
 * @info: Structure possesing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 * by nexttosho
 */
int populate_env_list(info_l *info)
{
	my_list *node = NULL;
	size_t i;

	for (i = 0; environ[i]; i++)
		add_node_end(&node, environ[i], 0);
	info->env = node;
	return (0);
}
