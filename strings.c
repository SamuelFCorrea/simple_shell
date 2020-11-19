#include "shell.h"

char *_strncat(char *dest, char *src)
{
        int i, l = 0, l1 = 0;
        char *new;

        while (*(dest + l) != '\0')
                l++;
        while (*(src + l1) != '\0')
                l1++;

        new = malloc((l + l1) * sizeof(char));
        if (!new)
                return (NULL);

        for (i = 0; i < l; i++)
                *(new + i) = *(dest + i);
        for (i = 0; i < l1; i++)
                *(new + (l + i)) = *(src + i);

        return (new);
}
