#include "shell.h"

void run_command(char **commands, char *av, char *env)
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
		commands[0] = find_path(commands, env);
                execve(commands[0], commands, NULL);
	}
}

char *find_path(char **commands, char *path)
{
	char *separator = "=:";
	char *token, *new;

	token = strtok(path, separator);

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
