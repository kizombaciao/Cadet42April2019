/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchao <cchao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 16:27:52 by cchao             #+#    #+#             */
/*   Updated: 2019/05/10 19:45:01 by cchao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t n)
{
	unsigned char *d;

	d = (unsigned char *)b;
	while (d < (unsigned char *)b + n)
		*(d++) = (unsigned char)c;
	return (b);
}

/*
** note, b+n is simply using pointer math, with contiguous addresses
** difference in address is the same as counter
**
** why replace while (n--) with below ???
** while (n--)
**
** https://www.geeksforgeeks.org/memset-c-example/
**
** memset function writes len bytes of value c
** (converted to an unsigned char) to the string b.
** This function returns it's first argument.
*/
