/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 14:46:36 by fcarranz          #+#    #+#             */
/*   Updated: 2025/01/02 16:09:34 by fedeito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_vec	get_next_cell(t_vec start_pt, t_vec step)
{

}

void set_steps(t_vec *step, t_dvec delta)
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

void	get_delta_dists(t_dvec *delta_dist, t_ivec start_pt, t_dvec delta)
{
	delta_dist->x = fabs(TILE_SZ / delta.x);
	delta_dist->y = fabs(TILE_SZ / delta.y);
}

t_vec	end_ray(t_vec start_pt, double ang, char **map)
{
	t_ray	ray;
	t_ivec	end_ray;
	t_ivec	step;
	t_ivec	map_pt;
	t_dvec	delta;
	t_dvec	delta_dist;

	set_deltas(&delta, ang);
	set_steps(&step, delta);
	get_delta_dists(&delta_dist, start_pt, delta);
	get_first_distance(&delta_dist, delta, start_pt);
	delta_dist.x *= TILE_SZ - (start_pt.x % TILE_SZ); 
	delta_dist.y *= TILE_SZ - (start_pt.y % TILE_SZ); 
	while (1)
	{
		end_ray = get_next_cell(start_pt, step);
		map_pt.x = end_ray.x / TILE_SZ;
		map_pt.y = end_ray.y / TILE_SZ;
		if (check_wall(map_pt.x, map_pt.y, map))
			break ;
		start_pt = end_ray;
	}
	return end_ray;
}
