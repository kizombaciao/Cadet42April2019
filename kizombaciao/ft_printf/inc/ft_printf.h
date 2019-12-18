#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdint.h>
# include <limits.h>

typedef struct s_p_string
{
	const char 	*s;
	size_t		length;
}			t_p_string;

typedef struct s_p_parameter
{
	t_p_string		s;
	int				access;
	int				flags;
	unsigned int	width;
	int				width_access;
	int				precision;
}   t_p_parameter;

int ft_printf(const char *s, ...);


#endif