/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 11:57:52 by fcarranz          #+#    #+#             */
/*   Updated: 2025/02/06 11:06:50 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdbool.h>
#include "cub3d.h"

void	init_image(t_img *data)
{
	data->img = NULL;
	data->addr = NULL;
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
