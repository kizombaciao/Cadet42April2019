/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchao <cchao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 14:53:25 by sako              #+#    #+#             */
/*   Updated: 2019/06/13 16:08:30 by cchao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <errno.h>
# include <stdio.h>

# define BLOCK '#'
# define EMPTY '.'
# define NL '\n'

# define INVALID_FILE -1

# define CHECK1(c) (c == BLOCK)
# define CHECK2(c) (c == EMPTY)
# define CHECK3(c) (c == NL)
# define CHECK4(c) (c == BLOCK || c == EMPTY || c == NL)

typedef struct		s_tetris
{
	char			letter;
	int				x[4];
	int				y[4];
}					t_tetris;

typedef struct		s_node
{
	t_tetris		tetris;
	int				x_offset;
	int				y_offset;
	struct s_node	*next;
}					t_node;

typedef struct		s_map
{
	char			**grid;
}					t_map;

t_node				*toread(char *file);
t_node				*toconstruct_nodes(char *buf, int size);
t_node				*toconstruct_tetris(char *buf, char letter);
void				tosolve(t_node *p);
void				tofree_nodes(t_node *p);
void				toprint_map(t_map *map, int map_size);
void				tofree_map(t_map *map, int map_size);
int					tovalidate(char *buf, int size);
t_node				*toalign(t_node *p);
t_map				*tocreate_map(int map_size);
int					within_xgrid(t_node *p, int map_size);
int					within_ygrid(t_node *p, int map_size);
void				place(t_node *p, t_map *map, char letter);

#endif
