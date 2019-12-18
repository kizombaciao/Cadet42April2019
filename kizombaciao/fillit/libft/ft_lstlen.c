/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchao <cchao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 16:27:18 by cchao             #+#    #+#             */
/*   Updated: 2019/05/10 19:14:06 by cchao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_lstlen(const t_list *lst)
{
	t_list *c;
	size_t l;

	c = (t_list *)lst;
	l = 0;
	while (c)
	{
		l++;
		c = c->next;
	}
	return (l);
}

/*
** then why pass as a const???
** Is the typecasting needed???
*/
