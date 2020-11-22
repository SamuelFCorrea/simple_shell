#include "shell.h"

int main(int ac, char **av)
{
	(void)ac;

	if (isatty(STDIN_FILENO))
		sh_interactive(av[0]);
	else
		sh_nointeractive(av[0]);

	return (0);
}
