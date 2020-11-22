#include "shell.h"

int get_path(char **env)
{
        int j = 0, m = 1, i;
        char *path = "PATH";

        for (i = 0; env[i]; i++) 
                if (env[i][j] == *(path + j))
                        for (; m; j++)
                                if (m == 4)
                                        return i;
                                else if (env[i][j] == *(path + j))
                                        m++;
                                else
                                {
                                        m = 1;
                                        j = 0;
                                        break;
                                }
        return -1;
}

char *_strncat(char *dest, char *src)
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
	*(new + i) = '/';
        for (i = 0; i < l1; i++)
                *(new + (l + i + 1)) = *(src + i);

        return (new);
}

int _strlen(char *str)
{
	int r = 0;

	for (; *(str + r); r++)
		;
	return r;
}
