#include "bish.h"
/**
 * array_maker - creates an array that will hold the usr cmds
 * @usr_cmd: str of usr_cmd from readline
 *
 * Return: empty malloc'd array
 */


char **array_maker(char *usr_cmd)
{
	char **argv;
	int i = 0, count = 0;

	while (usr_cmd[i])
	{
		if (usr_cmd[i] != ' ' || usr_cmd[i] != '\n' || usr_cmd[i] != '\t')
			count++;
		i++;
	}

	argv = malloc(sizeof(char *) * count);
	if (!argv)
	{
		perror("Error");
		exit(1);
	}
	return (argv);
}
