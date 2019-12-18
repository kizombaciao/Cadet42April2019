/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchao <cchao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 16:27:38 by cchao             #+#    #+#             */
/*   Updated: 2019/05/10 19:51:42 by cchao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char *p1;
	unsigned char *p2;

	p1 = (unsigned char *)s1;
	p2 = (unsigned char *)s2;
	if (s1 == s2 || n == 0)
		return (0);
	while (n--)
	{
		if (*(p1) != *(p2))
		{
			return (*p1 - *p2);
		}
		p1++;
		p2++;
	}
	return (0);
}

/*
** why does the result differ from memcmp.c ???
**
** The memcmp() function compares byte string s1 against byte string s2.  Both
**     strings are assumed to be n bytes long.
**
** RETURN VALUES
** The memcmp() function returns zero
** if the two strings are identical, otherwise
** returns the difference between the first two differing bytes (treated as
** unsigned char values,
** so that `\200' is greater than `\0', for example).  Zero-
** length strings are always identical.
** This behavior is not required by C and
** portable code should only depend on the sign of the returned value.
*/
