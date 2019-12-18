/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toprint.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sako <sako@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 16:34:57 by cchao             #+#    #+#             */
/*   Updated: 2019/06/11 22:29:49 by sako             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	toprint_map(t_map *map, int map_size)
{
	int i;

	i = 0;
	while (i < map_size)
	{
		ft_putstr(map->grid[i]);
		ft_putchar('\n');
		i++;
	}
}

void	tofree_map(t_map *map, int map_size)
{
	int i;

	i = 0;
	while (i < map_size)
	{
		ft_memdel((void **)&(map->grid[i]));
		i++;
	}
	ft_memdel((void **)&(map->grid));
	ft_memdel((void **)&map);
}
