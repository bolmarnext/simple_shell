#include "shell.h"

/**
 * _eputs - the program prints an input str
 * @str: str to be printed
 *
 * Return: return Nothing
 */
void _eputs(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_eputchar(str[i]);
		i++;
	}
}

/**
 * _eputchar - the prohram writes char c to stderr
 * @c: char to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set otherwisely.
 */
int _eputchar(char c)
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
 * _putfd - the program writes character c to given fd
 * @c: character to print
 * @fd: filedescriptor to write to
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set otherwisely.
 */
int _putfd(char c, int fd)
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
 * _putsfd - the program prints an input str
 * @str: str to be printed
 * @fd: filedescriptor to write to
 *
 * Return: numb of chars put
 */
int _putsfd(char *str, int fd)
{
	int i = 0;

	if (!str)
		return (0);
	while (*str)
	{
		i += _putfd(*str++, fd);
	}
	return (i);
}
