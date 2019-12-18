/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchao <cchao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 16:29:37 by cchao             #+#    #+#             */
/*   Updated: 2019/05/12 13:06:09 by cchao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

#include <stdio.h>

static int	ft_strtrim_space(char c)
{
	return (c == ' ' || c == '\n' || c == '\t');
}

static int	ft_strtrim_front(char const *s)
{
	int i;

	i = 0;
	while (s[i] && ft_strtrim_space(s[i]))
		i++;
	return (i);
}

static int	ft_strtrim_back(char const *s)
{
	int l;

	l = ft_strlen(s) - 1;
	while (s[l])
		if (ft_strtrim_space(s[l]))
			l--;
		else
			return (++l);
	return (++l);
}

char		*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	i = ft_strtrim_front(s);
	j = ft_strtrim_back(s);
	if (i >= j)
		return (ft_strnew(1));
	return (ft_strsub(s, i, j - i));
}

/*
**		// why did it fail the unit test???
**     // edge case if i = j ???
**
** Unlike global functions in C, access to static
** functions is restricted to the file
** where they are declared.
** Therefore, when we want to restrict access to functions,
** we make them static.
** Another reason for making functions static
** can be reuse of the same function name in other files.
**
** Allocates (with malloc(3)) and returns
** a copy of the string given as argument
** without whitespaces at the beginning
** or at the end of the string.
** Will be considered as whitespaces
** the following characters ’ ’, ’\n’
** and ’\t’.
** If s has no whites- paces
** at the beginning or at the end,
** the function returns a copy of s.
** If the allocation fails the function returns NULL.
**
** Return value
** The “fresh” trimmed string or a copy of s.
*/
