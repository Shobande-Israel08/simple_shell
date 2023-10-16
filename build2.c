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
 * unset_alias - sets alias to string from the function
 * @info: parameter struct for the function
 * @str: the string alias for the function
 * Return: Always 0 on success, 1 on error
 */

int unset_alias(info_l *info, char *str)
{
	char *p, c;
	int ret;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	c = *p;
	*p = 0;
	ret = delete_node_at_index(&(info->alias),
		get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*p = c;
	return (ret);
}

/**
 * set_alias –it is used to sets alias to string
 * @info: parameter structure for the function
 * @str: refers to the string alias
 * from the function
 * Return: Always 0 on success, 1 on error
 */
int set_alias(info_l *info, char *str)
{
	char *p;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	if (!*++p)
		return (unset_alias(info, str));

	unset_alias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * print_alias - it prints an alias string
 * @node: the alias node from the function
 *
 * Return: Always 0 on success, 1 on error
 */
int print_alias(my_list *node)
{
	char *p = NULL, *a = NULL;

	if (node)
	{
		p = _strchr(node->str, '=');
		for (a = node->str; a <= p; a++)
		_putchar(*a);
		_putchar('\'');
		_puts(p + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * _myalias - imitate the alias builtin that is man alias
 * @info: Structure possess potential arguments and
 * Used to maintian constant function prototype.
 *  Return: Always 0
 *  by nexttosho
 */
int _myalias(info_l *info)
{
	int i = 0;
	char *p = NULL;
	my_list *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (i = 1; info->argv[i]; i++)
	{
		p = _strchr(info->argv[i], '=');
		if (p)
			set_alias(info, info->argv[i]);
		else
			print_alias(node_starts_with(info->alias, info->argv[i], '='));
	}

	return (0);
}
