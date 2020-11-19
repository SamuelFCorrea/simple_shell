#include "shell.h"

void run_command(char **commands, char *av, char **env)
{
	/* si el comando comienza con '/' correrá el comando sin intentar
	 * encontrarlo en las rutas del path, pues se le estará dando la
	 * direccion que se va a utilizar
	 */
        if (commands[0][0] == '/')
        {
		/* comprueba si el archivo existe y se tienen los permisos para
		 * ejecutarlos
		 * en caso de tenerlos se ejecuta la funcion execve de lo contrario
		 * se manda el mensaje de error
		 */
                if (access(commands[0], F_OK | X_OK) == 0)
                        execve(commands[0], commands, env);
                else
                {
                        perror(commands[0]);
                        exit(1);
                }
        }
	/* si el comando no esta especificando la direccion del ejecutable */
        else
        {
		/* añade la ruta "/bin/" a la ruta del archivo para comprobar si existe */
                commands[0] = _strncat("/bin/", commands[0]);
		/* en caso de que ocurra un error mientras se añade el path retorna 1 */
                if (commands == NULL)
                        exit(1);
		/* en caso de que se encuentre el archivo en la nueva ruta lo ejecuta */
                if (access(commands[0], F_OK | X_OK) == 0)
                        execve(commands[0], commands, env);
		/* en caso de que no se encuentre el archivo imprime el mensaje de error */
                else
                {
                        perror(commands[0]);
                        exit(1);
                }
        }
}
