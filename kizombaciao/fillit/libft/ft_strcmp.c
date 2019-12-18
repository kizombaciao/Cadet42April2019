/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchao <cchao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 16:28:26 by cchao             #+#    #+#             */
/*   Updated: 2019/05/11 10:22:23 by cchao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
	{
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

/*
**    HOW COME IT IS OKAY TO RETURN UNSIGNED FOR AN INT FUNCTION???
**    The strcmp() function compares the two strings s1 and s2.  The locale
**    is not taken into account (for a locale-aware comparison, see
**    strcoll(3)).  It returns an integer less than, equal to, or greater
**    than zero if s1 is found, respectively, to be less than, to match, or
**    be greater than s2.
**
**    RETURN VALUE
**
**    The strcmp() and strncmp() functions return an integer less than,
**    equal to, or greater than zero if s1 (or the first n bytes thereof)
**    is found, respectively, to be less than, to match, or be greater than
**    s2.
*/
