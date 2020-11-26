#include "shell.h"

/**
 * main - main function to execute the shell, deterninate
 * if the shell going to run in interactive or no-interactive
 * mode
 *
 * Return: Always 0 (Success)
 */

int main(void)
{
	if (isatty(STDIN_FILENO))
		sh_interactive();
	else
		sh_nointeractive();

	return (0);
}
