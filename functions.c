#include "functions.h"

/**
 * handle_path - Concatenates commands  with the PATH directories.
 *
 * @commands: Commands to concatenate.
 *
 * Return: Array of strings.
 */
char **handle_path(char *commands)
{
	char *path, *token, *sub_dir, **arr_dir;
	int count = 1, i = 0;

	path = get_env("PATH");
	for (; path[i]; i++)
	{
		if (path[i] == ':')
			count++;
	}
	arr_dir = malloc(sizeof(char *) * (count + 1));
	token = strtok(path, ":");
	for (i = 0; token != NULL; i++)
	{
		sub_dir = malloc(_strlen(token) + _strlen(commands + 2));
		_strcpy(sub_dir, token);
		_strcat(sub_dir, "/");
		_strcat(sub_dir, commands);
		arr_dir[i] = sub_dir;
		token = strtok(NULL, ":");
	}
	free(path);
	arr_dir[count] = NULL;
	return (arr_dir);
}

/**
 * get_commands - Takes a string as a command.
 *
 * Return: Array of characteres.
 */
char *get_commands(void)
{
	char *string, *line = NULL;
	size_t len = 0;
	int read, i;

	write(1, "$ ", 2);
	read = getline(&line, &len, stdin);
	if (read == -1)
	{
		free(line);
		return (0);
	}
	string = malloc(_strlen(line));
	for (i = 0; i < _strlen(line) - 1; i++)
	{
		string[i] = line[i];
	}
	string[i] = '\0';
	free(line);
	return (string);
}

/**
 * get_env - Search for an enviroment variable.
 * @name: Enviroment variable name.
 *
 * Return: Pointer to the value of the variable.
 */
char *get_env(const char *name)
{
	int i;
	char *value = NULL;
	env_t *head = NULL;

	for (i = 0; environ[i]; i++)
	{
		add_node_env(&head, environ[i]);
	}
	while (head != NULL)
	{
		if (!_strcmp(head->token, name))
			value = _strdup(head->value);
		head = head->next;
	}
	free_list_env(head);
	return (value);
}

/**
 * get_argv - Tokenize a string from the command line.
 * @input: String from the command line.
 *
 * Return: Array of string.
 */
char **get_argv(char *input)
{
	int count = 0, i = 0;
	char *t, **av, *_array, **tmp;
	list_t *head = NULL;
	struct stat st;

	_array = _strdup(input);
	free(input);
	t = strtok(_array, " ");
	while (t != NULL)
	{
		add_node_at_end(&head, t);
		count++;
		t = strtok(NULL, " ");
	}
	free(_array);
	av = malloc(sizeof(char *) * (count + 1));
	while (i < count)
	{
		av[i] = _strdup(head->string);
		head = head->next;
		i++;
	}
	free_list(head);
	av[count] = NULL;
	execute_builtin(av);
	if (av[0][0] != '/')
	{
		tmp = handle_path(av[0]);
		for (i = 0; tmp[i]; i++)
		{
			if (stat(tmp[i], &st) == 0  && st.st_mode & S_IXUSR)
			{
				free(av[0]);
				av[0] = _strdup(tmp[i]);
			}
		}
		free_array(tmp);
	}
	return (av);
}

/**
 * execute_builtin - Executes builtins commands.
 * @vector: Array.
 *
 * Return: Nothing.
 *
 */
void execute_builtin(char **vector)
{
	int i = 0;

	if (_strcmp(vector[0], "exit") == 0)
	{
		free_array(vector);
		exit(1);
	}
	if (_strcmp(vector[0], "env") == 0)
	{
		while (environ[i])
		{
			write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
			write(STDOUT_FILENO, "\n", 1);
			i++;
		}
		free_array(vector);
		exit(0);
	}
}
