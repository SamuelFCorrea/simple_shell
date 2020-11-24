#include "shell.h"

int main()
{
	if (isatty(STDIN_FILENO))
		sh_interactive();
	else
		sh_nointeractive();

	return (0);
}
