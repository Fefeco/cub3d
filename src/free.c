/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 13:21:52 by fcarranz          #+#    #+#             */
/*   Updated: 2025/02/02 12:29:02 by fedeito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_map(char **map)
{
	char	**tmp;

	if (map)
	{
		tmp = map;
		while (*tmp)
			free(*tmp++);
		free(map);
	}
}

void	free_image(t_img *data, void *disp)
{
	if (data->img)
	{
		mlx_destroy_image(disp, data->img);
		data->img = NULL;
		data->addr = NULL;
	}
}

void	free_texture(t_tex *tex, void *disp)
{
	if (tex->file)
	{
		free(tex->file);
		tex->file = NULL;
	}
	free_image(&tex->data, disp);
}

void	free_mlx(t_mlx *mlx)
{
	if (mlx->win)
	{
		mlx_destroy_window(mlx->disp, mlx->win);
		mlx->win = NULL;
	}
	if (mlx->disp)
	{
		mlx_destroy_display(mlx->disp);
		free (mlx->disp);
		mlx->disp = NULL;
	}
}
