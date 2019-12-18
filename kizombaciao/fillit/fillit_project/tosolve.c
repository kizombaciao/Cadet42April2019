/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tosolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchao <cchao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 16:35:04 by cchao             #+#    #+#             */
/*   Updated: 2019/06/11 16:44:17 by cchao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

size_t	count_nodes(t_node *p)
{
	size_t n;

	n = 0;
	while (p)
	{
		n++;
		p = p->next;
	}
	return (n);
}

int		roundup_sqrt(int n)
{
	int map_size;

	map_size = 2;
	while (map_size * map_size < n)
		map_size++;
	return (map_size);
}

int		overlap(t_map *map, t_node *p)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (map->grid[p->tetris.y[i] + p->y_offset][p->tetris.x[i] +\
			p->x_offset] != '.')
		{
			return (1);
		}
		i++;
	}
	return (0);
}

int		tosolve_map(t_map *map, t_node *p, int map_size)
{
	if (!p)
		return (1);
	p->x_offset = 0;
	p->y_offset = 0;
	while (within_ygrid(p, map_size))
	{
		while (within_xgrid(p, map_size))
		{
			if (!overlap(map, p))
			{
				place(p, map, p->tetris.letter);
				if (tosolve_map(map, p->next, map_size))
					return (1);
				else
				{
					place(p, map, '.');
				}
			}
			p->x_offset++;
		}
		p->x_offset = 0;
		p->y_offset++;
	}
	return (0);
}

void	tosolve(t_node *p)
{
	t_map	*map;
	int		map_size;

	map_size = roundup_sqrt(count_nodes(p) * 4);
	map = tocreate_map(map_size);
	while (!tosolve_map(map, p, map_size))
	{
		tofree_map(map, map_size);
		map_size++;
		map = tocreate_map(map_size);
	}
	toprint_map(map, map_size);
	tofree_map(map, map_size);
}
