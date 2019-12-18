/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchao <cchao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 16:28:56 by cchao             #+#    #+#             */
/*   Updated: 2019/05/10 19:59:29 by cchao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*p;
	size_t	l;
	size_t	i;

	if (!s || !f)
		return (NULL);
	l = ft_strlen(s);
	if (!(p = (char *)malloc(sizeof(char) * (l + 1))))
		return (NULL);
	i = 0;
	while (i < l)
	{
		p[i] = f(s[i]);
		i++;
	}
	p[i] = '\0';
	return (p);
}

/*
** Applies the function f to each character
** of the string given as argument to create
** a “fresh” new string (with malloc(3))
** resulting from the successive applications of f.
** Return value
** The “fresh” string created
** from the successive applications of f.
*/
