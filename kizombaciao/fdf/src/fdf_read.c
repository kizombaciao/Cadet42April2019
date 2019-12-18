/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchao <cchao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 10:43:39 by cchao             #+#    #+#             */
/*   Updated: 2019/08/07 13:20:51 by cchao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*
** cycle through each line
** check if file inputs are digits
** skip over contiguous digits, by incrementing line
** if not digit, check if ' ' or '-'
** return the number of columns
*/

static int	count_cols(char *s)
{
	int		len;

	len = 0;
	while (*s)
	{
		if (ft_isdigit(*s))
		{
			len += 1;
			while (ft_isdigit(*s))
				s += 1;
		}
		else if (*s != ' ' && *s != '-')
			ft_puterror("ERROR: Invalid characters or read error", 5);
		s += 1;
	}
	return (len);
}

/*
** open file
** get a line
** check if line is empty or not
** find the number of columns in the line
** ensure that the number of columns has not decreased
** as we progressed through each row
** free memory
** close file
** set map.width equal to cols
** return number of rows
*/

static int	count_rows(t_fdf *fdf, char *av)
{
	int		fd;
	int		len;
	int		rows;
	int		cols;
	char	*line;

	if ((fd = open(av, O_RDONLY)) < 0)
		ft_puterror("ERROR: Opening File", 1);
	rows = 0;
	cols = 0;
	while (get_next_line(fd, &line))
	{
		if (!*line)
			break ;
		if ((len = count_cols(line)) > cols)
			cols = len;
		(cols == len) ? rows++ : ft_puterror("ERROR: Invalid File", 4);
		free(line);
	}
	if (close(fd) < 0)
		ft_puterror("ERROR: Closing File", 2);
	if (!(fdf->map.width = cols))
		ft_puterror("ERROR: Invalid File", 4);
	return (rows);
}

/*
** split each line to populate each given row of the 2d map.values array
** continue as long as y does not equal the map.width
** destroy memory no longer needded
*/

static void	get_strsplit_values(t_fdf *fdf, int y, int x, char *line)
{
	int		i;
	char	**split;

	if ((split = ft_strsplit(line, ' ')))
	{
		i = 0;
		while (split[i] && (y != fdf->map.width))
		{
			fdf->map.values[x][y] = ft_atoi(split[i++]);
			y++;
		}
		free(split);
	}
}

/*
** count the number of rows
** malloc memory for 2d map.values array
** cycle through each line to malloc memory for each row by cols needed
** and split each line and populate the 2d array
*/

void		fdf_read(char *av, t_fdf *fdf)
{
	int		y;
	int		x;
	int		fd;
	char	*line;

	y = 0;
	x = 0;
	fdf->map.height = count_rows(fdf, av);
	if ((fd = open(av, O_RDONLY)) < 0)
		ft_puterror("ERROR: Opening File", 1);
	if (!(fdf->map.values = (int **)malloc(sizeof(int *) * fdf->map.height)))
		ft_puterror("ERROR: Memory Allocation failed", 3);
	while (get_next_line(fd, &line) && x != fdf->map.height)
	{
		if (!(fdf->map.values[x] = (int *)malloc(sizeof(int) * fdf->map.width)))
			ft_puterror("ERROR: Memory Allocation failed", 3);
		get_strsplit_values(fdf, y, x, line);
		y = 0;
		x++;
		free(line);
	}
	if (close(fd) < 0)
		ft_puterror("ERROR: Closing File", 2);
}
