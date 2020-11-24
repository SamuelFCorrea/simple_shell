#include "shell.h"

void sh_interactive()
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

void sh_nointeractive()
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
