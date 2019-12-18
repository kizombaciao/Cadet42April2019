/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchao <cchao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 16:27:32 by cchao             #+#    #+#             */
/*   Updated: 2019/05/11 09:57:35 by cchao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char *d;
	unsigned char *s;

	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	while (n--)
	{
		*d = *s;
		if (*s == (unsigned char)c)
			return (++d);
		d++;
		s++;
	}
	return (NULL);
}

/*
** The memccpy() function copies no more than n bytes from memory area
**       src to memory area dest, stopping when the character c is found.
**       If the memory areas overlap, the results are undefined.
**
** The memccpy() function returns a pointer to the next character in
**       dest after c, or NULL if c was not found in the first n characters of
**       src.
*/
