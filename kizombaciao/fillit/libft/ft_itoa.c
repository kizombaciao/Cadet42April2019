/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchao <cchao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 16:26:51 by cchao             #+#    #+#             */
/*   Updated: 2019/05/10 19:50:32 by cchao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static size_t	ft_itoa_len(int n)
{
	size_t l;

	if (!n)
		return (1);
	l = 0;
	if (n < 0)
		l++;
	while (n)
	{
		n /= 10;
		l++;
	}
	return (l);
}

char			*ft_itoa(int n)
{
	size_t	l;
	size_t	e;
	char	*s;

	l = ft_itoa_len(n);
	if (!(s = (char *)malloc(sizeof(char) * (l + 1))))
		return (NULL);
	s[l] = '\0';
	if (n < 0)
	{
		s[0] = '-';
		e = 1;
	}
	else
	{
		e = 0;
	}
	while (l-- > e)
	{
		s[l] = '0' + n % 10 * (n < 0 ? -1 : 1);
		n /= 10;
	}
	return (s);
}

/*
** Trick:  use e to stop while loop early.
** Trick:  ternary condition
** Edge:   zero condition.
** Allocate (with malloc(3)) and returns a “fresh” string end- ing with ’\0’
** representing the integer n given as argument.
** Negative numbers must be supported. If the allocation fails,
** the function returns NULL.
*/
