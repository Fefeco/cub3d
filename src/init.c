/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 21:50:22 by fcarranz          #+#    #+#             */
/*   Updated: 2025/01/22 22:25:10 by fedeito          ###   ########.fr       */
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
	else if (key == LEFT || key == RIGHT)
		rotate(key, &cub3d->ply);
	else if (key == KEY_A || key == KEY_D || key == KEY_W || key == KEY_S)
		try_move(key, cub3d);
	return (0);
}

static int	end_loop(t_game *cub3d)
{
	clean_exit(cub3d, NULL, 0);
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
	mlx->win = mlx_new_window(mlx->disp, WIDTH, HEIGHT, "CUB3D");
	mlx_loop_hook(mlx->disp, render, cub3d);
	mlx_hook(mlx->win, ON_DESTROY, 0, end_loop, cub3d);
	mlx_hook(mlx->win, ON_KEYDOWN, KeyPressMask, handle_key, cub3d);
	mlx_loop(mlx->disp);
}
