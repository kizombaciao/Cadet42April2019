/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchao <cchao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 16:27:29 by cchao             #+#    #+#             */
/*   Updated: 2019/05/10 19:57:42 by cchao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *p;

	if (!(p = (void *)malloc(sizeof(void) * size)))
		return (NULL);
	ft_bzero(p, size);
	return (p);
}

/*
** TWO OPTIONS:
** ft_memset(m, 0, size);
**
** Note:  use NULL when you need to return empty as pointer
**
** Allocates (with malloc(3)) and returns a “fresh” memory area.
** The memory allocated is initialized to 0.
** If the alloca- tion fails, the function returns NULL.
**
** i = 0;
**	while (i < size)
**		r[i++] = '\0';
**
** Return value: The allocated memory area.
*/
