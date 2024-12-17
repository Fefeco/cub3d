/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 12:09:55 by fcarranz          #+#    #+#             */
/*   Updated: 2024/12/17 15:01:49 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "colors.h"
#include "libft.h"

void	draw_map(t_game *cub3d)
{
	t_img	*images;
	int		color;
	int		x;
	int		y;
	int		x_max;
	int		y_max;
	int		x_tile;
	int		y_tile;

	y_max = ft_array_size((const char **)cub3d->map);
	images = &cub3d->images;
	color = TGRAY;
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		y_tile = y / TILE;
		if (y_tile < y_max)
			x_max = ft_strlen(cub3d->map[y_tile]);
		while (x < WIDTH)
		{
			x_tile = x / TILE;
			if (x % TILE == 0 || y % TILE == 0)
				put_pxl_on_img(images, x, y, color);
			else if (y_tile < y_max && x_tile < x_max && cub3d->map[y_tile][x_tile] == '1')
				put_pxl_on_img(images, x, y, 0x00808080);
			++x;
		}
		++y;
	}
}
/*
static void	draw_background(t_game *cub3d)
{
	t_img	*images;
	int		color;
	t_color	col;

	images = &cub3d->images;
	col = cub3d->ceiling;
	color = create_trgb(0, col.red, col.green, col.blue);
	col = cub3d->floor;
}
*/
