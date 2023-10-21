#include "shell.h"
/**
 * _strtok - The delimiter to separate strings
 * @line: pointer to array.
 * @delim: the characters mark in the string.
 * Return: A pointer to token created
*/
char *_strtok(char *line, char *delim)
{
	int g;
	static char *str;
	char *copystr;

	if (line != NULL)
		str = line;
	for (; *str != '\0'; str++)
	{
		for (g = 0; delim[g] != '\0'; g++)
		{
			if (*str == delim[g])
			break;
		}
		if (delim[g] == '\0')
			break;
	}
	copystr = str;
	if (*copystr == '\0')
		return (NULL);
	for (; *str != '\0'; str++)
	{
		for (g = 0; delim[g] != '\0'; g++)
		{
			if (*str == delim[g])
			{
				*str = '\0';
				str++;
				return (copystr);
			}
		}
	}
	return (copystr);
}
