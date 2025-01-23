/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_minimap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedeito <fcarranz@student.42barcel>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 20:53:09 by fedeito           #+#    #+#             */
/*   Updated: 2025/01/23 22:57:17 by fedeito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	render_border(t_img *images)
{
	int		mini_w;
	int		mini_h;
	int		color;
	t_ivec	axis;
	t_ivec	push;

	mini_w = (WIDTH / 100) * 10;
	mini_h = (HEIGHT / 100) * 10;
	push.x =  (WIDTH / 100) * 88;
	push.y =  (HEIGHT / 100) * 88;
	axis.y = 0;
	color = create_trgb(0, 0, 0, 0);
	while (axis.y < mini_h)
	{
		axis.x = 0;
		while (axis.x < mini_w)
		{
			if (axis.x == 0 || axis.x == mini_w - 1
				|| axis.y == 0 || axis.y == mini_h - 1)
				put_pxl_on_img(images, axis.x + push.x, axis.y + push.y, color);
			++axis.x;
		}
		++axis.y;
	}
}

void	render_map(char **map, t_ivec pos, t_img *images)
{
	int		x;
	int		y;

	mini_pos.x = pos.x / TILE + ((pos.x % TILE) / 4);
	mini_pos.y = pos.y / TILE + ((pos.y % TILE) / 4);
	y = 0;
	while (y < HEIGHT && map[y / TILE])
	{
		x = 0;
		while (x < WIDTH && map[y / TILE][x / TILE])
		{
			if (map[y / TILE][x / TILE] == '1')
				put_pxl_on_img(images, x, y, MAP_WALL_COLOR);
			++x;
		}
		++y;
	}
}

void	render_minimap(t_game *cub3d)
{
	render_map(cub3d->map, cub3d->ply.pos, &cub3d->images);
	render_player(&cub3d->images);
	render_border(&cub3d->images);
}
