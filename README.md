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

| Function | Description | Arguments | Return Value | Example |
| -------- | ----------- | --------- | ------------ | ------- |
| main | Brings up a UNIX command line interpreter. Refer to Bish Features and Commands section for a full list of features and commands. | None | 0 upon success |   |
