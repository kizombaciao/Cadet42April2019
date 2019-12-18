/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchao <cchao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 16:28:38 by cchao             #+#    #+#             */
/*   Updated: 2019/05/10 19:48:14 by cchao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strequ(char const *s1, char const *s2)
{
	if (s1 == s2)
		return (1);
	if (!s1 || !s2)
		return (0);
	return (ft_strcmp(s1, s2) == 0);
}

/*
** Lexicographical comparison between s1 and s2.
** If the 2 strings are identical the function returns
** 1, or 0 otherwise.
** Return value
** 1 or 0 according to if the 2 strings are identical or not.
*/
