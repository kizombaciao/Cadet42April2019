/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchao <cchao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 16:29:23 by cchao             #+#    #+#             */
/*   Updated: 2019/05/12 09:53:52 by cchao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hay, const char *needle, size_t n)
{
	size_t len;

	if (!*needle)
		return ((char *)hay);
	len = ft_strlen(needle);
	while (*hay && n-- >= len)
	{
		if (*hay == *needle && ft_memcmp(hay, needle, len) == 0)
			return ((char *)hay);
		hay++;
	}
	return (NULL);
}

/*
**  why did it fail the unit test???
** // && n - i)  <- is this needed???
**    The strstr() function locates the first occurrence of the null-terminated
**     string needle in the null-terminated string haystack.
**
**    The strnstr() function locates the first occurrence of the null-termi-
**     nated string needle in the string haystack, where not more than len char-
**     acters are searched.  Characters that appear after a `\0' character are
**     not searched.  Since the strnstr() function is a FreeBSD specific API, it
**     should only be used when portability is not a concern
*/
