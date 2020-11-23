#include "shell.h"

int get_env(char *get)
{
        int j = 0, m = 1, i, l;

	l = _strlen(get);

        for (i = 0; environ[i]; i++) 
                if (environ[i][j] == *(get + j))
                        for (; m; j++)
                                if (m == l)
                                        return i;
                                else if (environ[i][j] == *(get + j))
                                        m++;
                                else
                                {
                                        m = 1;
                                        j = 0;
                                        break;
                                }
        return -1;
}

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

int _strlen(char *str)
{
	int r = 0;

	for (; *(str + r); r++)
		;
	return r;
}
