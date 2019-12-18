/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchao <cchao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 16:22:43 by cchao             #+#    #+#             */
/*   Updated: 2019/05/10 18:57:39 by cchao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t i;

	i = 0;
	while (n--)
		((unsigned char *)s)[i++] = '\0';
}

/*
** what is zero bytes???
** same as memset(s, 0, n) ?  yes!
** https://stackoverflow.com/questions/17096990/why-use-bzero-over-memset
** Overwrites the bytes of a string (*s) to zeroes bytes, depending on the
** value of the variable n. If the variable n is zero (0), then nothing
** will happen.
*/
