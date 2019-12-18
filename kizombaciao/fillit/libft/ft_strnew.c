/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchao <cchao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 16:29:17 by cchao             #+#    #+#             */
/*   Updated: 2019/05/10 19:58:13 by cchao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	return (ft_memalloc(size + 1));
}

/*
** // this is to initialize a string so need an ending '\0'
**
** Allocates (with malloc(3)) and
** returns a “fresh” string end- ing with ’\0’.
** Each character of the string is
** initialized at ’\0’.
** If the allocation fails the function returns NULL.
** Return value
** The string allocated and initialized to 0.
*/
