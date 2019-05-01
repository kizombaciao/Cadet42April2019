#include "ft.h"

char *ft_strcpy(char *d, const char *s)
{
    char *ds;

    if (d && s) // you don't need to dereference???
    {
        ds = d;
        while ((*d++ = *s++))
            ;
        return (ds);
    }
    return (NULL);
}

// test this code!!!
// https://searchcode.com/codesearch/view/93942178/