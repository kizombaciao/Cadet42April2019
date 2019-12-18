/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchao <cchao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 16:27:49 by cchao             #+#    #+#             */
/*   Updated: 2019/05/11 10:21:00 by cchao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char	*d;
	char	*s;
	size_t	i;

	if (dst == src)
		return (dst);
	d = (char *)dst;
	s = (char *)src;
	if (src < dst)
	{
		i = n;
		while (i--)
			d[i] = s[i];
	}
	else
	{
		i = 0;
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (dst);
}

/*
** Can below code also work???
** void	*tmp;
**
**	tmp = ft_memalloc(n + 1);
**	tmp = ft_memcpy(tmp, src, n);
**	dest = ft_memcpy(dest, tmp, n);
**	free(tmp);
**	return (dest);
**
** memmove() is used to copy a block of memory from a location to another.
** It is declared in string.h
**
** The memmove() function copies n bytes from memory area src to memory
** area dest.  The memory areas may overlap: copying takes place as
** though the bytes in src are first copied into a temporary array that
** does not overlap src or dest, and the bytes are then copied from the
** temporary array to dest.
*/
