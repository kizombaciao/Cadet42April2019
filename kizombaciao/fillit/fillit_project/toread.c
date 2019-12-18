/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchao <cchao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 16:35:01 by cchao             #+#    #+#             */
/*   Updated: 2019/06/13 15:53:29 by cchao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	tofree_nodes(t_node *p)
{
	t_node *tmp;

	while (p)
	{
		tmp = p;
		p = p->next;
		free(tmp);
	}
}

t_node	*toconstruct_tetris(char *buf, char letter)
{
	int		i;
	int		x;
	int		y;
	t_node	*p;

	i = 0;
	x = 0;
	y = 0;
	if (!(p = (t_node *)malloc(sizeof(t_node))))
		return (NULL);
	while (i < 20)
	{
		if (buf[i] == BLOCK)
		{
			p->tetris.x[x++] = (i >= 5) ? (i % 5) : i;
			p->tetris.y[y++] = i / 5;
		}
		i++;
	}
	p->x_offset = 0;
	p->y_offset = 0;
	p->tetris.letter = letter;
	p = toalign(p);
	return (p);
}

t_node	*toconstruct_nodes(char *buf, int size)
{
	int		i;
	char	letter;
	t_node	*begin;
	t_node	*current;

	i = 0;
	letter = 'A';
	while (i < size)
	{
		if (letter == 'A')
		{
			begin = toconstruct_tetris(buf + i, letter);
			current = begin;
		}
		else
		{
			current->next = toconstruct_tetris(buf + i, letter);
			current = current->next;
		}
		letter++;
		i += 21;
	}
	current->next = NULL;
	return (begin);
}

t_node	*toread(char *file)
{
	int		fd;
	char	buf[545];
	int		bytecount;
	t_node	*p;

	if (!(fd = open(file, O_RDONLY)))
		return (NULL);
	bytecount = read(fd, buf, 546);
	buf[bytecount] = '\0';
	close(fd);
	if (bytecount < 19 || bytecount > 545)
		return (NULL);
	if (tovalidate(buf, bytecount))
		return (NULL);
	p = toconstruct_nodes(buf, bytecount);
	return (p);
}
