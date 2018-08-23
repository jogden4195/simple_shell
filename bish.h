#ifndef BISH_H
#define BISH_H

#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <stdarg.h>
#include <signal.h>

#define DELIMS " \t\r\n"

extern char **environ;

int _strcmp(const char *s1, const char *s2);
int _strlen(char *str);
char *_strcpy(char *dest, char *src);
char *_getenv(const char *name);
int _printf(const char *format, ...);
int _strlen(char *s);
void _puts(char *str);
int _putchar(char c);
int print_number(int n);
void _env(void);
char *replace_arg(char *argv);

typedef struct commando
{
	char *usr_cmd;
	char *replace_cmd;
} cmdo;

#endif /* BISH_H */
