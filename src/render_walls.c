/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_walls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 20:48:54 by fedeito           #+#    #+#             */
/*   Updated: 2025/02/05 21:50:58 by fedeito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "cub3d.h"

static double	del_fish_eye(double ray_dst, double ray_ang, double ply_ang)
{
	return (HEIGHT / (ray_dst * cos(ray_ang - ply_ang)) * TILE);
}

void	render_walls(t_game *cub3d)
{
	int		x;
	t_ray	ray;
	double	increment;
	t_wall	wall;

	ray.start = cub3d->ply.pos;
	ray.ang = cub3d->ply.ang - (deg_to_rad(FOV) / 2);
	increment = deg_to_rad(FOV) / WIDTH;
	x = -1;
	while (++x < WIDTH)
	{
		set_deltas(&ray.delta, ray.ang);
		dda(&ray, cub3d->map);
		wall.line_height = del_fish_eye(ray.dst, ray.ang, cub3d->ply.ang);
		wall.start = HEIGHT / 2 - (wall.line_height / 2);
		wall.end = wall.start + wall.line_height;
		if (wall.end > HEIGHT)
			wall.end = HEIGHT;
		draw_wall(cub3d, x, wall, ray);
		ray.ang += increment;
	}
}
