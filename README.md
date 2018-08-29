# 0x15. C - Simple Shell
In this project, we created a simple command line shell for UNIX and Linux called **bish**, short for *bishounen (Japanese for 'pretty boy')*.

It is also a recursive acronym for **B**_ish, **I**t's a **SH**ell_.

![bish](https://github.com/jogden4195/simple_shell/blob/master/img/bish-logo.png)

## Goals of this project
At the end of this project, we are expected to be able to explain to anyone, without the help of Google:
* Who designed and implemented the original Unix operating system
* Who wrote the first version of the UNIX shell
* Who invented the B programming language (the direct predecessor to the C programming language)
* Who is Ken Thompson
* What is a pid and a ppid
* How to manipulate the environment of the current process
* What is the difference between a function and a system call
* How to create processes
* What are the three prototypes of main
* How does the shell use the PATH to find the programs
* How to execute another program with the execve system call
* How to suspend the execution of a process until one of its children terminates
* What is EOF / "end-of-file"?

## Contributors
Leo Byeon - https://github.com/leobyeon

Jenn Ogden - https://github.com/jogden4195

## Project Requirements
* Must be able to compile with gcc 4.8.4 using the flags -Wall -Werror -Wextra and -pedantic
* All files should follow Betty style and document guidelines
* No more than 5 functions per file
* Header files should be include guarded

## Files Included In This Repository

| File | Description |
| ---- | ----------- |
| bish.h | The header file for our project. It contains all of the prototypes, libraries, and structs necessary to run our main function. |
| main.c | This function generates our shell prompt and executes the user's commands. |
| array_maker.c | This file contains the function "array_maker", used in the main. |
| AUTHORS | This is the authors' page for our project. |
| getenv.c | This file contains the function "_getenv", used in the main. |
| _printf.c | This file contains the self_written function "_printf", used in the main. |
| print_number.c | This file contains the function "print_number", used in _printf. |
| putchar.c | This file contains the function "_putchar", used in _printf. |
| puts.c | This file contains the function "_puts", used in _printf. |
| README.md | This is the file you're reading right now! :) |
| replace_arg.c | This file contains the function "replace_arg", used in the main. |
| set_array.c | This file contains the function "set_array", used in the main. |
| strcmp.c | This file contains the function "_strcmp", used in the main. |
| strcpy.c | This file contains the function "_strcpy", used in set_array. |
| strlen.c | This file contains the function "_strlen", used in the main. |

## Function Descriptions

| Function | Description | Arguments | Return Value | Prototype |
| -------- | ----------- | --------- | ------------ | --------- |
| main | Brings up a UNIX command line interpreter. Refer to  How To Use *~b i s h~* section for a full list of features and commands. | None | 0 upon success | int main(void) |
| array_maker | Creates an array that will store the user's commands | char *usr_cmd | char **argv | char **array_maker(char *usr_cmd) |
| _strcmp | Compares two strings | char *str1, char *str2 | The difference between str1 and str2 | int _strcmp(char *str1, char *str2) |
| _strlen | Gets the length of a string | char *str | The length of the string | int _strlen(char *str) |
| _strcpy | Copies a source string to a destination string | char *dest, char *src | A pointer to the destination string |char _strcpy(char *dest, char *src) |
| _getenv | Gets the value of the environment variable | const char *name | Location of the matching variable if success; 0 if not found | char *_getenv(const char *name) |
| _printf | Prints out a string, integer, and/or character. | const char *format, ...  | 0 upon success | int _printf(const char *format, ...) |
| _puts | Prints out a string | char *str | none | void _puts(char *str) |
| _putchar | Prints out a character | char c | 0 upon success | int _putchar(char c) |
| print_number | Prints out a number | int n | 0 upon success | int print_number(int n) |
| _env | Prints out the environment variable | none | none | void _env(void) |
| replace_arg | Replaces shell variables with the pathway to their executables | char *argv | Argv array with replaced variable in it | char *replace_arg(char *argv) |
| set_array | Sets the user's commands into newly made argv array | char *tok, char **cmd_array | none | void set_array(char *tok, char **cmd_array) |

## Compilation And Usage

```
$ git clone [repository link]
$ gcc -Wall -Werror -Wextra -pedantic *.c -o bish
$ ./bish

[enter *~b i s h~* commands]
```

## How To Use *~ b i s h ~*

### How To Enter A Command

All commands for the bish shell follow this syntax: `command_name {arguments}`, where **command_name** is the name of the command you want to execute (e.g. `ls`, `echo`, etc.) and **{arguments}** are the arguments you are giving to that command. For example,

``` echo "Hello World" ```

in the above command, `echo` is the name of the command we are trying to execute and `"Hello World"` is the argument we are feeding into the `echo` command.

### *~ b i s h ~* Commands

| Command | What It Does |
| ------- | ------------ |
| ls | Displays files and directories in current working directory. |
| cd | Changes directory. |
| echo | Prints out arguments to standard output. |
| cat | Prints out content of a file to standard output. |
| chgrp | Changes file group ownership. |
| chmod | Changes file access permissions. |
| chown | Changes file owner and group. |
| cp | Copies files and directories. |
| date | Prints or sets the system data and time. |
| dd | Converts and copies a file. |
| df | Reports filesystem disk space usage. |
| dmesg | Prints or controls the kernel message buffer. |
| env | Prints out list of all environment variables. |
| exit | Exits out of *~ b i s h ~*. |
| false | Does nothing, unsuccessfully. |
| hostname | Shows or sets the system's host name. |
| kill | Sends signals to processes. |
| ln | Makes links between files. |
| login | Begins a session on the system. |
| mkdir | Makes directories. |
| mknod | Makes block or character special files. |
| more | Pages through text. |
| mount | Mounts a filesystem. |
| mv | Moves and/or renames a file. |
| ps | Reports process status. |
| pwd | Prints the name of the current working directory. |
| rm | Removes files or directories. |
| rmdir | Removes empty directories. |
| sed | The 'sed' stream editor. |
| sh | A POSIX compatible command shell. |
| su | Changes user's ID. |
| true | Does nothing, successfully. |
| uname | Prints system information. |

### Exiting *~ b i s h ~*

To exit out of the bish shell, simply enter the command

```
exit
```

To exit out of a process, just press `ctrl d`.
