#ifndef BISH_H
#define BISH_H

#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

int _strcmp(char *s1, char *s2);
int _strlen(char *str);
char *_strcpy(char *dest, char *src);

struct commando
{
	char *usr_cmd;
	char * (*func)(char *ptr);
	char *flags;
}

#endif /* BISH_H */
