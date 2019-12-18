/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toalign.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchao <cchao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 16:34:26 by cchao             #+#    #+#             */
/*   Updated: 2019/06/11 16:38:20 by cchao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	toshift_x(t_node *p, int n)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		p->tetris.x[i] += n;
		i++;
	}
}

void	toshift_y(t_node *p, int n)
{
	int i;

	i = 0;
	while (i < 4)
	{
		p->tetris.y[i] += n;
		i++;
	}
}

t_node	*toalign(t_node *p)
{
	while (p->tetris.x[0] != 0 && \
		p->tetris.x[1] != 0 && \
		p->tetris.x[2] != 0 && \
		p->tetris.x[3] != 0)
		toshift_x(p, -1);
	while (p->tetris.y[0] != 0 && \
		p->tetris.y[1] != 0 && \
		p->tetris.y[2] != 0 && \
		p->tetris.y[3] != 0)
		toshift_y(p, -1);
	return (p);
}
