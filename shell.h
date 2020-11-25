#ifndef SHELL_H
#define SHELL_H

/*****************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <errno.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <sys/resource.h>

/*****************************************************************************/

#define BUF_SIZE 1024
extern char **environ;

/*****************************************************************************/

/* start the shell in an interactive mode reading and executing commands */
void sh_interactive(void);
/* start the shell in a no interactive mode */
void sh_nointeractive(void);
/* execute the commands passed in the normal input */
void run_command(char **);
/*
 * read the input, stage it in the buffer and pass it to the parsing_line
 * fuction also print the PS1 variable
 */
char *command_line(char **);
/* parse the buffer to make it a matrix */
char **parsing_line(char *);
/* gets the lenght of a string */
int _strlen(char *);
/* concatenate a string */
char *_strncat(char *, char *, int);
/* find the correct path of the command in $PATH */
char *find_path(char **);
/* finds the $PATH variable in the enviroment matix */
int get_env(char *);
int especial_c(char **);
char *_pwd(char *);
void cd(char **);
void create_error(char **, int);
char *error_126(char **);
char *error_127(char **);
int num_len(int);
char *_itoa(int);
//int help_function(var_s *);
void print_help(void);
void help_exit(void);
void help_help(void);
void help_env(void);
void print_error(char *, int);

/*****************************************************************************/

#endif
