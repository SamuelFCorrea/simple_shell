#include "shell.h"

int help_function(var_s *vars)
{
	int i = 0;

	help help_list[] = {
		{"exit", help_exit},
		{"env", help_env},
		{"help", help_help},
		{NULL, NULL}
	};

	char *value;

	value = tokens[1];
	status = 0;

	if (value == NULL || value[0] == '\0')
	{
		print_help();
		return (0);
	}
	while (help_list[i].fc)
	{
		if (strcmp(tokens[1], help_list[i]) == 0)
		{
			help_list[i]();
			return (0);
		}
		i++;
	}
	return (1);
}

void print_help(void)
{
	_puts("These shell commands are defined internally.\n\n");
	_puts("\tType 'help' to see this list. Type 'help name'\n");
	_puts("\tto find out more about the function 'name'.\n\n");
	_puts("\texit [STATUS]\n");
	_puts("\tenv\n");
	_puts("\thelp [BUILT-IN]\n");
}

void help_exit(void)
{
	_puts("exit: exit [STATUS]\n");
	_puts("\tExits the shell.\n");
}

void help_help(void)
{
	_puts("help: help [BUILT-IN]\n");
	_puts("\tDisplays information about built-in commands.\n\n");
	_puts("\tUsed as help [BUILT-IN] to give detailed help\n");
	_puts("\tof the command specified. Otherwise will print\n");
	_puts("\tthe list of help commands avaliable.\n");
}

void help_env(void)
{
	_puts("env: env\n");
	_puts("\tPrints the current environment.\n");
}
