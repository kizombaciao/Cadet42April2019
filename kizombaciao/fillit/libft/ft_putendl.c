/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchao <cchao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 16:28:03 by cchao             #+#    #+#             */
/*   Updated: 2019/05/10 19:26:13 by cchao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putendl(char const *s)
{
	size_t l;

	l = ft_strlen(s);
	write(1, s, l);
	ft_putchar('\n');
}

/*
** Outputs the string s to the standard output followed by a ’\n’.
*/
