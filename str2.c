#include "shell.h"

/**
 * _strancpy - it copies a string
 * from the function
 * @dest: the destination from the function
 * @src: Is the source
 *
 * Return: pointer to the destination
 */
char *_strancpy(char *dest, char *src)
{
	int i = 0;

	if (dest == src || src == 0)
		return (dest);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

/**
 * _strandup - It duplicates a string from
 * the function
 * @str: It is the string to duplicate
 * from the function
 * Return: It is a pointer to the duplicated string
 */
char *_strandup(const char *str)
{
	int length = 0;
	char *ret;

	if (str == NULL)
		return (NULL);
	while (*str++)
		length++;
	ret = malloc(sizeof(char) * (length + 1));
	if (!ret)
		return (NULL);
	for (length++; length--;)
		ret[length] = *--str;
	return (ret);
}

/**
 * _puts1 - It prints an input string from
 * the function
 * @str: the string to be printed
 * Return: Nothing
 */

void _puts1(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_putchar1(str[i]);
		i++;
	}
}

/**
 * _putchar1 - It writes the character c
 * to the stdout from the function
 * @c: The character to print from
 * the function
 * Return: from the function,On success 1.
 * and on error, -1 is returned,
 * and errno is set to appropriately.
 */
int _putchar1(char c)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(1, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}
