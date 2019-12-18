/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchao <cchao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 16:28:32 by cchao             #+#    #+#             */
/*   Updated: 2019/05/10 20:06:32 by cchao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strdel(char **as)
{
	if (as && *as)
		ft_memdel((void **)as);
}

/*
**  Note, 'as && *as' !!!
**
** Takes as a parameter the address of a string
** that need to be freed with free(3),
** then sets its pointer to NULL.
*/
