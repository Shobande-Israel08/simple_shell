#include "shell.h"

/**
 * bfree - frees a pointer and null the address
 * @ptr: location of the pointer to free
 * Return: 1 if freed, otherwise 0.
 * by nexttosho
 */
int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = null;
		return (1);
	}
	return (0);
}
