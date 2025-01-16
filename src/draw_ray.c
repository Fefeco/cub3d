/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedeito <fcarranz@student.42barcel>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 12:54:38 by fedeito           #+#    #+#             */
/*   Updated: 2025/01/16 16:51:20 by fedeito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "cub3d.h"

bool	hit(int x, int y, char **map)
{
	if (map[y / TILE][x / TILE] == '1')
		return (true);
	return (false);
}
/*
void	draw_line(t_img *img, t_ivec curr_pos, char **map, double ang)
{
	t_dvec	delta;
	t_dvec	tmp;
	int		i;

	i = -1;
	tmp.x  = curr_pos.x;
	tmp.y  = curr_pos.y;
	set_deltas(&delta, ang);
}
*/
void	draw_ray(t_game *cub3d)
{
	t_dvec	tmp;
	t_dvec	delta;
	double	i;
	double	current_ang;
	double	stop;

	stop = deg_to_rad(FOV / 2);
	i = stop * -1;
	while (i < stop)
	{
		current_ang = cub3d->player.ang + i;
		set_deltas(&delta, current_ang);
		tmp.x = cub3d->player.x;
		tmp.y = cub3d->player.y;
		while (!hit(floor(tmp.x), floor(tmp.y), cub3d->map))
		{
			put_pxl_on_img(&cub3d->images, floor(tmp.x), floor(tmp.y), 0x00FFDE21);
			tmp.x += delta.x;
			tmp.y += delta.y;
		}
		i += 0.001;
	}
}
