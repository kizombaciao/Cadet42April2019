/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchao <cchao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 10:46:49 by cchao             #+#    #+#             */
/*   Updated: 2019/08/07 10:49:02 by cchao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Outputs the string s to the standard output.
*/

void	ft_putstr(char const *s)
{
	int		i;

	i = 0;
	if (s)
		while (s[i])
			write(1, &s[i++], 1);
}
