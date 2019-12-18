/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchao <cchao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 16:29:29 by cchao             #+#    #+#             */
/*   Updated: 2019/05/11 10:27:28 by cchao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static size_t	ft_count_words(char const *s, char c)
{
	size_t i;
	size_t w;
	size_t flag;

	flag = 0;
	w = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			flag = 0;
		else if (flag == 0)
		{
			flag = 1;
			w++;
		}
		i++;
	}
	return (w);
}

static size_t	ft_word_len(char const *s, char c)
{
	size_t l;

	l = 0;
	while (*s != c && *s++)
		l++;
	return (l);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**p;
	size_t	i;
	size_t	j;
	size_t	k;

	if (!s)
		return (NULL);
	if (!(p = (char **)malloc(sizeof(char *) * (ft_count_words(s, c) + 1))))
		return (NULL);
	i = 0;
	k = 0;
	while (i < ft_count_words(s, c))
	{
		j = 0;
		while (s[k] == c && s[k])
			k++;
		if (!(p[i] = (char *)malloc(ft_word_len(&s[k], c) + 1)))
			return (NULL);
		while (s[k] != c && s[k])
			p[i][j++] = s[k++];
		p[i++][j] = '\0';
	}
	p[i] = 0;
	return (p);
}

/*
** //l = ft_word_len(&s[k], c);
** EXAM:  USE ABOVE FOR SPLIT STRING!!!
** Allocates (with malloc(3)) and returns an array
** of “fresh” strings (all ending with ’\0’,
** including the array itself) ob- tained
** by spliting s using the character c as a delimiter.
** If the allocation fails the function returns NULL.
** Example : ft_strsplit("*hello*fellow***students*", ’*’)
** returns the array ["hello", "fellow", "students"].
** The array of “fresh” strings result of the split.
*/
