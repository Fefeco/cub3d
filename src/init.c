/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedeito <fcarranz@student.42barcel>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 21:50:22 by fedeito           #+#    #+#             */
/*   Updated: 2024/12/12 12:33:54 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "ft_printf.h"
#include "colors.h"

static void	mlx_clean_exit(t_mlx *mlx)
{
	if (mlx->win)
	{
		mlx_destroy_window(mlx->disp, mlx->win);
		free (mlx->win);
		mlx->win = NULL;
	}
	if (mlx->disp)
	{
		mlx_destroy_display(mlx->disp);
		free (mlx->disp);
		mlx->disp = NULL;
	}
}

void	init_game(t_game *cub3d)
{
	t_mlx	*mlx;

	mlx = &cub3d->mlx;
	mlx->disp = mlx_init();
	if (!mlx->disp)
		return ;
	ft_printf(YELL"Connection stablished!\n"RESET);
	mlx->win = mlx_new_window(mlx->disp, WIDTH, HEIGTH, "CUB3D");
	mlx_loop(mlx->disp);

	mlx_clean_exit(mlx);
}
