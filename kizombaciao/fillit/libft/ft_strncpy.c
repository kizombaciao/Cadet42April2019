/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchao <cchao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 16:29:08 by cchao             #+#    #+#             */
/*   Updated: 2019/05/14 16:09:40 by cchao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	size_t	l;

	l = ft_strnlen(src, n);
	ft_memmove(dst, src, l);
	ft_memset(dst + l, 0, n - l);
	return (dst);
}

/*
** The strcpy() function copies the string pointed to by src,
** including the terminating null byte ('\0'),
** to the buffer pointed to by dest. The strings may not overlap,
** and the destination string dest must be
** large enough to receive the copy. Beware of buffer overruns! (See BUGS.)
**
** The strncpy() function is similar,
** except that at most n bytes of src are copied. Warning:
** If there is no null byte among the first n bytes of src,
** the string placed in dest will not be
** null-terminated.
**
** If the length of src is less than n,
** strncpy() writes additional null bytes to dest to ensure
** that a total of n bytes are written.
**
** Return Value
** The strcpy() and strncpy() functions return
** a pointer to the destination string dest.
**
**  char *ds;
**
**	if (dst && src)
**	{
**		if (!n)
**			return (dst);
**		ds = dst;
**		while (n--)
**		{
**			if (*src)
**				*dst++ = *src++;
**			else
**				*dst++ = 0;
**		}
**		return (ds);
**	}
**	return (NULL);
*/
