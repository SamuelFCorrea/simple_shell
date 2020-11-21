#include "shell.h"

char *command_line(char **buffer, size_t *buf_size, char *av)
{
        int c;

        write(1, "$ ", 2);
        /* si el usuario da la instrucción (ctrl + d) getline devolverá el valor -1*/
        c = getline(buffer, buf_size, stdin);
	/* en caso de que @c seá igual a -1 retornará NULL de lo contrario la linea del input*/
        if (c == -1)
                return (NULL);
        return (*buffer);
}

char **parsing_line(char *buffer, char *av)
{
        char **commands, *tokens;
        /* @s corresponde a los caracteres que se van a ignorar y que van
	 * a determinar lo que separa una instruccion de otra
	 */
	char *s = " \t\r\n\a";
        int i;

	/* se abre espacio para almacenar las instruciones y en caso de no
	 * poderse retorna NULL
	 */
        commands = malloc(64 * sizeof(char *));
        if (!commands)
        {
                perror("Error: imposible to allocate buffer memory");
                return (NULL);
        }

	/* se adquiere la primera instruccion y se almacena en @tokens */
        tokens = strtok(buffer, s);

	/* un bucle que va a correr mientras aun queden instrucciones */
        for (i = 0; tokens; i++)
        {
		/* se almacena la instrucción el la matriz que posteriormente
		 * vamos a devolver
		 */
                commands[i] = tokens;
		/* adquiere la siguiente instrucción */
                tokens = strtok(NULL, s);
        }
	/* retorna la matriz con las instrucciones ya formada */
        return (commands);
}
