#include "shell.h"

/**
 * _stranlen – used to returns the length of a string
 * @s: the string whose length is to be checked
 * Return: length of string integer
 */
int _stranlen(char *s)
{
	int i = 0;

	if (!s)
		return (0);

	while (*s++)
		i++;
	return (i);
}

/**
 * _strancmp – carry out lexicogarphic comparison of two strangs.
 * @s1: the 1st strang
 * @s2: the 2nd strang
 * Return: negative if s1 < s2, positive if s1 > s2, zero if s1 == s2
 */
int _strancmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}

/**
 * begin_with - checks if the needle starts with haystack
 * @haystack: string to search
 * @needle: the substring to search
 * Return: address of next char of haystack or NULL
 */
char *begin_with(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}

/**
 * _strancat - concatenates two strings
 * @dest: the buffer destination
 * @src: the buffer source
 * by nexttosho
 * Return: pointer to destination buffer
 */
char *_strancat(char *dest, char *src)
{
	char *ret = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (ret);
}
