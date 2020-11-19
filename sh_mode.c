#include "shell.h"

void sh_interactive()
{
        char *buffer, **commands;
        size_t buf_size = 1024;

	/* crea y examina si hay espacio para el buffer */
        buffer = malloc(buf_size * sizeof(char));
        if (!buffer)
        {
                perror("Error: imposible to allocate buffer memory");
                exit(1);
        }

	/* bucle infinito para recibir los comandos */
        while (1)
        {
		/* en command_line leerá la linea que se escribá y la devolverá */
                buffer = command_line(&buffer, &buf_size);
                /* command_line retornará NULL en caso de que se de la instrucción de ctrl+d */
		if (!buffer)
                        break;
		/* parsing_line dividirá la string del input en varias, correspondientes a
		 * cada instrucción
		 */
                commands = parsing_line(buffer);
                /* se abre un nuevo proceso y en el subproceso se lanza la función de run_commands */
		if (fork() == 0)
                        run_command(commands);
		/* se espera a que se termine la ejecución del proceso para comenzar con la
		 * siguiente ejecución del bucle
		 */
                wait(NULL);
        }
}

void sh_nointeractive()
{
        char *buffer, **commands;
        size_t buf_size = 1024;

	/* crea y examina si hay espacio para el buffer */
        buffer = malloc(buf_size * sizeof(char));
        if (!buffer)
        {
                perror("Error: imposible to allocate buffer memory");
                exit(1);
        }

	/* obtiene la string que se paso y la almacena en el buffer */
        getline(&buffer, &buf_size, stdin);
	/* almacena en @commands las instruciones ya separadas */
        commands = parsing_line(buffer);
	/* se ejecuta el comando que se pasó */
        run_command(commands);
}
