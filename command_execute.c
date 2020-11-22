#include "shell.h"

void ex_ec(char **commands, int i)
{
	int j = 0, k;

	switch (i)
	{
		case 0:
			if (chdir(commands[1]) == -1)
				perror("error cd");
			break;
		case 1:
			if (fork() == 0)
			while(environ[j])
			{
				k = _strlen(environ[j]);
				write(1, environ[j], k);
				write(1, "\n", 1);
				j++;
			}
			wait(NULL);
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

void run_command(char **commands, char *av)
{
	int m;

	m = especial_c(commands);
	
	if (m == 0)
	if (fork() == 0)
	{
	/* si el comando comienza con '/' correrá el comando sin intentar
	 * encontrarlo en las rutas del path, pues se le estará dando la
	 * direccion que se va a utilizar
	 */
	        if (commands[0][0] == '/' || commands[0][0] == '.')
       		{
		/* comprueba si el archivo existe y se tienen los permisos para
		 * ejecutarlos
		 * en caso de tenerlos se ejecuta la funcion execve de lo contrario
		 * se manda el mensaje de error
		 */
           	        if (access(commands[0], F_OK | X_OK) == 0)
                        	execve(commands[0], commands, NULL);
                	else
        	        {
	                        perror(commands[0]);
                        	exit(1);
                	}
        	}
		/* si el comando no esta especificando la direccion del ejecutable */
        	else
		{
			commands[0] = find_path(commands);
                	execve(commands[0], commands, NULL);
		}
	}
	wait(NULL);
}

char *find_path(char **commands)
{
	int n;
	char *separator = "=:";
	char *token, *new;

	n = get_path(environ);

	token = strtok(environ[n], separator);

	while (token)
	{
		new = _strncat(token, commands[0]);
		if (access(new, F_OK | X_OK) == 0)
			return (new);
		else
			token = strtok(NULL, separator);
		free(new);
	}
	perror("Error");
	exit(1);
}
