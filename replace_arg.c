#include "bish.h"
/**
 * replace_arg - replaces usr's cmd with the pathname of cmd
 * @arg: the usr's argument from the cmd line
 *
 * Return: the replaced str if it matches any or the og str if
 * it doesnt match
 */

char *replace_arg(char *arg)
{
	int i = 0;
	cmdo cmd[] = {
		{"ls", "/bin/ls"},
		{"echo", "/bin/echo"},
		{"cat", "/bin/cat"},
		{"chgrp", "/bin/chgrp"},
		{"chmod", "/bin/chmod"},
		{"chown", "/bin/chown"},
		{"cp", "/bin/cp"},
		{"date", "/bin/date"},
		{"dd", "/bin/dd"},
		{"df", "/bin/df"},
		{"dmesg", "/bin/dmesg"},
		{"false", "/bin/false"},
		{"hostname", "/bin/hostname"},
		{"kill", "/bin/kill"},
		{"ln", "/bin/ln"},
		{"login", "/bin/ln"},
		{"mkdir", "/bin/mkdir"},
		{"mknod", "/bin/mknod"},
		{"more", "/bin/more"},
		{"mount", "/bin/mount"},
		{"mv", "/bin/mv"},
		{"ps", "/bin/ps"},
		{"pwd", "/bin/pwd"},
		{"rm", "/bin/rm"},
		{"rmdir", "/bin/rmdir"},
		{"sed", "/bin/sed"},
		{"sh", "/bin/sh"},
		{"su", "/bin/su"},
		{"true", "/bin/true"},
		{"uname", "/bin/uname"},
		{NULL, NULL}
	};

	while (cmd[i].usr_cmd)
	{
		if (_strcmp(arg, cmd[i].usr_cmd) == 0)
			arg = cmd[i].replace_cmd;
		i++;
	}
	return (arg);
}
