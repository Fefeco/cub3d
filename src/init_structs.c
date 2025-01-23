/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 11:57:52 by fcarranz          #+#    #+#             */
/*   Updated: 2025/01/23 21:19:59 by fedeito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdbool.h>
#include "cub3d.h"

static void	init_textures(t_coords	*textures)
{
	textures->no = NULL;
	textures->so = NULL;
	textures->we = NULL;
	textures->ea = NULL;
}

static void	init_images(t_img *images)
{
	images->img_to_render = NULL;
	images->addr_to_render = NULL;
	images->img_to_draw = NULL;
	images->addr_to_draw = NULL;
}

static void	init_colors(t_color *color)
{
	color->red = -1;
	color->green = -1;
	color->blue = -1;
}

static void	init_mlx(t_mlx	*mlx)
{
	mlx->disp = NULL;
	mlx->win = NULL;
}

void	init_t_game(t_game *cub3d)
{
	init_mlx(&cub3d->mlx);
	init_textures(&cub3d->textures);
	init_images(&cub3d->images);
	init_colors(&cub3d->ceiling);
	init_colors(&cub3d->floor);
	cub3d->ready_for_map = false;
	cub3d->render = true;
	cub3d->ply.ang = -1;
	cub3d->map = NULL;
}
