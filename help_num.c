#include "shell.h"

/**
 * long_to_string - the string to be converted.
 * @number: number of string to be converted.
 * @string: the buffer to save the string number.
 * @base: The base to convert number
 *
 * Return: Nothing.
 */
void long_to_string(long number, char *string, int base)
{
	int index = 0, inNegative = 0;
	long cociente = number;
	char letters[] = {"0123456789abcdef"};

	if (cociente == 0)
		string[index++] = '0';

	if (string[0] == '-')
		inNegative = 1;

	while (cociente)
	{
		if (cociente < 0)
			string[index++] = letters[-(cociente % base)];
		else
			string[index++] = letters[cociente % base];
		cociente /= base;
	}
	if (inNegative)
		string[index++] = '-';

	string[index] = '\0';
	str_reverse(string);
}


/**
 * _atoi - an integer to be converted to string
 *
 * @s: str origen pointer
 * Return: integer of the string or 0.
 */
int _atoi(char *s)
{
	int sign = 1;
	unsigned int number = 0;

	while (!('0' <= *s && *s <= '9') && *s != '\0')
	{
		if (*s == '-')
			sign *= -1;
		if (*s == '+')
			sign *= +1;
		s++;
	}

	while ('0' <= *s && *s <= '9' && *s != '\0')
	{

		number = (number * 10) + (*s - '0');
		s++;
	}
	return (number * sign);
}

/**
 * count_characters - number the incident character in string.
 *
 * @string: str origen pointer
 * @character: The string to be counted with character
 * Return: integer of string or 0.
 */
int count_characters(char *string, char *character)
{
	int e = 0, counter = 0;

	for (; string[e]; e++)
	{
		if (string[e] == character[0])
			counter++;
	}
	return (counter);
}
