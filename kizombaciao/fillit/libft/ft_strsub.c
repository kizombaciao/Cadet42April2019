/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchao <cchao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 16:29:34 by cchao             #+#    #+#             */
/*   Updated: 2019/05/10 19:57:55 by cchao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	i;

	if (!s)
		return (NULL);
	if (!(p = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (len-- && s[i])
	{
		p[i++] = s[start++];
	}
	p[i] = '\0';
	return (p);
}

/*
**  // test for s[i] ???
**
** Allocates (with malloc(3)) and returns
** a “fresh” substring from the string given as argument.
** The substring begins at indexstart and is of size len.
** If start and len aren’t refering to a valid substring,
** the behavior is undefined. If the allocation fails,
** the function returns NULL.
** Return value
** The substring.
*/
