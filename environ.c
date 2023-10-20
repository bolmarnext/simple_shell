#include "shell.h"

/**
 * _myenv -  this program prints current environ
 * @info: struct contai potential arg.to maintain constant func prototype.
 * Return: return Always 0
 */
int _myenv(info_t *info)
{
	print_list_str(info->env);
	return (0);
}

/**
 * _getenv - the program gets value of environ variable
 * @info:  struct contain potential arg.
 * @name: env var name
 *
 * Return: return the value
 */
char *_getenv(info_t *info, const char *name)
{
	list_t *node = info->env;
	char *q;

	while (node)
	{
		q = starts_with(node->str, name);
		if (q && *q)
			return (q);
		node = node->next;
	}
	return (NULL);
}

/**
 * _mysetenv -  this program Initialize a new environ variable,
 *             or modify existing one
 * @info: struct contain potential arg.
 *  Return: return Always 0
 */
int _mysetenv(info_t *info)
{
	if (info->argc != 3)
	{
		_eputs("Incorrect number of arguements\n");
		return (1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
 * _myunsetenv -  this remove an environment variable
 * @info: struct contain potential arg. maintain func prototype.
 * Return: return Always 0
 */
int _myunsetenv(info_t *info)
{
	int i;

	if (info->argc == 1)
	{
		_eputs("Too few arguements.\n");
		return (1);
	}
	for (i = 1; i <= info->argc; i++)
		_unsetenv(info, info->argv[i]);

	return (0);
}

/**
 * populate_env_list - the program populates env linked list
 * @info: this structure contain potential arg
 * Return: return Always 0
 */
int populate_env_list(info_t *info)
{
	list_t *node = NULL;
	size_t i;

	for (i = 0; environ[i]; i++)
		add_node_end(&node, environ[i], 0);
	info->env = node;
	return (0);
}
