/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchao <cchao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 16:28:29 by cchao             #+#    #+#             */
/*   Updated: 2019/05/11 13:50:30 by cchao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	char *p;

	p = dst;
	while ((*p++ = *src++))
		;
	*(--p) = '\0';
	return (dst);
}

/*
** 	test this code!!!
** 	https://searchcode.com/codesearch/view/93942178/
**
** 	The strcpy() function copies the string pointed to by src, including
**	the terminating null byte ('\0'), to the buffer pointed to by dest.
**	The strings may not overlap, and the destination string dest must be
**	large enough to receive the copy.  Beware of buffer overruns!  (See
**	BUGS.)
**
**	RETURN VALUE
**	The strcpy() and strncpy() functions return a pointer to the
**	destination string dest.
*/
