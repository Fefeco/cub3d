/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shurtado <shurtado@student.42barcelona.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 11:57:52 by fcarranz          #+#    #+#             */
/*   Updated: 2025/01/31 21:20:20 by fedeito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdbool.h>
#include "cub3d.h"

static void	init_image(t_img *data)
{
	data->img = NULL;
	data->addr = NULL;
}

static void	init_textures(t_game *cub3d)
{
	cub3d->no.file = NULL;
	init_image(&cub3d->no.data);
	cub3d->no.w = 64;
	cub3d->no.h = 64;
	cub3d->so.file = NULL;
	init_image(&cub3d->so.data);
	cub3d->so.w = 64;
	cub3d->so.h = 64;
	cub3d->ea.file = NULL;
	init_image(&cub3d->ea.data);
	cub3d->ea.w = 64;
	cub3d->ea.h = 64;
	cub3d->we.file = NULL;
	init_image(&cub3d->we.data);
	cub3d->we.w = 64;
	cub3d->we.h = 64;
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
	init_textures(cub3d);
	init_image(&cub3d->render);
	init_image(&cub3d->draw);
	init_colors(&cub3d->ceiling);
	init_colors(&cub3d->floor);
	cub3d->ready_for_map = false;
	cub3d->key_press = true;
	cub3d->ply.ang = -1;
	cub3d->map = NULL;
}
