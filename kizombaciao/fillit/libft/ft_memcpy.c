/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchao <cchao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 16:27:41 by cchao             #+#    #+#             */
/*   Updated: 2019/05/10 20:07:46 by cchao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char *d;
	char *s;

	d = (char *)dst;
	s = (char *)src;
	while (n--)
		*(d)++ = *(s)++;
	return (dst);
}

/*
** doesn't handle overlap like memmove.c
** should i use char instead of unsigned char???
**
** please check below!!!
** above is wrong!  different result from memcpy.c
** add edge cases!!!
** does such type casting permit arguments to still be integers???
** given that we are using unsigned char.
** In C, can one use int type for char variable? Why is that okay?
**
**  return (ft_memmove(dst, src, n));
**
**  unsigned char *t;
**
**  t = (unsigned char *)dst;
**  while (n--)
**  {
**      *t++ = *((unsigned char *)src++);
**  }
**  return (dst);
**
** Copies n bytes from memory area src to memory area dst.
** If dst and src overlap, behavior is undefined.
**
** The strcpy ( ) function is designed to work exclusively with
** strings. It copies each byte of the source string to the
** destination string and stops when the terminating null
** character (\0) has been moved. On the other hand, the
** memcpy ()  function is designed to work with any type of data.
**
** Because not all data ends with a null character, you must
** provide the memcpy ( ) function with the number of bytes
** you want to copy from the source to the destination.
**
** strcpy() functio copies bytes from source to destination
** till null character is encountered whereas memcpy() can
** expect a non-string object so null character may not come.
** That's why it is must to specify the number of bytes to be
** copied from source to destination
*/
