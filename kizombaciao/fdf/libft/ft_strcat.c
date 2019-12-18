/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchao <cchao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 10:47:05 by cchao             #+#    #+#             */
/*   Updated: 2019/08/07 10:49:02 by cchao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Appends a copy of the null-terminated string s2 to the end of the
** null-terminated string s1, then add a terminating '/0'. The string s1
** must have sufficient space to hold the result.
*/

char	*ft_strcat(char *s1, const char *s2)
{
	unsigned int	i;
	unsigned int	len;

	i = 0;
	len = ft_strlen(s1);
	while (s2[i])
	{
		s1[len + i] = s2[i];
		i += 1;
	}
	s1[len + i] = '\0';
	return (s1);
}
