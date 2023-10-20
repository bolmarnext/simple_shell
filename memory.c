#include "shell.h"

/**
 * bfree - the program frees a pointer and NULLs the address
 * @ptr: address of pointer to free
 *
 * Return: return 1 if freed, else 0.
 */
int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
