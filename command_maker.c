#include "shell.h"

/**
 * command_line - print PS1 variable and get the
 * line in the input
 *
 * @buffer: buffer to save the input string
 *
 * Return: on success input string, othewise -1 to indicate
 * the end of file
 */

char *command_line(char **buffer)
{
	int c;
	size_t buf_size = BUF_SIZE;

	write(1, "$ ", 2);
	c = getline(buffer, &buf_size, stdin);
	if (c == -1)
		return (NULL);
	return (*buffer);
}

/**
 * parsing_line - transform the buffer into a matrix
 * to execute the commands
 *
 * @buffer: a string who contains the input arguments
 *
 * Return: return the commands to execute
 */

char **parsing_line(char *buffer)
{
	char **commands = NULL, *tokens = NULL;
	char *s = " \t\r\n\a";
	int i;

	commands = malloc(64 * sizeof(char *));
	if (!commands)
	{
		print_error("Error: failed to allocate memory", 1);
		return (NULL);
	}

	tokens = strtok(buffer, s);
	if (!tokens)
		return (NULL);
	for (i = 0; tokens; i++)
	{
		commands[i] = tokens;
		tokens = strtok(NULL, s);
	}
	return (commands);
}
