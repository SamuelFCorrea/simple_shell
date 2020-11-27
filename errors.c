#include "shell.h"

/**
 * print_error - Writes an error message to stderr.
 * @arg0: Arguments.
 * @i: Iterator.
 */
void print_error(char *arg0, int i)
{
	char *erbuffer;
	int l;

	erbuffer = malloc(sizeof(char) * 512);
	if (!erbuffer)
		exit(1);

	erbuffer = _pwd("_=");
	l = _strlen(erbuffer);

	write(STDERR_FILENO, erbuffer, l);
	write(STDERR_FILENO, ": ", 2);
	if (i == 0)
		perror(arg0);
	else
	{
		l = _strlen(arg0);
		write(STDERR_FILENO, arg0, l);
		write(1, "\n", 1);
	}
	free(erbuffer);
	exit(1);
}
