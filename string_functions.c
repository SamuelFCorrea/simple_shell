#include "functions.h"

/**
 * _strlen - Calculates the lenght of a string.
 * @s: String.
 *
 * Return: Lenght of the string.
 */
int _strlen(const char *s)
{
	int count = 0;

	for (; s[count]; count++)
	{}
	return (count);
}

/**
 *_strcmp - Compares two string
 * @s1: First string.
 * @s2: Second String.
 *
 * Return: Integer number as boolean.
 */
int _strcmp(const char *s1, const char *s2)
{
	const char *r = s1, *l = s2;
	int res = 0;

	for (; *r || *l; r++, l++)
	{
		res = *r - *l;
		if (res != 0)
			return (res);
	}
	return (res);
}

/**
 * *_strcpy - Copies a string.
 * @dest: Destination string.
 * @src: Source string.
 * Return: Destination string with the value copied.
 */
char *_strcpy(char *dest, char *src)
{
	int c, length;

	length = _strlen(src) + 1;
	for (c = 0; c < length && src[c] != '\0'; c++)
		dest[c] = src[c];
	if (c < length)
		dest[c] = '\0';
	return (dest);
}

/**
 * *_strcat - Concatenates two strings.
 * @dest: Destination string.
 * @src: Source string.
 * Return: Destination string with the strings concatenated.
 */
char *_strcat(char *dest, char *src)
{
	int i1, i2;

	i1 = i2 = 0;
	while (dest[i1])
		i1++;
	while (src[i2])
	{
		dest[i1 + i2] = src[i2];
		i2++;
	}
	return (dest);
}

/**
 * *_strdup - Duplicates a string.
 * @str: String to duplicate.
 * Return: Duplicated string.
 */
char *_strdup(const char *str)
{
	char *cpy;
	unsigned int i, size;

	if (str == NULL)
		return (NULL);
	size = _strlen(str);
	cpy = malloc(size + 1 * sizeof(char));
	if (cpy == NULL)
		return (NULL);
	for (i = 0; i <= size; i++)
		cpy[i] = str[i];
	return (cpy);
}
