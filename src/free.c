/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 13:21:52 by fcarranz          #+#    #+#             */
/*   Updated: 2024/12/16 14:20:28 by fcarranz         ###   ########.fr       */
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

void	free_images(t_img *images, void *disp)
{
	if (images->img_to_render)
	{
		mlx_destroy_image(disp, images->img_to_render);
		images->img_to_render = NULL;
		images->addr_to_render = NULL;
	}
	if (images->img_to_draw)
	{
		mlx_destroy_image(disp, images->img_to_draw);
		images->img_to_draw = NULL;
		images->addr_to_draw = NULL;
	}
}

void	free_coords(t_coords *textures)
{
	if (textures->NO)
		free(textures->NO);
	if (textures->SO)
		free(textures->SO);
	if (textures->WE)
		free(textures->WE);
	if (textures->EA)
		free(textures->EA);
}

void	free_mlx(t_mlx *mlx)
{
	if(mlx->win)
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
