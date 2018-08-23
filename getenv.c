#include "bish.h"

/**
 * _env - prints the env
 * Return: void
 */
void _env(void)
{
	int i = 0;

	while (environ[i])
	{
		_printf("%s\n", environ[i]);
		i++;
	}
}

/**
 * _getenv - get value of an environment variable
 * @name: variable to match
 * Return: the location of the matching variable if sucess;
 * 0 if not found
 */
char *_getenv(const char *name)
{
	int i = 0;
	char *keyword;
	char *loc;

	while (environ[i])
	{
		keyword = strtok(environ[i], "=");
		loc = strtok(0, " ");
		if (_strcmp(keyword, name) == 0)
			return (loc);
		i++;
	}
	return (0);
}
