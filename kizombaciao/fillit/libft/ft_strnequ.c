/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchao <cchao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 16:29:11 by cchao             #+#    #+#             */
/*   Updated: 2019/05/10 19:43:28 by cchao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	if (s1 == s2)
		return (1);
	if (!s1 || !s2)
		return (0);
	return (ft_strncmp(s1, s2, n) == 0);
}

/*
** Lexicographical comparison between s1 and s2
** up to n char- acters or until a ’\0’ is reached.
** If the 2 strings are identical, the function
** returns 1, or 0 otherwise.
** Return value
** 1 or 0 according to if the 2 strings are identical or not.
*/
