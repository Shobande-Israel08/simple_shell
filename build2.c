#include "shell.h"

/**
 * histo1 - from the function, showcase the history list,
 * line by line command, predated with line numbers, starting at 0.
 * @info: Structure containing potential arguments and
 * Used to maintain constant function prototype.
 *  Return: Always 0
 */

int histo1(info_l *info)
{
	print_list(info->history);
	return (0);
}

/**
 * unsetted_alias - sets alias to string from the function
 * @info: parameter struct for the function
 * @str: the string alias for the function
 * Return: Always 0 on success, 1 on error
 */

int unsetted_alias(info_l *info, char *str)
{
	char *pi, ce;
	int ret;

	pi = _strchr(str, '=');
	if (!pi)
		return (1);
	ce = *pi;
	*pi = 0;
	ret = delete_node_at_index(&(info->alias),
		get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*pi = ce;
	return (ret);
}

/**
 * setted_alias – It sets alias to string
 * @info: parameter structure for the function
 * @str: refers to the string alias
 * from the function
 * Return: Always 0 on success, 1 on error
 */
int setted_alias(info_l *info, char *str)
{
	char *pi;

	pi = _strchr(str, '=');
	if (!pi)
		return (1);
	if (!*++pi)
		return (unsetted_alias(info, str));

	unsetted_alias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * printed_alias - it prints an alias string
 * @node: the alias node from the function
 *
 * Return: Always 0 on success, 1 on error
 */
int printed_alias(my_list *node)
{
	char *pi = NULL, *a = NULL;

	if (node)
	{
		pi = _strchr(node->str, '=');
		for (a = node->str; a <= pi; a++)
		_putchar(*a);
		_putchar('\'');
		_puts(pi + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * _newalias - imitate the alias builtin that is man alias
 * @info: Structure possess potential arguments and
 * Used to maintian constant function prototype.
 *  Return: Always 0
 *  by nexttosho
 */
int _newalias(info_l *info)
{
	int i = 0;
	char *pi = NULL;
	my_list *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			printed_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (i = 1; info->argv[i]; i++)
	{
		pi = _strchr(info->argv[i], '=');
		if (pi)
			setted_alias(info, info->argv[i]);
		else
			printed_alias(node_starts_with(info->alias, info->argv[i], '='));
	}

	return (0);
}
