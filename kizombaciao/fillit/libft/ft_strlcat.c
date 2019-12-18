/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchao <cchao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 16:28:50 by cchao             #+#    #+#             */
/*   Updated: 2019/05/11 10:22:01 by cchao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t dlen;
	size_t slen;
	size_t i;
	size_t j;

	dlen = ft_strnlen(dst, size);
	slen = ft_strlen(src);
	if (dlen < size)
	{
		i = dlen;
		j = 0;
		while (i < size && j < slen)
			dst[i++] = src[j++];
		if (i < size)
			dst[i] = '\0';
		else
			dst[size - 1] = '\0';
	}
	return (dlen + slen);
}

/*
** // if amount of space in dst, limited by '\0', is less than size,
** // then what you return is i + slen, where i = ft_strlen(dst)
** // but if dst has sufficient space to fit size,
** // then what you return is size + slen.
**
**     size_t i;
**     size_t len;
**
**     len = ft_strlen(dst);
**     i = 0;
**     while (src[i] && i < size)
**     {
**         dst[len + i] = src[i];
**         i++;
**     }
**     dst[len + i] = '\0';
**
**     len = ft_strlen(src);
**     return (len + size); // is it size or len of dst???
**
**     Appends the NULL-terminated string src to the end of dst.
**     It will append at most size - strlen(dst) - 1 bytes, NULL-terminating
**     the result.
**
**     Return Values
**     The strlcpy() and strlcat() functions return
**		the total length of the string
**     they tried to create. For strlcpy()
**		that means the length of src. For strlcat()
**     that means the initial length of dst
**		plus the length of src. While this may seem
**     somewhat confusing, it was done to make truncation detection simple.
**
**     Note, however, that if strlcat() traverses
** 		size characters without finding a NUL,
**     the length of the string is considered to be size
**		and the destination string will
**     not be NUL-terminated
**		(since there was no space for the NUL). This keeps strlcat()
**     from running off the end of a string.
**		In practice this should not happen (as it means
**     that either size is incorrect or that dst is not a proper ''C'' string).
**     The check exists to prevent potential security problems
**		in incorrect code.
*/
