/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcut.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchao <cchao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 10:47:27 by cchao             #+#    #+#             */
/*   Updated: 2019/08/07 10:49:02 by cchao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Allocates with malloc(), and returns a "fresh" string with the length of
** the total characters gotten up to the point that it finds a specific
** character. If the allocation fails the function returns NULL.
*/

char	*ft_strcut(const char *str, char c)
{
	int		len;
	char	*cut;

	len = 0;
	while (str[len] != c && str[len])
		if (str[len++] == c)
			break ;
	if (!(cut = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	ft_strncpy(cut, str, len);
	cut[len + 1] = '\0';
	return (cut);
}
