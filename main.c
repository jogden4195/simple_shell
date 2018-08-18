#include "header.h"

int main(void)
{
	int shell_on = 1;

	char curr_loc[1024];
	size_t buf_size = 100;
	char buf[10];
	char *usr_cmd = buf;
	char *tok;

	usr_cmd = malloc(buf_size);

	while (shell_on)
	{
		getcwd(curr_loc, sizeof(curr_loc));
		printf("b i s h :%s> ", curr_loc);

		getline(&usr_cmd, &buf_size, stdin);
		tok = strtok(usr_cmd, " \n");
		if (tok == NULL)
			printf("Enter a command.\n");
		else
		{
			if (strcmp(tok, "exit") == 0)
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
