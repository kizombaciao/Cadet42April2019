/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchao <cchao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 16:27:12 by cchao             #+#    #+#             */
/*   Updated: 2019/05/11 09:56:11 by cchao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	del((*alst)->content, (*alst)->content_size);
	free(*alst);
	*alst = NULL;
}

/*
** DESCRIBE:  JUST DELETING THE ADDRESS AND ENTRIES FOR A SINGLE NODE.
**
** Takes as a parameter a link’s pointer address
** and frees the memory of the link’s content
** using the function del given as a parameter,
** then frees the link’s memory using free(3).
** The memory of next must not be freed under any circumstance.
** Finally, the pointer to the link
** that was just freed must be set to NULL
** (quite similar to the function ft_memdel in the mandatory part).
*/
