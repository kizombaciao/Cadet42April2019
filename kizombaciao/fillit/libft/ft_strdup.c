/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchao <cchao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 16:28:35 by cchao             #+#    #+#             */
/*   Updated: 2019/05/10 20:12:23 by cchao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	int		i;
	int		len;
	char	*d;

	len = ft_strlen(s);
	if (!(d = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (s[i])
	{
		d[i] = s[i];
		i++;
	}
	d[i] = '\0';
	return (d);
}

/*
**    The strdup() function returns a pointer to a new string which is a
**    duplicate of the string s.  Memory for the new string is obtained
**    with malloc(3), and can be freed with free(3).
**
**    RETURN VALUE
**    On success, the strdup() function returns a pointer to the duplicated
**    string.  It returns NULL if insufficient memory was available, with
**    errno set to indicate the cause of the error.
*/
