/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedeito <fcarranz@student.42barcel>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 12:54:38 by fedeito           #+#    #+#             */
/*   Updated: 2025/01/16 20:34:25 by fedeito          ###   ########.fr       */
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

void	draw_ray(t_game *cub3d)
{
	t_ray	ray;
	double	i;
	double	stop;

	stop = deg_to_rad(FOV / 2);
	i = stop * -1;
	while (i < stop)
	{
		ray.ang = cub3d->player.ang + i;
		set_deltas(&ray.delta, ray.ang);
		ray.tot_dist.x = cub3d->player.x;
		ray.tot_dist.y = cub3d->player.y;
		while (!hit(floor(ray.tot_dist.x), floor(ray.tot_dist.y), cub3d->map))
		{
			ray.tot_dist.x += ray.delta.x;
			ray.tot_dist.y += ray.delta.y;
		}
		ray.tot_dist.x -= ray.delta.x;
		ray.tot_dist.y -= ray.delta.y;
		put_pxl_on_img(&cub3d->images, floor(ray.tot_dist.x), floor(ray.tot_dist.y), 0x00FFDE21);
		i += 0.001;
	}
}
