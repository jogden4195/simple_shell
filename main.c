#include "bish.h"

/*
 * Things Jenn edited as of 8/19 @ 1am:
 * - Added variables i and argv
 * - Added while loop to parse through usr cmd to get array
 *   of arguments for execve
 * - Added if conditional that creates a child process and
 *   execve the args
 * Things that still need to be fixed:
 * - bish can execute one process but doesn't know how to switch
 *   commands when executing the next one
 *   (ie if we entered ./mypid it will work but if we were to then
 *   enter /bin/ls bish will just do ./mypid again.
 */

int main(void)
{
	int shell_on = 1, i = 0;
	size_t buf_size = 100;
	char buf[10];
	char *usr_cmd = buf;
	char *argv[100];
	char *tok;

	usr_cmd = malloc(buf_size);

	while (shell_on)
	{
		printf("b i s h :~$ ");

		getline(&usr_cmd, &buf_size, stdin);
		tok = strtok(usr_cmd, " \n");
		if (tok == NULL)
			printf("Plz enter a command.\n");
		else
		{
			if (_strcmp(tok, "exit") == 0)
				shell_on = 0;
			else
			{
				while (tok)
				{
					printf("tok: %s\n", tok);

					/*
					 * Parsing through the usr cmd to
					 * get array of commands
					 * i.e. ls -l -> ["ls", "-l"]
					 */

					argv[i] = malloc(_strlen(tok) + 1);
					strcpy(argv[i], tok);
					tok = strtok(NULL, " ");
					i++;
				}

				/*
				 * Make the last element of the array so
				 * execve works properly.
				 */

				argv[i] = NULL;

				/*
				 * Making child process so bish will remain
				 * open after completing execve.
				 */

				if (fork() == 0)
				{
					execve(argv[0], argv, NULL);
				}

				/*
				 * Gotta wait for child to die before makin
				 * another one :(
				 */
				wait(NULL);
			}
		}
	}
	free(usr_cmd);
	return (0);
}
