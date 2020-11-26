#include "functions.h"

/**
 * main - Entry point.
 *
 * Return: Always 0. (Success)
 */
int main(void)
{
	char *input, **av;
	pid_t PID;
	int status;

	while (1)
	{
		PID = fork();
		if (PID == 0)
		{
			input = get_commands();
			av = get_argv(input);
			status = execve(av[0], av, environ);
			if (status == -1)
			{
				free_array(av);
				perror("Error:");
			}
			else
				free_array(av);
		}
		else if (PID == -1)
			exit(EXIT_FAILURE);
		else
			wait(NULL);
	}
	return (0);
}
