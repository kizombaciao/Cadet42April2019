/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchao <cchao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 18:40:47 by cchao             #+#    #+#             */
/*   Updated: 2019/05/10 18:48:19 by cchao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	if (ft_strchr(s, c) == NULL)
		return (NULL);
	while (*s)
		s++;
	while (*s != c)
		s--;
	return ((char *)s);
}

/*
** The strrchr() function shall locate the last occurrence of c
** (converted to a char) in the string pointed to by s.  The terminating
** NUL character is considered to be part of the string.
** Upon successful completion, strrchr() shall return a pointer to the
** byte or a null pointer if c does not occur in the string.
*/
