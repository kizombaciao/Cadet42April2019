/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchao <cchao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 16:27:35 by cchao             #+#    #+#             */
/*   Updated: 2019/05/11 09:58:24 by cchao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *s2;
	unsigned char c2;

	s2 = (unsigned char *)s;
	c2 = (unsigned char)c;
	while (n--)
	{
		if (*s2++ == c2)
			return (--s2);
	}
	return (NULL);
}

/*
** Note, void ptr can take addresses of any data type.
** But void ptr can not be dereferenced because it has no data type.
**
** The memchr() function locates the first occurrence of c (converted to an
**     unsigned char) in string s.
**
** RETURN VALUES
**     The memchr() function returns
** a pointer to the byte located, or NULL if no such
**     byte exists within n bytes.
*/
