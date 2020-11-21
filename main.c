#include "shell.h"

int main(int ac, char **av, char **env)
{
	int i;

	(void)ac;

	i = get_path(env);

	if (isatty(STDIN_FILENO))
		sh_interactive(av[0], env[i]);
	else
		sh_nointeractive(av[0], env[i]);

	return (0);
}
