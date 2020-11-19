#include "shell.h"

int main(int ac, char **av, char **env)
{
	(void)ac;

	if (isatty(STDIN_FILENO))
		sh_interactive(av[0], env);
	else
		sh_nointeractive(av[0], env);

	return (0);
}
