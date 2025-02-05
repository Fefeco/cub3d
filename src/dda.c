/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 14:46:36 by fcarranz          #+#    #+#             */
/*   Updated: 2025/02/05 21:54:34 by fcarranz         ###   ########.fr       */
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

t_ivec	get_map_coords(t_dvec ply_pos)
{
	t_ivec	map_pt;

	map_pt.x = floor(ply_pos.x);
	map_pt.y = floor(ply_pos.y);
	map_pt.x /= TILE;
	map_pt.y /= TILE;
	return (map_pt);
}

static double	get_first_dist(int step, double pos, double delta)
{
	double	first_dist;
	double	tile;

	tile = (double) TILE;
	if (step > 0)
		first_dist = (tile - fmod(pos, tile));
	else if (step < 0)
		first_dist = fmod(pos, tile);
	else
		first_dist = 0;
	if (delta != 0)
		first_dist /= fabs(delta);
	return (first_dist);
}

char	next_step_axis(t_dvec delta_dst, t_dvec tot_dst)
{
	if (!delta_dst.y || (delta_dst.x && tot_dst.x < tot_dst.y))
		return ('x');
	else
		return ('y');
}

void	dda(t_ray *ray, char **map)
{
	t_ivec	map_pos;
	t_dvec	dst;

	map_pos = get_map_coords(ray->start);
	set_step_directions(ray);
	set_delta_distances(&ray->delta_dst, ray->delta);
	dst.x = get_first_dist(ray->step.x, ray->start.x, fabs(ray->delta.x));
	dst.y = get_first_dist(ray->step.y, ray->start.y, fabs(ray->delta.y));
	ray->axis = '0';
	while (1)
	{
		ray->axis = next_step_axis(ray->delta_dst, dst);
		if (ray->axis == 'x')
		{
			map_pos.x += ray->step.x;
			dst.x += ray->delta_dst.x;
		}
		else
		{
			map_pos.y += ray->step.y;
			dst.y += ray->delta_dst.y;
		}
		if (check_wall(map_pos.x, map_pos.y, map))
			break ;
	}
	if (ray->axis == 'x')
		ray->dst = dst.x - ray->delta_dst.x;
	else
		ray->dst = dst.y - ray->delta_dst.y;
}
