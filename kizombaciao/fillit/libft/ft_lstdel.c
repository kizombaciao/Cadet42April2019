/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchao <cchao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 16:27:09 by cchao             #+#    #+#             */
/*   Updated: 2019/05/12 13:27:36 by cchao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *p;
	t_list *remove;

	p = *alst;
	while (p)
	{
		remove = p;
		p = p->next;
		ft_lstdelone(&remove, del);
	}
	*alst = NULL;
}

/*
** DESCRIBE:  DELETING THE ENTIRE LIST.
** we want to delete the entries as well as addresses!
**		remove = p;
**		del(remove->content, remove->content_size);
**		p = remove->next;
**		free(remove);
**
** void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
** {
**	if ((*alst)->next)
**		ft_lstdel(&(*alst)->next, del);
**	ft_lstdelone(alst, del);
**}
**
** Takes as a parameter the adress of a pointer to a link
** and frees the memory of this link
** and every successors of that link
** using the functions del and free(3).
** Finally the pointer to the link
** that was just freed must be set to NULL
** (quite similar to the function
** ft_memdel from the mandatory part).
*/
