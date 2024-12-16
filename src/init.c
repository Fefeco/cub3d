/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 21:50:22 by fedeito           #+#    #+#             */
/*   Updated: 2024/12/16 12:29:16 by fedeito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <X11/keysym.h>
#include <X11/Xlib.h>
#include "cub3d.h"
#include "ft_printf.h"
#include "colors.h"
#include "keys.h"

static int	handle_key(int key, t_game *cub3d)
{
	if (key == ESC)
		clean_exit(cub3d, NULL, 0);
	else if (key == LEFT)
		ft_printf(YELL"keyPress: LEFT\n"RESET);
	else if (key == RIGHT)
		ft_printf(YELL"keyPress: RIGHT\n"RESET);
	else if (key == KEY_A)
		ft_printf(TEST3"keyPress: A\n"RESET);
	else if (key == KEY_W)
		ft_printf(TEST2"keyPress: W\n"RESET);
	else if (key == KEY_S)
		ft_printf(TEST2"keyPress: S\n"RESET);
	else if (key == KEY_D)
		ft_printf(TEST3"keyPress: D\n"RESET);
	return (0);
}

void	init_game(t_game *cub3d)
{
	t_mlx	*mlx;

	mlx = &cub3d->mlx;
	mlx->disp = mlx_init();
	if (!mlx->disp)
		return ;
	create_image(cub3d);
	ft_printf(YELL"Connection stablished!\n"RESET);
	mlx->win = mlx_new_window(mlx->disp, WIDTH, HEIGHT, "CUB3D");
	mlx_loop_hook(mlx->disp, render, cub3d);
	mlx_hook(mlx->win, ON_DESTROY, 0, clean_exit, cub3d);
	mlx_hook(mlx->win, ON_KEYDOWN, KeyPressMask, handle_key, cub3d);
	mlx_loop(mlx->disp);
}
