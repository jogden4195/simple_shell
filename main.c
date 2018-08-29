#include "bish.h"

/**
 * main - creates a ~B I S H~ shell
 * @argc: number of arguments going into main
 * @argv: array of arguments going into main
 *
 * Return: 0
 */

/*
 * Leo edit, 8/23 @ 10:21am:
 * - fixed the infinite loop problem by checking for a couple of fail errors
 * - fixed how Ctrl+D is supposed to function
 * - cleaned up some betty errors
 *
 * Leo edit, 8/21 @ 3:12pm:
 * - created _getenv to use for cd (refer to getenv.c for more info)
 * - used getcwd to print out current directory whenever prompt is present
 * - updates getcwd whenever cd is called
 * - added pretty characters to the prompt~*
 *
 * Leo edit, 8/21 @ 12:37pm:
 * - created macro DELIMS in bish.h (refer to file for more info)
 * - created var subtok for handling args after tok
 * - implemented 'cd' temporarily
 *
 * Things Jenn added as of 8/20 @ 10:30am:
 * - pid_t variable called pid
 * - exit statement for when we come across a command that
 *   has no executable
 * - fixed up the if/else if's for parent/child processes
 *
 * Things Jenn edited as of 8/19 @ 1am:
 * - Added variables i and argv
 * - Added while loop to parse through usr cmd to get array
 *   of arguments for execve
 * - Added if conditional that creates a child process and
 *   execve the args
 *
 * Things that still need to be fixed:
 * - bish can execute one process but doesn't know how to switch
 *   commands when executing the next one
 *   (e.g. if we entered ./mypid it will work but if we were to then
 *   enter /bin/ls bish will just do ./mypid again. (UPDATE: FIXED
 *   IT AS OF 8/20)
 * - Need to get rid of printf statements
 * - Need to figure out proper error codes
 */

int main(int __attribute__((unused)) argc, char *argv[])
{
	int shell_on = 1, line = 0;
	int ret_getline;
	size_t buf_size = 100;
	char *usr_cmd;
	char **usr_arg;
	char *tok;
	char *subtok;
	pid_t pid;
	char cwd[100];

	usr_cmd = malloc(buf_size);

	while (shell_on)
	{

		line++;
		if (isatty(0) == 1)
			_printf("$ ");

		ret_getline = getline(&usr_cmd, &buf_size, stdin);
		if (!usr_cmd)
			break;
		if (ret_getline == -1)
			break;
		tok = strtok(usr_cmd, DELIMS);
		if (!tok)
			write(STDIN_FILENO, "", 1);
		else
		{
			if (_strcmp(tok, "exit") == 0)
				shell_on = 0;

			/*
			 * built-in function for cd
			 * subtok is a variable for input AFTER where
			 * the tok variable cuts off;
			 * if nothing is entered, it acts as though
			 * cd $HOME is input
			 */

			else if (_strcmp(tok, "cd") == 0)
			{
				subtok = strtok(0, DELIMS);
				if (!subtok)
				{
					chdir(_getenv("HOME"));
					getcwd(cwd, sizeof(cwd));
				}
				else
				{
					chdir(subtok);
					getcwd(cwd, sizeof(cwd));
				}
			}
			else if (_strcmp(tok, "env") == 0)
			{
				_env();
			}
			else
			{
				pid = fork();
				switch (pid)
				{
					/*
					 * If pid = 0, something went wrong with
					 * the forking process. We will shoot up
					 * an error message in this situation.
					 */

					case -1:
						perror("Error");
						exit(1);

					/*
					 * When pid = 0, we are in the child
					 * process. The child process does
					 * most of the heavy lifting by actually
					 * executing the usr's commands.
					 */

					case 0:

					/*
					 * These two functions, array_maker and
					 * set_array, creates an array and sets
					 * it's elements to the usr's command args,
					 * respectively.
					 */

						usr_arg = array_maker(usr_cmd);
						set_array(tok, usr_arg);

					/*
					* Making child process so bish will remain
					* open after completing execve.
					*/
						execve(usr_arg[0], usr_arg, NULL);
						_printf("%s: %i: %s: not found\n", argv[0], line, usr_arg[0]);

					/*
					* if execve doesn't work out (eg if a
					* nonvalid command is given), we need
					* an exit statement so the child process
					* dies and we reenter the parent.
					*/
						free(usr_arg);
						exit(1);
					/*
					* Gotta wait for child to die before makin
					* another one :(
					*/
					default:
						wait(NULL);
				}
			}
		}
	}
	free(usr_cmd);
	return (0);
}
