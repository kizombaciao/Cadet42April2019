/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchao <cchao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 16:27:24 by cchao             #+#    #+#             */
/*   Updated: 2019/05/12 13:20:03 by cchao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *p;

	if (!(p = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (!content || !content_size)
	{
		p->content = NULL;
		p->content_size = 0;
		p->next = NULL;
	}
	else
	{
		p->content = ft_memalloc(content_size);
		p->content = ft_memcpy(p->content, content, content_size);
		p->content_size = content_size;
		p->next = NULL;
	}
	return (p);
}

/*
** if no content, then malloc with NULL
** if there is content, then malloc with content added
**
** Allocates (with malloc(3))
** and returns a “fresh” link.
** The variables content
** and content_size of the new link are initialized
** by copy of the parameters of the function.
** If the parameter content is null,
** the variable content is initialized to NULL
** and the variable content_size is initialized to 0
** even if the parameter content_size isn’t.
** The variable next is initialized to NULL.
** If the allocation fails, the function returns NULL.
**
** Return value: The new link.
*/
