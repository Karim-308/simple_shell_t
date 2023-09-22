#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/stat.h>
#include <stdarg.h>

extern char **environ;

extern int child_exit_status;

char *isCommand(char *);

char **split_line(char *line, int bufsize);

int _strcmp(char *, char *);

int _strcmpn(char *, char *, int); /*like the strcpm but compares with a length*/

char *_strcpy(char *);

char *_strcon(char *, char *);

int _isInt(char *);

int _strToInt(char *);

void _exitFromShell(char **, char *, char **);

void _perror(int, ...);

void _puts(int, ...); /*Like _perror but it prints to the STDOUT instead of STDERR*/

int _putchar(char);

void printEnv();

char *_getenv(char *, int);

char *_getenvVar(char *, int); /*Like the _getenv but it returns the env var from the beginning*/

char *_intToStr(int n);

void _cd(char **, char *, char **, char *);

void updatePWD(char **, char *);

void shell_loop(void);

void process_command(char *line, ssize_t bytes, int commNum);

void execute_command(char *command, char **args);

#endif
