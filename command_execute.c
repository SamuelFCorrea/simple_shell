#include "shell.h"

void cd(char **command)
{
	char *pwd, *actual;
	size_t b = BUF_SIZE, c;

	pwd = malloc(b * sizeof(char));
	if (!pwd)
	{
		perror("failed to allocate memory");
		exit(1);
	}
	actual = malloc(b * sizeof(char));
	if (!actual)
	{
		free(pwd);
		perror("failed to allocate memory");
		exit(1);
	}
	getcwd(actual, b);
	if (!command[1])
	{
		pwd = _pwd("HOME=");
		chdir(pwd);
		c = get_env("OLDPWD");
		environ[c] = _strncat("OLDPWD=", actual, 0);
		c = get_env("PWD");
		environ[c] = _strncat("PWD=", pwd, 0);
	}
	else if (command[1][0] == '-')
	{
		c = get_env("OLDPWD");
		if (c == -1)
			perror("No OLDPWD");
		else
		{
			pwd = _pwd("OLDPWD=");
			chdir(pwd);
			c = get_env("OLDPWD");
			environ[c] = _strncat("OLDPWD=", actual, 0);
			c = get_env("PWD");
			environ[c] = _strncat("PWD=", pwd, 0);
		}
	}
	else
	{
		if (chdir(command[1]) == -1)
		{
			free(pwd);
			free(actual);
			perror("fail");
		}
		else
		{
			getcwd(pwd, b);
			c = get_env("OLDPWD");
			environ[c] = _strncat("OLDPWD=", actual, 0);
			c = get_env("PWD");
			environ[c] = _strncat("PWD=", pwd, 0);
		}
	}
}

void ex_ec(char **commands, int i)
{
	int j = 0, k;

	switch (i)
	{
		case 0:
			cd(commands);
			break;
		case 1:
			while(environ[j])
			{
				k = _strlen(environ[j]);
				write(1, environ[j], k);
				write(1, "\n", 1);
				j++;
			}
			break;
		case 2:
			exit(1);
			break;
		default:
			exit(69);
	}
}

int especial_c(char **commands)
{
	char *ep_c[] = {"cd", "env", "exit"};
	int i, j, m = 0;

	for (i = 0; i < 3; i++)
	{
	for (j = 0; ep_c[i][j]; j++)
		if (ep_c[i][j] == commands[0][j])
			m++;
		else
		{
			m = 0;
			break;
		}
	if (m != 0)
	{
		ex_ec(commands, i);
		return 1;
	}
	}

	return 0;
}

void run_command(char **commands)
{
	int m;

	m = especial_c(commands);
	
	if (m == 0)
	if (fork() == 0)
	{
	        if (commands[0][0] == '/' || commands[0][0] == '.')
       		{
           	        if (access(commands[0], F_OK | X_OK) == 0)
                        	execve(commands[0], commands, NULL);
                	else
        	        {
	                        perror(commands[0]);
                        	exit(1);
                	}
        	}
        	else
		{
			commands[0] = find_path(commands);
                	execve(commands[0], commands, NULL);
		}
	}
	wait(NULL);
}


char *_pwd(char *s)
{
	int n;
	char *token;

	n = get_env(s);
	if (n == -1)
		return (NULL);

	token = strtok(environ[n], s);

	return (token);
}

char *find_path(char **commands)
{
	int n;
	char *separator = "=:";
	char *token, *new;

	n = get_env("PATH");

	token = strtok(environ[n], separator);

	while (token)
	{
		new = _strncat(token, commands[0], 1);
		if (access(new, F_OK | X_OK) == 0)
			return (new);
		else
			token = strtok(NULL, separator);
		free(new);
	}
	perror("Error");
	exit(1);
}
