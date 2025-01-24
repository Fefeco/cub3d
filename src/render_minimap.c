/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_minimap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedeito <fcarranz@student.42barcel>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 20:53:09 by fedeito           #+#    #+#             */
/*   Updated: 2025/01/24 20:15:34 by fedeito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>

/*void	render_border(t_img *images)
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
*/
void	render_map(char **map, t_img *images)
{
	t_ivec	mini;
	int		mini_tile;

	mini_tile = TILE / 4;
	mini.y = 0;
	while (mini.y < HEIGHT && map[mini.y / mini_tile])
	{
		mini.x = 0;
		while (map[mini.y / mini_tile][mini.x / mini_tile])
		{
			if (map[mini.y / mini_tile][mini.x / mini_tile] == '1')
				put_pxl_on_img(images, mini.x, mini.y, MAP_WALL_COLOR);
			++mini.x;
		}
		++mini.y;
	}
}
void	render_ray(t_ivec pos, double ang, char **map, t_img *images)
{
	t_dvec	delta;
	t_dvec	acc;
	int		mini_tile;

	mini_tile = TILE / 4;
	set_deltas(&delta, ang);
	acc.x = pos.x;
	acc.y = pos.y;
	while (map[(int)floor(acc.y) / mini_tile][(int)floor(acc.x) / mini_tile] != '1')
	{
		put_pxl_on_img(images, floor(acc.x), floor(acc.y), 0x00FF0000);
		acc.x += delta.x;
		acc.y += delta.y;
	}
}

void	render_player(t_img *images, t_player ply, char **map)
{
	t_ivec	pos;
	t_ivec	grow_dir;

	pos.x = ply.pos.x / 4;
	pos.y = ply.pos.y / 4;
	grow_dir.x = 1;
	if (map[pos.y][pos.x + grow_dir.x] == '1')
		grow_dir.x = -1;
	grow_dir.y = 1;
	if (map[pos.y + grow_dir.y][pos.x] == '1')
		grow_dir.y = -1;
	put_pxl_on_img(images, pos.x, pos.y, MAP_WALL_COLOR);
	put_pxl_on_img(images, pos.x + grow_dir.x, pos.y + grow_dir.y, MAP_WALL_COLOR);
	put_pxl_on_img(images, pos.x + grow_dir.x, pos.y, MAP_WALL_COLOR);
	put_pxl_on_img(images, pos.x, pos.y + grow_dir.y, MAP_WALL_COLOR);
	render_ray(pos, ply.ang, map, images);
}
void	render_minimap(t_game *cub3d)
{
	render_map(cub3d->map, &cub3d->images);
	render_player(&cub3d->images, cub3d->ply, cub3d->map);
	//render_border(&cub3d->images);
}
