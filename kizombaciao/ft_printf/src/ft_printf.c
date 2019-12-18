#include "../inc/ft_printf.h"
#include "../libft/libft.h"


static int p_parse_inner(const char *s, size_t *i, int *valid)
{
	if (!s[*i])
		return (1);
	
}

int p_parse(char *s, va_list av)
{
	size_t i;
	size_t start;
	int count;
	int valid;

	i = 0;
	count = 0;
	while (s[i])
	{
		start = i;
		valid = 0;
		if (s[i] == '%')
		{
			i++;

		}
	}	

}

int ft_printf(const char *s, ...)
{
    va_list av;
    int ac;

    ac = 0;
    if (s)
    {
        va_start(av, s);
        ac = p_parse(1, s, av);
        va_end(av);
    }
    return (ac);
}

/*
int ft_printf2(int fd, const char *s, va_list ap)
{
    t_p p; // TRY POINTER HERE!!!

    printf("\n111a  %zu", p.buffer_length);


    ft_bzero(&p, sizeof(p)); // ???
    p.fd = fd;
    va_copy(p.ap, ap); // copies content of va_list variables
    p.s = s;
    p.start = p.s;

    while (*p.s)
    {
        if (*p.s != '%')
            p.s++;
        else
        {
            buffer(&p, p.start, p.s - p.start);
        }
        

    }
    buffer(&p, p.start, p.s - p.start);


    return (p.length);
}
*/
