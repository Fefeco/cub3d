/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedeito <fcarranz@student.42barcel>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 12:54:38 by fedeito           #+#    #+#             */
/*   Updated: 2025/01/17 13:54:52 by fcarranz         ###   ########.fr       */
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
	t_dvec	tmp;
	double	i;
	double	stop;
	double	ray_dist;

	ray.start.x = cub3d->player.x;
	ray.start.y = cub3d->player.y;
	stop = deg_to_rad(FOV / 2);
	i = stop * -1;
	while (i < stop)
	{
		ray.ang = cub3d->player.ang + i;
		set_deltas(&ray.delta, ray.ang);
		tmp.x = cub3d->player.x;
		tmp.y = cub3d->player.y;
		//while (!hit(floor(tmp.x), floor(tmp.y), cub3d->map))
		//{
		//	tmp.x += ray.delta.x;
		//	tmp.y += ray.delta.y;
		//}
		ray_dist = get_ray_distance(ray, cub3d->map);
		put_pxl_on_img(&cub3d->images, floor(tmp.x), floor(tmp.y), 0x00FFDE21);
		i += 0.001;
	}
}
