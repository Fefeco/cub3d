/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 14:46:36 by fcarranz          #+#    #+#             */
/*   Updated: 2025/02/05 22:41:41 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

static void	update_pos_dist(int *pos, double *dst, int step, double dlt_dst)
{
	*pos += step;
	*dst += dlt_dst;
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
	while (!check_wall(map_pos.x, map_pos.y, map))
	{
		ray->axis = next_step_axis(ray->delta_dst, dst);
		if (ray->axis == 'x')
			update_pos_dist(&map_pos.x, &dst.x, ray->step.x, ray->delta_dst.x);
		else
			update_pos_dist(&map_pos.y, &dst.y, ray->step.y, ray->delta_dst.y);
	}
	if (ray->axis == 'x')
		ray->dst = dst.x - ray->delta_dst.x;
	else
		ray->dst = dst.y - ray->delta_dst.y;
}
