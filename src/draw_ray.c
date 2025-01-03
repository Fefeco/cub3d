/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedeito <fcarranz@student.42barcel>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 12:54:38 by fedeito           #+#    #+#             */
/*   Updated: 2025/01/03 20:09:42 by fedeito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "cub3d.h"

void	draw_line(t_img *img, t_ivec curr_pos, int steps, double ang)
{
	t_dvec	delta;
	int		i;

	i = -1;
	delta.x = cos(ang);
	delta.y = sin(ang);
	while (++i < steps)
	{
		curr_pos.x += delta.x;
		curr_pos.y += delta.y;
		put_pxl_on_img(img, floor(curr_pos.x), floor(curr_pos.y), 0x00aa0000);
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
	}
}
