/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 13:21:52 by fcarranz          #+#    #+#             */
/*   Updated: 2025/02/01 13:06:43 by fedeito          ###   ########.fr       */
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
		data->img = NULL;
		data->addr = NULL;
	}
}

// Function to change
void	free_textures(t_ttex *tex)
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
// To

void	free_texture(t_tex *tex, void *disp)
{
	if (tex->file)
	{
		free(tex->file);
		tex->file = NULL;
	}
	free_image(&tex->data, disp);
}
// End

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
