/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 11:57:52 by fcarranz          #+#    #+#             */
/*   Updated: 2024/12/12 14:19:36 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdbool.h>
#include "cub3d.h"

static void	init_textures(t_coords	*textures)
{
	textures->NO = NULL;
	textures->SO = NULL;
	textures->WE = NULL;
	textures->EA = NULL;
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
	mlx->disp_on = 0;
}

void	init_t_game_ptrs(t_game *cub3d)
{
	init_mlx(&cub3d->mlx);
	init_textures(&cub3d->textures);
	init_colors(&cub3d->ceiling);
	init_colors(&cub3d->floor);
	cub3d->ready_for_map = false;
	cub3d->player_orient = 0;
	cub3d->map = NULL;
}
