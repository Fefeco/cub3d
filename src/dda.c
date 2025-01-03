/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 14:46:36 by fcarranz          #+#    #+#             */
/*   Updated: 2025/01/03 11:44:03 by fedeito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void set_steps(t_ivec *step, t_dvec delta)
{
	if (delta.x < 0)
		step->x = -1;
	else
		step->x = 1;
	if (delta.y < 0)
		step->y = -1;
	else
		step->y = 1;
}

void	set_deltas(t_dvec *delta, double ang)
{
	delta->x = cos(ang);
	delta->y = sin(ang);
}

void	set_delta_dists(t_ray *ray)
{
	ray->delta_dist.x = fabs(TILE / ray->delta.x);
	ray->delta_dist.y = fabs(TILE / ray->delta.y);
}

t_ivec	get_map_coords(t_ray ray)
{
	t_ivec	map_pt;

	map_pt.x = ray.pos.x / TILE;
	map_pt.y = ray.pos.y / TILE;
	return (map_pt);
}

void	calc_next_cell_dist(t_ray *ray)
{
	if (ray->step.x > 0)
		ray->next_cell.x = (TILE - (ray->pos.x % TILE)) * ray->delta_dist.x; 
	else
		ray->next_cell.x = (ray->pos.x % TILE) * ray->delta_dist.x;
	if (ray->step.y > 0)
		ray->next_cell.y = (TILE - (ray->pos.y % TILE)) * ray->delta_dist.y; 
	else
		ray->next_cell.y = (ray->pos.y % TILE) * ray->delta_dist.y;
}

t_ivec	end_ray(t_ivec start_pt, double ang, char **map)
{
	t_ray	ray;
	t_ivec	map_pt;
	t_ivec	impact;
	double	short_dist;

	ray.pos = start_pt;
	set_deltas(&ray.delta, ang);
	set_steps(&ray.step, ray.delta);
	set_delta_dists(&ray);
	calc_next_cell_dist(&ray);
	map_pt = get_map_coords(ray);
	while (!check_wall(map_pt.x, map_pt.y, map))
	{
		if (ray.next_cell.x < ray.next_cell.y)
		{
			short_dist = ray.next_cell.x;
			ray.next_cell.x += ray.delta_dist.x;
			map_pt.x += ray.step.x;
		}
		else
		{
			short_dist = ray.next_cell.y;
			ray.next_cell.y += ray.delta_dist.y;
			map_pt.y += ray.step.y;
		}
	}
	return map_pt; 
}
