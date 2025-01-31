/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 13:21:52 by fcarranz          #+#    #+#             */
/*   Updated: 2025/01/31 21:16:07 by fedeito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	*free_map(char **map)
{
	char	**tmp;

	if (map)
	{
		tmp = map;
		while (*tmp)
			free(*tmp++);
		free(map);
	}
	return (NULL);
}

void	free_image(t_img *data, void *disp)
{
	if (data->img)
	{
		mlx_destroy_image(disp, data->img);
		data->img= NULL;
		data->addr= NULL;
	}
}

void	free_textures(t_game *cub3d)
{
	if (cub3d->no.file)
		free(cub3d->no.file);
	if (cub3d->so.file)
		free(cub3d->so.file);
	if (cub3d->we.file)
		free(cub3d->we.file);
	if (cub3d->ea.file)
		free(cub3d->ea.file);
	if (cub3d->no.data.img)
		free(cub3d->no.data.img);
	if (cub3d->so.data.img)
		free(cub3d->so.data.img);
	if (cub3d->we.data.img)
		free(cub3d->we.data.img);
	if (cub3d->ea.data.img)
		free(cub3d->ea.data.img);
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
