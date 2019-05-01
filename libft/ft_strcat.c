#include "ft.h"

char *ft_strcat(char *s1, const char *s2)
{
    int i;
    size_t len;

    len = ft_strlen(s1);
    i = 0;
    while (s2[i])
    {
        s1[len + i] = s2[i];
        i++;
    }
    s1[len + i] = '\0'; // can we use NULL??? which library is needed???
    return (s1);
}

// Is null termination required???