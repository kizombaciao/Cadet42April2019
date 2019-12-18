/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchao <cchao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 10:43:26 by cchao             #+#    #+#             */
/*   Updated: 2019/08/07 11:55:47 by cchao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*
** Help Commands.
*/

static void	fdf_help(char *av0)
{
	ft_putstr("HELP PAGE:\n\t");
	ft_putstr(ft_program_name(av0));
	ft_putstr(" FDF\n");
	ft_putstr("Commands:\n");
	ft_putstr("\t[Esc]				-> Exit Program.\n");
	ft_putstr("\t[R]				-> Reset Map.\n");
	ft_putstr("\t[C]				-> Colorize.\n");
	ft_putstr("\t[KeyPad +][KeyPad -]		-> Zoom in / Zoom out.\n");
	ft_putstr("\t[KeyPad *][KeyPad /]		-> Factor Values by 0.25\n");
	ft_putstr("\t[Space]				-> Camera (isometric <-> plain).\n");
	ft_putstr("\t[UpArrow][Left][Down][Right] 	-> Move Map.\n");
}

/*
** Only gets called when you press r on keyboard.
** Map reset to the initial values.
** origin at top left corner
** factor allows for expansion in size of values
** ceil() rounds up to integer value
*/

static void	reset_map(t_fdf *fdf)
{
	fdf->map.coord_x = 0;
	fdf->map.coord_y = 0;
	fdf->map.factor = 1.00;
	fdf->map.angle_y = cos(M_PI / 3);
	fdf->map.angle_x = fdf->map.angle_y * sin(M_PI / 6);
	fdf->map.zoom = ceil((fdf->map.width > fdf->map.height)) \
		? (WIN_WIDTH / fdf->map.width) + MAGIC_ZOOM \
		: (WIN_HEIGHT / fdf->map.height) + MAGIC_ZOOM;
	fdf->map.isometric = 1;
	fdf->color.red = 0x4F;
	fdf->color.green = 0x4F;
	fdf->color.blue = 0x4F;
}

/*
** Colorize the map with a random color.
** Toggle randomly
*/

static void	random_color(t_fdf *fdf)
{
	fdf->color.red = (rand() % 0x7F);
	fdf->color.green = (rand() % 0x7F);
	fdf->color.blue = (rand() % 0x7F);
}

/*
** ASSIGNING KEYSTROKE TO KEYCODE FOR COMMAND
** REFERENCE KEYS.H
*/

static int	fdf_keys(int keycode, t_fdf *fdf)
{
	if (keycode == KEY_ESCAPE)
		exit(0);
	else if (keycode == KEY_ANSI_R)
		reset_map(fdf);
	else if (keycode == KEY_ANSI_C)
		random_color(fdf);
	else if (keycode == KEY_UPARROW)
		fdf->map.coord_x -= 1;
	else if (keycode == KEY_DOWNARROW)
		fdf->map.coord_x += 1;
	else if (keycode == KEY_RIGHTARROW)
		fdf->map.coord_y += 1;
	else if (keycode == KEY_LEFTARROW)
		fdf->map.coord_y -= 1;
	else if (keycode == KEY_ANSI_KEYPADPLUS)
		fdf->map.zoom += 1;
	else if ((keycode == KEY_ANSI_KEYPADMINUS) && (fdf->map.zoom > MAX_ZOOM))
		fdf->map.zoom -= 1;
	else if ((keycode == KEY_ANSI_KEYPADMULTIPLY) && (fdf->map.factor < MAX_X))
		fdf->map.factor += 0.25;
	else if ((keycode == KEY_ANSI_KEYPADDIVIDE) && (fdf->map.factor > -MAX_X))
		fdf->map.factor -= 0.25;
	else if (keycode == KEY_SPACE)
		fdf->map.angle_x *= (fdf->map.isometric++ % 2) ? 0.2 : 5;
	return (0);
}

/*
** malloc for fdf struct
** call fdf_read to read the fdf file
** initialize the image variables
** mlx_init to establish connection
** create new window
** set up event loop call for keyboard inputs
*/

int			main(int ac, char *av[])
{
	t_fdf	*fdf;

	if (ac == 2)
	{
		if (!(fdf = (t_fdf *)malloc(sizeof(t_fdf))))
			ft_puterror("ERROR: Memory Allocation failed", 3);
		fdf_read(av[1], fdf);
		reset_map(fdf);
		fdf->mlx.init = mlx_init();
		fdf->mlx.win = mlx_new_window(fdf->mlx.init, WIN_WIDTH, WIN_HEIGHT, \
			TITLE(ft_remove_extension(av[1])));
		mlx_hook(fdf->mlx.win, 2, 3, fdf_keys, fdf);
		mlx_loop_hook(fdf->mlx.init, fdf_draw, fdf);
		mlx_loop(fdf->mlx.init);
	}
	else
		fdf_help(av[0]);
	return (0);
}

/*
** mlx_init, INITIALIZE CONNECTION
**
** void *mlx_new_window ( void *mlx_ptr, int size_x, int size_y, char *title );
** CREATES A NEW WINDOW ON THE SCREEN, USING SIZE_X AND SIZE_Y
** AND TITLE FOR DISPLAY
**
** int mlx_loop_hook ( void *mlx_ptr, int (*funct_ptr)(), void *param );
** Code that handles intercepting events
** such as keyboard presses is called a hook.
** You hook onto the message and can do something with it.
**
** mlx_loop ( void *mlx_ptr );
** INFINITE LOOP THAT WAITS FOR EVENT,
** AND THEN CALLS A USER-DEFINED FUNCTION ASSOCIATED WITH THE EVENT.
** SENDS ORDERS TO DISPLAY PIXELS, IMAGES ON SCREEN
** AND GETS INFO FROM THE KEYBOARD AND MOUSE
**
** https://qst0.github.io/ft_libgfx/
** https://github.com/qst0/ft_libgfx
** https://dev.to/freerangepixels/
** a-probably-terrible-way-to-render-gradients-1p3n
** int mlx_pixel_put ( void *mlx_ptr, void *win_ptr, int x, int y, int color );
** https://qst0.github.io/ft_libgfx/man_mlx_pixel_put.html
**
** M_PI, from math.h
**
** const char *ptr vs char const *ptr:
** char *const ptr : This is a constant pointer to non-constant character.
** You cannot change the pointer p, but can change the value pointed by ptr.
** const char *ptr : This is a pointer to a constant character.
** You cannot change the value pointed by ptr,
** but you can change the pointer itself.
** const char * const ptr : This is a constant pointer to constant character.
** You can neither change the value pointed by ptr nor the pointer ptr.
** https://www.geeksforgeeks.org/
** difference-const-char-p-char-const-p-const-char-const-p/
**
** endian:
** denoting or relating to a system of ordering data in a computer's memory
** whereby the most significant ( big-endian )
** or least significant ( little-endian ) byte is put first.
** https://www.geeksforgeeks.org/little-and-big-endian-mystery/
**
** bpp:
** bits per pixel
** the number of bits needed to hold one element of an image.
** WikiPage:
** https://github.com/VBrazhnik/FdF/wiki
** INSTRUCTIONS:
** https://github.com/wickedpool/Fdf-42
**
** https://www.gnu.org/software/make/manual/html_node/Automatic-Variables.html
*/
