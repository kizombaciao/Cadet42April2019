/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tomap.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sako <sako@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 16:34:54 by cchao             #+#    #+#             */
/*   Updated: 2019/06/11 22:16:42 by sako             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_map	*tocreate_map(int map_size)
{
	int		i;
	t_map	*map;

	map = (t_map *)ft_memalloc(sizeof(t_map));
	map->grid = (char **)ft_memalloc(sizeof(char *) * map_size);
	i = 0;
	while (i < map_size)
	{
		map->grid[i] = ft_strnew(map_size);
		ft_memset(map->grid[i], EMPTY, map_size);
		i++;
	}
	return (map);
}

int		within_xgrid(t_node *p, int map_size)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (p->tetris.x[i] + p->x_offset >= map_size)
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int		within_ygrid(t_node *p, int map_size)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (p->tetris.y[i] + p->y_offset >= map_size)
		{
			return (0);
		}
		i++;
	}
	return (1);
}

void	place(t_node *p, t_map *map, char letter)
{
	int i;
	int x;
	int y;

	i = 0;
	while (i < 4)
	{
		x = p->tetris.x[i] + p->x_offset;
		y = p->tetris.y[i] + p->y_offset;
		map->grid[y][x] = letter;
		i++;
	}
}
