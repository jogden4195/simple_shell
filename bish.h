#ifndef BISH_H
#define BISH_H

#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

#define DELIMS " \t\r\n"

extern char **environ;

int _strcmp(const char *s1, const char *s2);
int _strlen(char *str);
char *_strcpy(char *dest, char *src);
char *_getenv(const char *name);

typedef struct commando
{
	char *usr_cmd;
	char * (*func)(char *ptr);
	char *flags;
} cmdo;

#endif /* BISH_H */
