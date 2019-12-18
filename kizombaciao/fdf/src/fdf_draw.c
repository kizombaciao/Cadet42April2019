/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchao <cchao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 10:45:54 by cchao             #+#    #+#             */
/*   Updated: 2019/08/07 11:57:17 by cchao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*
** we are submitting one long string to mlx.
** in order to index the string, we artificially created i variable.
** we are submitting 4 colors, red, green, blue, and other
** we multiply y by 4 to index across 4 element at a time
** we mutliply x by 4 and WIN_WIDTH, since that is the length of a row
** http://rit-mcsl.org/fairchild//WhyIsColor/Questions/4-5.html
*/

static void	draw_pixel(t_fdf *fdf, int y, int x, double hypotenuse)
{
	int		i;

	if ((y > 0 && x > 0) && (y < WIN_WIDTH && x < WIN_HEIGHT))
	{
		i = (y * 4) + (x * WIN_WIDTH * 4);
		fdf->image.data[i] = fdf->color.red + hypotenuse;
		fdf->image.data[i + 1] = fdf->color.green + hypotenuse;
		fdf->image.data[i + 2] = fdf->color.blue + hypotenuse;
		fdf->image.data[i + 3] = 0x7F + hypotenuse;
	}
}

/*
** compute hypotenuse
** use increments of hypotenuse to travel along x and y to draw the line
*/

static void	draw_lines(t_fdf *fdf)
{
	double y;
	double x;
	double delta_y;
	double delta_x;
	double hypotenuse;

	y = fdf->map.y0;
	x = fdf->map.x0;
	delta_y = fdf->map.y1 - fdf->map.y0;
	delta_x = fdf->map.x1 - fdf->map.x0;
	hypotenuse = sqrt((pow(delta_y, 2)) + (pow(delta_x, 2)));
	delta_y /= hypotenuse;
	delta_x /= hypotenuse;
	while (hypotenuse > 0)
	{
		draw_pixel(fdf, y, x, hypotenuse);
		y += delta_y;
		x += delta_x;
		hypotenuse--;
	}
}

/*
** Draw horizontal, taking account of angle, zoom,
** position relative to size of window, move, and isometric.
** this function gets called repeatedly, as part of a while loop.
*/

static void	draw_horizontal(t_fdf *fdf, int y, int x)
{
	int		yt;
	int		xt;

	yt = y - fdf->map.width / 2;
	xt = x - fdf->map.height / 2;
	fdf->map.y0 = fdf->map.angle_y * (yt - xt) * fdf->map.zoom;
	fdf->map.y0 += (WIN_WIDTH / 2) + fdf->map.coord_y;
	fdf->map.x0 = fdf->map.angle_x * (yt + xt) * fdf->map.zoom;
	fdf->map.x0 -= fdf->map.values[x][y] * fdf->map.factor;
	fdf->map.x0 += (WIN_HEIGHT / 2) + fdf->map.coord_x;
	fdf->map.y1 = fdf->map.angle_y * ((yt + 1) - xt) * fdf->map.zoom;
	fdf->map.y1 += (WIN_WIDTH / 2) + fdf->map.coord_y;
	fdf->map.x1 = fdf->map.angle_x * ((yt + 1) + xt) * fdf->map.zoom;
	fdf->map.x1 -= fdf->map.values[x][y + 1] * fdf->map.factor;
	fdf->map.x1 += (WIN_HEIGHT / 2) + fdf->map.coord_x;
	draw_lines(fdf);
}

/*
** Draw vertical, taking account of angle, zoom,
** position relative to size of window, move, and isometric.
*/

static void	draw_vertical(t_fdf *fdf, int y, int x)
{
	int		yt;
	int		xt;

	yt = y - fdf->map.width / 2;
	xt = x - fdf->map.height / 2;
	fdf->map.y0 = fdf->map.angle_y * (yt - xt) * fdf->map.zoom;
	fdf->map.y0 += (WIN_WIDTH / 2) + fdf->map.coord_y;
	fdf->map.x0 = fdf->map.angle_x * (yt + xt) * fdf->map.zoom;
	fdf->map.x0 -= fdf->map.values[x][y] * fdf->map.factor;
	fdf->map.x0 += (WIN_HEIGHT / 2) + fdf->map.coord_x;
	fdf->map.y1 = fdf->map.angle_y * (yt - (xt + 1)) * fdf->map.zoom;
	fdf->map.y1 += (WIN_WIDTH / 2) + fdf->map.coord_y;
	fdf->map.x1 = fdf->map.angle_x * (yt + (xt + 1)) * fdf->map.zoom;
	fdf->map.x1 -= fdf->map.values[x + 1][y] * fdf->map.factor;
	fdf->map.x1 += (WIN_HEIGHT / 2) + fdf->map.coord_x;
	draw_lines(fdf);
}

/*
** create new image for memory, using connection, width and height
** get necessary specs
** cycle to draw horizontal and vertical
** fdf->mlx.img is a void pointer
** fdf->image.data is the long string that holds pixel data.
** x and y travels the entire length of the height and width respectively
*/

int			fdf_draw(t_fdf *fdf)
{
	int		y;
	int		x;

	x = 0;
	fdf->mlx.img = mlx_new_image(fdf->mlx.init, WIN_WIDTH, WIN_HEIGHT);
	fdf->image.data = mlx_get_data_addr(fdf->mlx.img, &fdf->image.bpp, \
		&fdf->image.size, &fdf->image.endian);
	while (x < fdf->map.height)
	{
		y = 0;
		while (y < fdf->map.width)
		{
			fdf->map.y0 = y;
			fdf->map.x0 = x;
			if (y + 1 < fdf->map.width)
				draw_horizontal(fdf, y, x);
			if (x + 1 < fdf->map.height)
				draw_vertical(fdf, y, x);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(fdf->mlx.init, fdf->mlx.win, fdf->mlx.img, 0, 0);
	mlx_destroy_image(fdf->mlx.init, fdf->mlx.img);
	return (0);
}

/*
** https://qst0.github.io/ft_libgfx/man_mlx_new_image.html
** void *mlx_new_image ( void *mlx_ptr, int width, int height );
** mlx_new_image() creates a new image in memory.
**
** char *mlx_get_data_addr
** ( void *img_ptr, int *bits_per_pixel, int *size_line, int *endian );
** returns information about the created image,
** allowing a user to modify it later.
** The img_ptr parameter specifies the image to use.
** bits_per_pixel will be filled with the number of bits needed
** to represent a pixel color (also called the depth of the image).
** size_line is the number of bytes
** used to store one line of the image in memory.
** This information is needed to move from one line to another in the image.
** endian tells you wether the pixel color in the image needs to be stored in:
** little (endian == 0), or big (endian == 1).
** mlx_get_data_addr returns a char * address
** that represents the begining of the memory area where the image is stored.
**
** int mlx_put_image_to_window
** ( void *mlx_ptr, void *win_ptr, void *img_ptr, int x, int y );
** to dump a drawed image inside a specified window to display on screen.
** mlx_ptr connection identifier to the display.
** win_ptr, the window to use
** img_ptr, the image
** x, y: where the image should be placed in the window.
**
** int mlx_destroy_image ( void *mlx_ptr, void *img_ptr );
** destroys the given image, img_ptr.
*/
