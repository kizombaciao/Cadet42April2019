/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchao <cchao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 16:28:18 by cchao             #+#    #+#             */
/*   Updated: 2019/05/10 19:44:35 by cchao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	int			i;
	size_t		len;

	len = ft_strlen(s1);
	i = 0;
	while (s2[i])
	{
		s1[len + i] = s2[i];
		i++;
	}
	s1[len + i] = '\0';
	return (s1);
}

/*
**    The strcat() function appends the src string to the dest string,
**    overwriting the terminating null byte ('\0') at the end of dest, and
**    then adds a terminating null byte.  The strings may not overlap, and
**    the dest string must have enough space for the result.  If dest is
**    not large enough, program behavior is unpredictable; buffer overruns
**    are a favorite avenue for attacking secure programs.
**
**    RETURN VALUE
**    The strcat() and strncat() functions return a pointer to the
**    resulting string dest.
*/
