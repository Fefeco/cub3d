/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedeito <fcarranz@student.42barcel>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 21:50:22 by fedeito           #+#    #+#             */
/*   Updated: 2024/12/12 14:31:32 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "ft_printf.h"
#include "colors.h"
#include <X11/keysym.h>

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
		mlx->disp_on = 0;
	}
}

int	handle_input(int keysym, t_mlx *mlx)
{
    if (keysym == XK_Escape)
        mlx_destroy_window(mlx->disp, mlx->win);
    return (0);
}

int	close_win(void *ptr)
{
	t_mlx	mlx;
	
	mlx = *((t_mlx *)ptr);
	mlx_clean_exit(&mlx);
	ft_printf(TEST2"Llego?"RESET);
	return (0);
}

void	init_game(t_game *cub3d)
{
	t_mlx	*mlx;

	mlx = &cub3d->mlx;
	mlx->disp = mlx_init();
	if (!mlx->disp)
		return ;
	else
		mlx->disp_on = 1;
	ft_printf(YELL"Connection stablished!\n"RESET);
	mlx->win = mlx_new_window(mlx->disp, WIDTH, HEIGTH, "CUB3D");
	mlx_hook(mlx->win, ON_DESTROY, 0, close_win, mlx);
	mlx_key_hook(mlx->win, handle_input, mlx);
	mlx_loop(&mlx->disp_on);
	ft_printf(GREEN"Llego?"RESET);
	mlx_clean_exit(mlx);
}
