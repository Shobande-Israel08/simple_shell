#include "shell.h"

/**
 * str_length - Length of the stringto return
 * @string: the string pointer
 * Return: length of string.
 */
int str_length(char *string)
{
	int length = 0;

	if (string == NULL)
		return (0);

	while (string[length++] != '\0')
	{
	}
	return (--length);
}

/**
 * str_duplicate - the string to be duplicated
 * @string: The string in the program to be copied
 * Return: array pointer
 */
char *str_duplicate(char *string)
{
	char *result;
	int length, e;

	if (string == NULL)
		return (NULL);

	length = str_length(string) + 1;

	result = malloc(sizeof(char) * length);

	if (result == NULL)
	{
		errno = ENOMEM;
		perror("Error");
		return (NULL);
	}
	for (e = 0; e < length ; e++)
	{
		result[e] = string[e];
	}

	return (result);
}

/**
 * str_compare - string comparison
 * @string1: the string one
 * @string2: the string two
 * @number: char numbers to be compared
 * Return: 1 if equals strings,0 if different
 */
int str_compare(char *string1, char *string2, int number)
{
	int iterator;

	if (string1 == NULL && string2 == NULL)
		return (1);

	if (string1 == NULL || string2 == NULL)
		return (0);

	if (number == 0)
	{
		if (str_length(string1) != str_length(string2))
			return (0);
		for (iterator = 0; string1[iterator]; iterator++)
		{
			if (string1[iterator] != string2[iterator])
				return (0);
		}
		return (1);
	}
	else
	{
		for (iterator = 0; iterator < number ; iterator++)
		{
			if (string1[iterator] != string2[iterator])
			return (0);
		}
		return (1);
	}
}

/**
 * str_concat - The two strings to be concatenates
 * @string1: String one to be concatenated
 * @string2: String two to be concatenated
 *
 * Return: array pointer
 */
char *str_concat(char *string1, char *string2)
{
	char *result;
	int length1 = 0, length2 = 0;

	if (string1 == NULL)
		string1 = "";
	length1 = str_length(string1);

	if (string2 == NULL)
		string2 = "";
	length2 = str_length(string2);

	result = malloc(sizeof(char) * (length1 + length2 + 1));
	if (result == NULL)
	{
		errno = ENOMEM;
		perror("Error");
		return (NULL);
	}

	for (length1 = 0; string1[length1] != '\0'; length1++)
		result[length1] = string1[length1];
	free(string1);

	for (length2 = 0; string2[length2] != '\0'; length2++)
	{
		result[length1] = string2[length2];
		length1++;
	}

	result[length1] = '\0';
	return (result);
}


/**
 * str_reverse - string to be reversed
 *
 * @string: string pointer
 * Return: void.
 */
void str_reverse(char *string)
{

	int e = 0, length = str_length(string) - 1;
	char hold;

	while (e < length)
	{
		hold = string[e];
		string[e++] = string[length];
		string[length--] = hold;
	}
}

