#include "shell.h"

char *command_line(char **buffer)
{
        int c;
	size_t buf_size = BUF_SIZE;

        write(1, ">> ", 3);
        c = getline(buffer, &buf_size, stdin);
        if (c == -1)
                return (NULL);
        return (*buffer);
}

char **parsing_line(char *buffer)
{
        char **commands = NULL, *tokens = NULL;
	char *s = " \t\r\n\a";
        int i;

        commands = malloc(64 * sizeof(char *));
        if (!commands)
        {
                perror("Error: imposible to allocate buffer memory");
                return (NULL);
        }

        tokens = strtok(buffer, s);
	if (!tokens)
		return (NULL);
        for (i = 0; tokens; i++)
        {
                commands[i] = tokens;
                tokens = strtok(NULL, s);
        }
        return (commands);
}
