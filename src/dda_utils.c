/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 22:38:19 by fcarranz          #+#    #+#             */
/*   Updated: 2025/02/06 10:53:01 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_step_directions(t_ray *ray)
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
