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

void sh_interactive();
void sh_nointeractive();
void run_command(char **);
char *command_line(char **, size_t *);
char **parsing_line(char *);
int _strlen(char *);
char *_strncat(char *, char *);

/*****************************************************************************/
#endif
