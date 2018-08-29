#include "bish.h"
/**
 * set_array - sets the usr's cmds into our newly made argv array
 * @tok: strtok's usr's cmd
 * @cmd_array: the array we are inputting the values into
 *
 * Return: none
 */

void set_array(char *tok, char **cmd_array)
{
	int i = 0;
	char *path;
	
	while (tok)
	{
		if (i == 0)
			tok = replace_arg(tok);
		cmd_array[i] = tok;
		tok = strtok(NULL, DELIMS);
		i++;
	}
	cmd_array[i] = NULL;
}
