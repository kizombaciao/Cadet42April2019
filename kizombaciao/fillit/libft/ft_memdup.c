/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchao <cchao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 16:27:46 by cchao             #+#    #+#             */
/*   Updated: 2019/05/10 19:25:51 by cchao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memdup(const void *src, size_t len)
{
	char *p;

	if (!(p = (char *)malloc(sizeof(char) * len)))
		return (NULL);
	return (ft_memcpy(p, src, len));
}

/*
** why assume it is a string???
** is memcpy the best???
*/
