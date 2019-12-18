/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchao <cchao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 16:29:00 by cchao             #+#    #+#             */
/*   Updated: 2019/05/10 19:41:35 by cchao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*p;
	unsigned int	l;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	l = ft_strlen(s);
	if (!(p = (char *)malloc(sizeof(char) * (l + 1))))
		return (NULL);
	i = 0;
	while (i < l)
	{
		p[i] = f(i, s[i]);
		i++;
	}
	p[i] = '\0';
	return (p);
}

/*
** Applies the function f to each character of the string passed
** as argument by giving its index as first argument to create
** a “fresh” new string (with malloc(3)) resulting
** from the suc- cessive applications of f.
** Param. #1
** The string to map.
** Param. #2
** The function to apply to each character of s and its index.
** Return value
** The “fresh” string created from the successive applications of f.
*/
