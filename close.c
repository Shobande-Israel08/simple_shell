#include "shell.h"

/**
 **_strancpy - copies a string from the function
 *@dest:Is the destination of the string to be copied to
 *@src: the source string
 *@n: the number of characters to be copied
 *Return: the concatenated string
 */
char *_strancpy(char *dest, char *src, int n)
{
	int i, j;
	char *x = dest;

	i = 0;
	while (src[i] != '\0' && i < n - 1)
	{
		dest[i] = src[i];
		i++;
	}
	if (i < n)
	{
		j = i;
		while (j < n)
		{
			dest[j] = '\0';
			j++;
		}
	}
	return (x);
}

/**
 **_strancat - concatenates two strings in the function
 *@dest: the 1st string to concatenate
 *@src: the 2nd string to concatenate
 *@n: the number of bytes to be used in the function
 *Return: the concatenated string
 */
char *_strancat(char *dest, char *src, int n)
{
	int i, j;
	char *x = dest;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0' && j < n)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	if (j < n)
		dest[i] = '\0';
	return (x);
}

/**
 **_stranchr - it identifies a character in a string
 *@x: the string to be parsed into the function
 *@c: the character to look for in the function
 *Return: (x) a pointer to the memory area x
 * by nexttosho
 */
char *_stranchr(char *x, char c)
{
	do {
		if (*x == c)
			return (x);
	} while (*x++ != '\0');

	return (NULL);
}
