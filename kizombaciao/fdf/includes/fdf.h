/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchao <cchao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 10:48:43 by cchao             #+#    #+#             */
/*   Updated: 2019/08/07 11:55:47 by cchao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

/*
** Required header files.
*/

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include <time.h>

/*
** User defined header files.
*/

# include "../libft/libft.h"
# include "../minilibx/mlx.h"
# include "../includes/keys.h"

/*
** the window size (width and height),
** max value of x coordinate,
** and the title of the window (removing the .fdf extension).
*/

# define WIN_WIDTH		(1280)
# define WIN_HEIGHT		(720)
# define MAX_X			(10)
# define MAX_ZOOM		(5)
# define MAGIC_ZOOM		(2)
# define TITLE(file)	(ft_strjoin("fdf - ", file))

/*
** FDF Structures
**
** t_mlx   : required minilibx arguments, used with mlx_get_data_addr
** t_image : variables to be used for creation of the image (map).
**            data -> information about the image, allowing to be modified.
**            size -> move from one line to another in the image.
**            endian -> how the pixel color in the image needs to be stored.
**            bpp -> filled with the number of bits to represent a pixel color.
** t_map   : variables for fdf map.
** t_color : define the color, rgb value (24-bits).
** t_fdf   : nested structure
*/

typedef struct	s_mlx
{
	void	*init;
	void	*win;
	void	*img;
}				t_mlx;

typedef struct	s_image
{
	char	*data;
	int		size;
	int		endian;
	int		bpp;
}				t_image;

typedef struct	s_map
{
	int		**values;
	int		width;
	int		height;
	int		coord_y;
	int		coord_x;
	int		y0;
	int		y1;
	int		x0;
	int		x1;
	int		zoom;
	int		isometric;
	double	factor;
	double	angle_y;
	double	angle_x;
}				t_map;

typedef struct	s_color
{
	int		red;
	int		green;
	int		blue;
}				t_color;

typedef struct	s_fdf
{
	t_mlx	mlx;
	t_map	map;
	t_image	image;
	t_color	color;
}				t_fdf;

void			fdf_read(char *av, t_fdf *fdf);
int				fdf_draw(t_fdf *fdf);

#endif
