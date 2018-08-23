#include "bish.h"

/*
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

int main(void)
{
	int shell_on = 1, i = 0;
	size_t buf_size = 100;
	char buf[10];
	char *usr_cmd = buf;
	char *argv[100];
	char *tok;
	char *subtok;
	pid_t pid;
	char cwd[100];

	usr_cmd = malloc(buf_size);

	while (shell_on)
	{

		getcwd(cwd, sizeof(cwd));
		_printf("*~b i s h~* :: %s~$ ", cwd);

		getline(&usr_cmd, &buf_size, stdin);
		tok = strtok(usr_cmd, DELIMS);

		if (tok == NULL)
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
			else
			{
				pid = fork();
				if (pid < 0)
					perror("Error");
				else if (pid == 0)
				{
					while (tok)
					{

					/*
					 * Parsing through the usr cmd to
					 * get array of commands
					 * i.e. ls -l -> ["ls", "-l"]
					 */
						argv[i] = malloc(_strlen(tok) + 1);
						_strcpy(argv[i], tok);
						tok = strtok(NULL, DELIMS);
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
					execve(argv[0], argv, NULL);
					perror(argv[0]);

				/*
				 * if execve doesn't work out (eg if a
				 * nonvalid command is given), we need
				 * an exit statement so the child process
				 * dies and we reenter the parent.
				 */

					exit(1);
				}
				/*
				 * Gotta wait for child to die before makin
				 * another one :(
				 */
				else if (pid > 0)
					wait(NULL);
			}
		}
	}
	free(usr_cmd);
	return (0);
}
