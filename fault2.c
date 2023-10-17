#include "shell.h"

/**
 * _erra1 - transmute a string to an int
 * @s: the string to be transmuted
 * Return: 0 if no numbers in string,transmuted number otherwise
 *       -1 on error
 */
int _erra1(char *s)
{
	int i = 0;
	unsigned long int result = 0;

	if (*s == '+')
		s++;
	for (i = 0;  s[i] != '\0'; i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			result *= 10;
			result += (s[i] - '0');
			if (result > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (result);
}

/**
 * outprint_error - outputs an error message
 * @info: the parameter & return info struct
 * @estr: string possesing specified error type
 * Return: 0 if no numbers in string, transmuted number otherwise
 *        -1 on error
 */
void outprint_error(info_l *info, char *estr)
{
	eputs1(info->fname);
	eputs1(": ");
	print_p(info->line_count, STDERR_FILENO);
	eputs1(": ");
	eputs1(info->argv[0]);
	eputs1(": ");
	eputs1(estr);
}

/**
 * print_p - function outputs a decimal (integer) number (base 10)
 * @input: the input
 * @fd: the file descriptor to input to
 * by nexttosho
 * Return: number of characters printed
 */
int print_p(int input, int fd)
{
	int (*__putchar)(char) = _putchar;
	int i, count = 0;
	unsigned int _abs_, current;

	if (fd == STDERR_FILENO)
		__putchar = _eputcha1;
	if (input < 0)
	{
		_abs_ = -input;
		__putchar('-');
		count++;
	}
	else
		_abs_ = input;
	current = _abs_;
	for (i = 1000000000; i > 1; i /= 10)
	{
		if (_abs_ / i)
		{
			__putchar('0' + current / i);
			count++;
		}
		current %= i;
	}
	__putchar('0' + current);
	count++;

	return (count);
}

/**
 * number_changer - converter function, a clone of itoa
 * @num: num
 * @base: base
 * @flags: argument flags
 * Return: string
 */

char *number_changer(long int num, int base, int flags)
{
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long n = num;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		n = -num;
		sign = '-';

	}
	array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do	{
		*--ptr = array[n % base];
		n /= base;
	} while (n != 0);

	if (sign)
		*--ptr = sign;
	return (ptr);
}

/**
 * comments_removal – removes first instance of '#' with '\0'
 * @buf: location of the string to modify
 * Return: Always 0;
 */
void comments_removal(char *buf)
{
	int i;

	for (i = 0; buf[i] != '\0'; i++)
		if (buf[i] == '#' && (!i || buf[i - 1] == ' '))
		{
			buf[i] = '\0';
			break;
		}
}
