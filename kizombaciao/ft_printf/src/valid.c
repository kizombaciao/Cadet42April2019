#include "../inc/ft_printf.h"
#include "../libft/libft.h"


int p_valid_conversion(const char c)
{
	return(ft_strchr("dDioOuUxXeEfFgGaAcCsSpn%", c) != NULL);
}

int p_valid_modifier(const char c)
{
	return(ft_strchr("hljz", c) != NULL);
}

int p_valid_flag(const char c)
{
	return(ft_strchr("#0-+' ", c) != NULL);
}

int p_valid_precision(const char c)
{
	return(ft_strchr("$*.", c) != NULL); // ??? 
}

int p_check_valid(const char c)
{
	return (p_valid_conversion(c) || p_valid_modifier(c) || p_valid_flag(c) \
		|| p_valid_digit(c) || p_valid_precision(c));
}
