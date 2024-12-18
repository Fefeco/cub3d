/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 12:09:55 by fcarranz          #+#    #+#             */
/*   Updated: 2024/12/18 12:26:44 by fedeito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "colors.h"
#include "libft.h"

static void	draw_grid(t_img	*images)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			if (x % TILE == 0 || y % TILE == 0)
				put_pxl_on_img(images, x, y, GRID_COLOR);
			++x;
		}
		++y;
	}
}

void	draw_map(t_game *cub3d)
{
	t_img	*images;
	int		x;
	int		y;

	images = &cub3d->images;
	y = 0;
	while (y < HEIGHT && cub3d->map[y / TILE])
	{
		x = 0;
		while (x < WIDTH && cub3d->map[y / TILE][x / TILE])
		{
			if (cub3d->map[y / TILE][x / TILE] == '1')
				put_pxl_on_img(images, x, y, MAP_WALL_COLOR);
			++x;
		}
		++y;
	}
	draw_grid(images);
}
