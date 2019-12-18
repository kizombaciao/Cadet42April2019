/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchao <cchao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 16:28:48 by cchao             #+#    #+#             */
/*   Updated: 2019/05/10 19:43:03 by cchao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		l1;
	size_t		l2;
	char		*s;

	if (!s1 || !s2)
		return (NULL);
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	if (!(s = malloc(sizeof(char *) * l1 + l2 + 1)))
		return (NULL);
	ft_memcpy(s, s1, l1);
	ft_memcpy(s + l1, s2, l2);
	s[l1 + l2] = '\0';
	return (s);
}

/*
** Allocates (with malloc(3)) and returns
** a “fresh” string end- ing with ’\0’,
** result of the concatenation of s1 and s2.
** If the allocation fails the function returns NULL.
** Return value
** The “fresh” string result of the concatenation of the 2 strings.
*/
