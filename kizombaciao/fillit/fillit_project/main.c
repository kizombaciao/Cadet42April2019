/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchao <cchao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 16:36:16 by cchao             #+#    #+#             */
/*   Updated: 2019/06/13 21:29:52 by sako             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int ac, char **av)
{
	t_node	*p;

	if (ac != 2)
	{
		ft_putstr("USAGE: ./fillit input_file\n");
		return (1);
	}
	p = toread(av[1]);
	if (p == NULL)
	{
		ft_putstr("error\n");
		return (1);
	}
	tosolve(p);
	tofree_nodes(p);
	return (0);
}
