/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_program_name.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchao <cchao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 10:46:34 by cchao             #+#    #+#             */
/*   Updated: 2019/08/07 10:49:02 by cchao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Gets the name of the program (av[0]).
*/

char	*ft_program_name(char const *av0)
{
	char *name;

	name = (char *)av0;
	while (*name && *name != '/')
		name += 1;
	if (!name)
		return ((char *)av0);
	return (name + 1);
}
