#include "shell.h"

/**
 * sh_interactive - keeps the shell in an interactive mode
 *
 * Return: none
 */

void sh_interactive(void)
{
	char *buffer = NULL, **commands = NULL;
	size_t buf_size = BUF_SIZE;
	int i;

	buffer = malloc(buf_size * sizeof(char));
	if (!buffer)
	{
		perror("Error: imposible to allocate buffer memory");
	exit(1);
	}

	while (1)
	{
		buffer = command_line(&buffer);
		if (!buffer)
			break;
		commands = parsing_line(buffer);
		if (commands)
			run_command(commands);
	}
	if (buffer)
		free(buffer);
	if (commands)
	{
		for (i = 0; commands[i]; i++)
			free(commands[i]);
		free(commands);
	}
}


/**
 * sh_noninteractive - run the command in the input and
 * finish the execution
 *
 * Return: none
 */

void sh_nointeractive(void)
{
	char *buffer = NULL, **commands = NULL;
	size_t buf_size = BUF_SIZE;
	int eof = 0, i;

	buffer = malloc(buf_size * sizeof(char));
	if (!buffer)
	{
		perror("Error: imposible to allocate buffer memory");
		exit(1);
	}

	while (1)
	{
		eof =  getline(&buffer, &buf_size, stdin);
		if (eof == -1 || !buffer)
			break;
		commands = parsing_line(buffer);
		if (commands)
			run_command(commands);
	}
	if (buffer)
		free(buffer);
	if (commands)
	free(commands);
}
