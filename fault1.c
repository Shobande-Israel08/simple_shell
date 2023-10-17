#include "shell.h"

/**
 * eputs1 - outputs an input string
 * @str: the string to output
 * Return: Null
 */

void eputs1(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_eputcha1(str[i]);
		i++;
	}
}

/**
 * _eputcha1 - input the character c to stderr
 * @c: The character to output
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */

int _eputcha1(char c)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(2, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
 * _iput1fd - input the character c to given fd
 * @c: The character to output
 * @fd: The file descriptor to input to
 * Return:On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 * by nexttosho
 */

int _iput1fd(char c, int fd)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(fd, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
 * _iput2fd - outputs an input string
 * @str:the string to output
 * @fd:the file descriptor to input to
 * Return:the number of chars put
 */

int _iput2fd(char *str, int fd)
{
	int i = 0;

	if (!str)
		return (0);
	while (*str)
	{
		i += _iput1fd(*str++, fd);
	}
	return (i);
}
