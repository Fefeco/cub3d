/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 14:46:36 by fcarranz          #+#    #+#             */
/*   Updated: 2024/12/30 15:26:41 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_vec	get_next_cell(t_vec start_pt, t_vec step)
{

}

void set_steps(t_vec *step, double ang)
{
	double	dx;
	double	dy;

	dx = cos(ang);
	dy = sin(ang);
	if (dx < 0)
		step->x = -1;
	else
		step->x = 1;
	if (dy < 0)
		step->y = -1;
	else
		step->y = 1;
}

t_vec	end_ray(t_vec start_pt, double ang, char **map)
{
	t_vec	end_ray;
	t_vec	step;
	t_vec	map;

	set_steps(&step, ang);
	while (1)
	{
		end_ray = get_next_cell(start_pt, step);
		map.x = end_ray.x / TILE_SZ;
		map.y = end_ray.y / TILE_SZ;
		if (check_wall(map.x, map.y, map))
			break ;
		start_pt = end_ray;
	}
	return end_ray;
}
