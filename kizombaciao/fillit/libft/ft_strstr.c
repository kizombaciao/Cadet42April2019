/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchao <cchao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 16:29:32 by cchao             #+#    #+#             */
/*   Updated: 2019/05/10 19:37:35 by cchao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *hay, const char *needle)
{
	int i;
	int j;

	if (!*needle)
		return ((char *)hay);
	i = 0;
	while (hay[i])
	{
		j = 0;
		while (hay[i + j] == needle[j])
		{
			j++;
			if (!needle[j])
				return (&((char *)hay)[i]);
		}
		i++;
	}
	return (0);
}

/*
** The strstr() function locates the first occurrence of
** the null-terminated string s2 in the null-terminated string s1.
** If s2 is an empty string, s1 is returned; if s2 occurs nowhere in s1,
** NULL is returned; otherwise a pointer to the first character
** of the first occurrence of s2 is returned.
*/
