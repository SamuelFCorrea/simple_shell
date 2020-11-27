#include "shell.h"

/**
 * ex_ec - funtion to determinate if a builtin is required
 * @commands: command and arguments
 * @i: command id
 *
 * Return: none
 */

void ex_ec(char **commands, int i)
{
	int j = 0, k;

	switch (i)
	{
		case 0:
			if (commands != NULL)
			break;
		case 1:
			while (environ[j])
			{
				k = _strlen(environ[j]);
				write(1, environ[j], k);
				write(1, "\n", 1);
				j++;
			}
			break;
		case 2:
			exit(0);
			break;
		default:
			exit(69);
	}
}

/**
 * especial_c - determinate if the command is a builtin one
 * @commands: arguments and command
 *
 * Return: if the input has a builtin command return 1,
 * otherwise return 0
 */

int especial_c(char **commands)
{
	char *ep_c[] = {"cd", "env", "exit"};
	int i, j, m = 0;

	for (i = 0; i < 3; i++)
	{
	for (j = 0; ep_c[i][j]; j++)
		if (ep_c[i][j] == commands[0][j])
			m++;
		else
		{
			m = 0;
			break;
		}
	if (m != 0)
	{
		ex_ec(commands, i);
		return (1);
	}
	}

	return (0);
}

/**
 * run_command - creates an child process and run the input command
 * @commands: command and arguments to run
 *
 * Return: none
 */

void run_command(char **commands)
{
	int m;

	m = especial_c(commands);

	if (m == 0)
	if (fork() == 0)
	{
		if (commands[0][0] == '/' || commands[0][0] == '.')
		{
			if (access(commands[0], F_OK | X_OK) == 0)
				execve(commands[0], commands, NULL);
			else
			{
				perror(commands[0]);
				exit(1);
			}
		}
		else
		{
			commands[0] = find_path(commands);
			execve(commands[0], commands, NULL);
		}
	}

	wait(NULL);
}

/**
 * find_path - finds the correct path to execute the commands
 * @commands: the command to find
 *
 * Return: the path of the command if it exist
 */

char *find_path(char **commands)
{
	int n;
	char *separator = "=:";
	char *token, *new;

	n = get_env("PATH");

	token = strtok(environ[n], separator);

	while (token)
	{
		new = _strncat(token, commands[0], 1);
		if (access(new, F_OK | X_OK) == 0)
			return (new);
		token = strtok(NULL, separator);
		free(new);
	}
	print_error(commands[0], 0);
	exit(1);
}
