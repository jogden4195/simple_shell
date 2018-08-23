#include "bish.h"

void _env(void)
{
	int i = 0;

	while (environ[i])
	{
		_printf("%s\n", environ[i]);
		i++;
	}
}


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
