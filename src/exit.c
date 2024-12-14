/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 13:00:35 by fcarranz          #+#    #+#             */
/*   Updated: 2024/12/14 21:26:40 by fcarranz         ###   ########.fr       */
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

void	free_images(t_game *cub3d)
{
	t_img	*images;

	images = &cub3d->images;
	if (images->img_to_render)
	{
		mlx_destroy_image(cub3d->mlx.disp, images->img_to_render);
		images->img_to_render = NULL;
		free(images->addr_to_render);
		images->addr_to_render = NULL;
	}
	if (images->img_to_draw)
	{
		mlx_destroy_image(cub3d->mlx.disp, images->img_to_draw);
		images->img_to_draw = NULL;
		free(images->addr_to_draw);
		images->addr_to_draw = NULL;
	}
}
void	free_coords(t_coords	*textures)
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

void	free_t_game_ptrs(t_game *cub3d)
{
	free_coords(&cub3d->textures);
	cub3d->map = free_map(cub3d->map);
	free_images(cub3d);
}

int	exit_err(const char *error, int ret)
{
	print_err(error, ret);
	exit (ret);
}
