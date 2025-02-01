/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shurtado <shurtado@student.42barcelona.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 11:57:52 by fcarranz          #+#    #+#             */
/*   Updated: 2025/02/01 10:56:53 by fedeito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdbool.h>
#include "cub3d.h"

static void	init_textures(t_tex *tex)
{
	tex->file_no = NULL;
	tex->file_so = NULL;
	tex->file_we = NULL;
	tex->file_ea = NULL;
	tex->img_no = NULL;
	tex->img_so = NULL;
	tex->img_we = NULL;
	tex->img_ea = NULL;
}
// Function to change
static void	init_images(t_img *images)
{
	images->img_to_render = NULL;
	images->addr_to_render = NULL;
	images->img_to_draw = NULL;
	images->addr_to_draw = NULL;
}
// To
static void	init_image(t_iimg *data)
{
	data->img= NULL;
	data->addr= NULL;
}
// End

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
	init_textures(&cub3d->tex);
	// Change
	init_images(&cub3d->images);
	// To
	init_image(&cub3d->render);
	init_image(&cub3d->draw);
	// End
	init_colors(&cub3d->ceiling);
	init_colors(&cub3d->floor);
	cub3d->ready_for_map = false;
	cub3d->key_press = true;
	cub3d->ply.ang = -1;
	cub3d->map = NULL;
	cub3d->tex.w = 64;
	cub3d->tex.h = 64;
}
