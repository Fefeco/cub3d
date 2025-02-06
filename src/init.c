/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 21:50:22 by fcarranz          #+#    #+#             */
/*   Updated: 2025/02/06 19:26:37 by fedeito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <X11/keysym.h>
#include <X11/Xlib.h>
#include "cub3d.h"
#include "ft_printf.h"
#include "colors.h"
#include "keys.h"

static int	end_loop(t_game *cub3d)
{
	clean_exit(cub3d, NULL, 0);
	return (0);
}

void	init_game(t_game *cub3d)
{
	t_mlx	*mlx;

	mlx = &cub3d->mlx;
	create_image(cub3d);
	mlx->win = mlx_new_window(mlx->disp, WIDTH, HEIGHT, "CUB3D");
	mlx_loop_hook(mlx->disp, render, cub3d);
	mlx_hook(mlx->win, ON_DESTROY, 0, end_loop, cub3d);
	mlx_hook(mlx->win, ON_KEYDOWN, KeyPressMask, handle_key_press, cub3d);
	mlx_hook(mlx->win, KeyRelease, KeyReleaseMask, handle_key_release, cub3d);
	mlx_loop(mlx->disp);
}
