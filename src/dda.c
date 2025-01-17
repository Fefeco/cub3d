/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 14:46:36 by fcarranz          #+#    #+#             */
/*   Updated: 2025/01/17 13:40:19 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void set_step_directions(t_ray *ray)
{
	if (ray->delta.x < 0)
		ray->step->x = -1;
	else if (ray->delta.x == 0)
		ray->step->x = 0;
	else
		ray->step->x = 1;
	if (ray->delta.y < 0)
		ray->step->y = -1;
	else if (ray->delta.y == 0)
		ray->step->y = 0;
	else
		ray->step->y = 1;
}

void	set_delta_dists(t_dvec *delta_dist, t_dvec delta)
{
	if (delta.x == 0)
		delta_dist->x = 0;
	else
		delta_dist->x = fabs(TILE / delta.x);
	if (delta.y == 0)
		delta_dist->y = 0;
	else
		delta_dist->y = fabs(TILE / delta.y);
}

t_ivec	get_map_coords(t_ivec ply_pos)
{
	t_ivec	map_pt;

	map_pt.x = ply_pos.x / TILE;
	map_pt.y = ply_pos.y / TILE;
	return (map_pt);
}

static t_dvec	get_first_dist(int	step, int pos, double delta)
{
	double	first_dist;

	if (step > 0)
		first_dist = (TILE - (pos % TILE));
	else if (step < 0)
		first_dist = (pos % TILE);
	if (step == 0)
		first_dist == 0;
	else
		first_dist *= 1 / delta;
	return (first_dist);
}

t_dvec	calc_first_dist(t_ray *ray)
{
	ray->tot_dist.x = get_first_dist(ray->step.x, ray->start.x, ray->delta.x);
	ray->tot_dist.y = get_first_dist(ray->step.y, ray->start.y, ray->delta.y);
}

double	get_ray_distance(t_ray ray, char **map)
{
	t_ivec	map_pos;
	char	flag;

	flag = '0';
	set_step_directions(&ray);
	set_delta_dists(&ray.delta_dist, ray.delta);
	map_pos = get_map_coords(ray.start);
	calc_first_dist(&ray);
	while (1)
	{
		if (!delta_dist.y || (delta_dist.x && travel_dist.x < travel_dist.y))
		{
			flag = 'x';
			map_pos.x += vec_dir.x;
		}
		else
		{
			flag = 'y';
			map_pos.y += vec_dir.y;
		}
		if (check_wall(map_pos.x, map_pos.y, map))
			break ;
		if (flag == 'x')
			travel_dist.x += delta_dist.x;
		else
			travel_dist.y += delta_dist.y;
	}
	return (calc_steps(travel_dist, delta)); 
}
