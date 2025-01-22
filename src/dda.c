/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 14:46:36 by fcarranz          #+#    #+#             */
/*   Updated: 2025/01/22 23:13:16 by fedeito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void set_step_directions(t_ray *ray)
{
	if (ray->delta.x < 0)
		ray->step.x = -1;
	else if (ray->delta.x == 0)
		ray->step.x = 0;
	else
		ray->step.x = 1;
	if (ray->delta.y < 0)
		ray->step.y = -1;
	else if (ray->delta.y == 0)
		ray->step.y = 0;
	else
		ray->step.y = 1;
}

void	set_delta_distances(t_dvec *delta_dst, t_dvec delta)
{
	if (delta.x == 0)
		delta_dst->x = 0;
	else
		delta_dst->x = fabs(TILE / delta.x);
	if (delta.y == 0)
		delta_dst->y = 0;
	else
		delta_dst->y = fabs(TILE / delta.y);
}

t_ivec	get_map_coords(t_ivec ply_pos)
{
	t_ivec	map_pt;

	map_pt.x = ply_pos.x / TILE;
	map_pt.y = ply_pos.y / TILE;
	return (map_pt);
}

static double	get_first_dist(int	step, int pos, double delta)
{
	double	first_dist;

	if (step > 0)
		first_dist = (TILE - (pos % TILE));
	else if (step < 0)
		first_dist = (pos % TILE);
	else
		first_dist = 0;
	if (delta != 0)
		first_dist *= 1 / delta;
	return (first_dist);
}

char	next_step_axis(t_dvec delta_dst, t_dvec tot_dst)
{
	if (!delta_dst.y || (delta_dst.x && tot_dst.x < tot_dst.y))
		return ('x');
	else
		return ('y');
}

double	dda(t_ray ray, char **map)
{
	t_ivec	map_pos;
	char	next_axis;

	map_pos = get_map_coords(ray.start);
	set_step_directions(&ray);
	set_deltas(&ray.delta, ray.ang);
	set_delta_distances(&ray.delta_dst, ray.delta);
	ray.dst.x = get_first_dist(ray.step.x, ray.start.x, ray.delta.x);
	ray.dst.y = get_first_dist(ray.step.y, ray.start.y, ray.delta.y);
	next_axis = '0';
	while (1)
	{
		printf("delta.x: %f, delta.y: %f, step.x: %d, step.y: %d\n",
       ray.delta.x, ray.delta.y, ray.step.x, ray.step.y);
		next_axis = next_step_axis(ray.delta_dst, ray.dst);
		if (next_axis == 'x')
		{
			map_pos.x += ray.step.x;
			ray.dst.x += ray.delta_dst.x;
		}
		else
		{
			map_pos.y += ray.step.y;
			ray.dst.y += ray.delta_dst.y;
		}
		if (check_wall(map_pos.x, map_pos.y, map))
			break ;
	}
	if (next_axis == 'x')
		return (ray.dst.x - ray.delta_dst.x);
	else
		return (ray.dst.y - ray.delta_dst.y);
}
