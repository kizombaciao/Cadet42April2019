/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchao <cchao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 16:27:21 by cchao             #+#    #+#             */
/*   Updated: 2019/05/10 20:07:04 by cchao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *p;

	if (lst)
	{
		p = f(lst);
		p->next = ft_lstmap(lst->next, f);
		return (p);
	}
	return (NULL);
}

/*
**	l = ft_lstlen(lst);
**
** Iterates a list lst
** and applies the function f to each link
** to create a “fresh” list
** (using malloc(3))
** resulting from the successive applications of f.
** If the allocation fails, the function returns NULL.
**
** Return value
** The new list.
*/
