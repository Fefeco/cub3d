/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedeito <fcarranz@student.42barcel>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 12:54:38 by fedeito           #+#    #+#             */
/*   Updated: 2025/01/13 11:01:54 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "cub3d.h"

void	draw_line(t_img *img, t_ivec curr_pos, int steps, double ang)
{
	t_dvec	delta;
	t_dvec	tmp;
	int		i;

	i = -1;
	tmp.x  = curr_pos.x;
	tmp.y  = curr_pos.y;
	set_deltas(&delta, ang);
	while (++i < steps)
	{
		tmp.x += delta.x;
		tmp.y += delta.y;
		put_pxl_on_img(img, floor(tmp.x), floor(tmp.y), 0x00AA0000);
	}
}

void	draw_ray(t_game *cub3d)
{
	double	current_ang;
	t_ivec	ply_pos;
	int		steps;
	int		i;

	ply_pos.x = cub3d->player.x;
	ply_pos.y = cub3d->player.y;
	i = (FOV / 2) * -1;
	while (i <= FOV / 2)
	{
		current_ang = cub3d->player.ang + deg_to_rad(i);
		steps = get_steps(ply_pos, current_ang, cub3d->map);  
		draw_line(&cub3d->images, ply_pos, steps, current_ang);
		++i;
//		if (i == -11)
//			break;
	}
}
