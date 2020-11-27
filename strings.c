#include "shell.h"

/**
 * _pwd - find a variable in the enviroment
 * @s: var to find
 *
 * Return: the variable value
 */

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

/**
 * get_env - get a enviroment variable
 * @get: variable to get
 *
 * Return: position of the variable in environ
 */

int get_env(char *get)
{
	int j = 0, m = 1, i, l;

	l = _strlen(get);

	for (i = 0; environ[i]; i++)
		if (environ[i][j] == *(get + j))
			for (; m; j++)
				if (m == l)
					return (i);
				else if (environ[i][j] == *(get + j))
					m++;
				else
				{
					m = 1;
					j = 0;
					break;
				}
	return (-1);
}

/**
 * _strncat - concatenate two strings
 * @dest: principal string
 * @src: string to add
 * @c: option
 *
 * Return: concatenated string
 */

char *_strncat(char *dest, char *src, int c)
{
	int i, l = 0, l1 = 0;
	char *new;

	while (*(dest + l) != '\0')
		l++;
	while (*(src + l1) != '\0')
		l1++;

	new = malloc((l + l1 + 1) * sizeof(char));
	if (!new)
		return (NULL);

	for (i = 0; i < l; i++)
		*(new + i) = *(dest + i);
	if (c == 1)
		*(new + i) = '/';
	for (i = 0; i < l1; i++)
		*(new + (l + i + c)) = *(src + i);
	return (new);
}

/**
 * _strlen - get the string lenght
 * @str: input string
 *
 * Return: length of the string
 */

int _strlen(char *str)
{
	int r = 0;

	for (; *(str + r); r++)
		;
	return (r);
}
