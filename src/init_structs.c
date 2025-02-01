/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shurtado <shurtado@student.42barcelona.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 11:57:52 by fcarranz          #+#    #+#             */
/*   Updated: 2025/02/01 13:08:53 by fedeito          ###   ########.fr       */
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

// Function to change
static void	init_texturess(t_ttex *tex)
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
// To
static void init_with_height(t_tex	*tex)
{
	tex->w = 64;
	tex->h = 64;
}

static void	init_textures(t_game *cub3d)
{
	t_tex	*tex;

	tex = &cub3d->no;
	tex->file = NULL;
	init_image(&tex->data);
	init_with_height(tex);
	tex = &cub3d->so;
	tex->file = NULL;
	init_image(&tex->data);
	init_with_height(tex);
	tex = &cub3d->ea;
	tex->file = NULL;
	init_image(&tex->data);
	init_with_height(tex);
	tex = &cub3d->we;
	tex->file = NULL;
	init_image(&tex->data);
	init_with_height(tex);
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
	// Function to change
	init_texturess(&cub3d->tex);
	// To
	init_textures(cub3d);
	// End
	init_image(&cub3d->render);
	init_image(&cub3d->draw);
	init_colors(&cub3d->ceiling);
	init_colors(&cub3d->floor);
	cub3d->ready_for_map = false;
	cub3d->key_press = true;
	cub3d->ply.ang = -1;
	cub3d->map = NULL;
	cub3d->tex.w = 64;
	cub3d->tex.h = 64;
}
