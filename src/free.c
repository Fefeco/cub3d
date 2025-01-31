/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 13:21:52 by fcarranz          #+#    #+#             */
/*   Updated: 2025/01/31 11:17:15 by fcarranz         ###   ########.fr       */
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

void	free_textures(t_tex *tex)
{
	if (tex->file_no)
		free(tex->file_no);
	if (tex->file_so)
		free(tex->file_so);
	if (tex->file_we)
		free(tex->file_we);
	if (tex->file_ea)
		free(tex->file_ea);
	if (tex->img_no)
		free(tex->img_no);
	if (tex->img_so)
		free(tex->img_so);
	if (tex->img_we)
		free(tex->img_we);
	if (tex->img_ea)
		free(tex->img_ea);
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
