#include "ft.h"

int ft_isspace(char c)
{
    return (c == '\t' || c == '\n' || c == 'v' || c == '\f' || c == 'r' || c == ' ');
}

// how about integer overflow???
int ft_atoi(const char *s)
{
    int i;
    int n;
    int sign;

    while (ft_isspace(*s++))
        ;
    
    sign = 1;
    if (*s == '-')
        sign = -1;

    if (*s == '+' || *s == '-')
        s++;

    n = 0;
    while (ft_isdigit(*s))
    {
        n = n * 10 + (*s - '0');
        s++;
    }
    return (sign * n);
}