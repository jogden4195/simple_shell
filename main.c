#include "bish.h"

int main(void)
{
	int shell_on = 1;
	size_t buf_size = 100;
	char buf[10];
	char *usr_cmd = buf;
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
					tok = strtok(NULL, " \n");
				}
			}
		}
	}
	free(usr_cmd);
	return (0);
}
